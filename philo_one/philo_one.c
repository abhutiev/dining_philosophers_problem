#include "philosophers.h"

void	philosopher_backpack(t_data *data, t_philo *philo, int i)
{
	philo->mutex = data->mutex;
	philo->index = i;
	philo->info = data->input;
	philo->start_of_simulation = data->start_of_simulation;
	philo->number_of_dinners = data->number_of_dinners;
	philo->number_of_dinners[i] = 0;
	philo->index_left_fork = i;
	if (i == 0)
		philo->index_right_fork = data->input.number_of_philosophers - 1;
	else
		philo->index_right_fork = i - 1;
}

void	*satiety(t_data *data)
{
	int	i;

	pthread_mutex_lock(data->mutex->etiquette);
	pthread_mutex_unlock(data->mutex->etiquette);
	while (1)
	{
		for (i = 0; i < data->input.number_of_philosophers; i++) {
			if (data->number_of_dinners[i] < data->input.number_of_times_each_philo_must_eat)
				break;
		}
		if (i == data->input.number_of_philosophers)
			break;
	}
	pthread_mutex_lock(data->mutex->print);
	printf("%llu Philosophers fed up", get_current_time() - *data->start_of_simulation);
	pthread_mutex_unlock(data->mutex->stop);
	return (NULL);
}

int	create_philosophers(t_data *data)
{
	t_philo	*philo;
	pthread_t gluttony;

	philo = (t_philo *)malloc(data->input.number_of_philosophers * sizeof(t_philo));
	if (!philo)
	{
		write(2, "Something wrong with memory allocation\n", 39);
		return (1);
	}
	data->number_of_dinners = (int *)malloc(sizeof(int) * data->input.number_of_philosophers);
	for (int i = 0; i < data->input.number_of_philosophers; i++)
	{
		philosopher_backpack(data, &philo[i], i);
		if (pthread_create(&philo[i].thread, NULL, (void *)&philo_hussle, &philo[i]))
		{
			write(2, "Something wrong with thread creation\n", 40);
			return (1);
		}
		pthread_detach(philo[i].thread);
	}
	set_start_time(data);
	if (data->input.number_of_times_each_philo_must_eat)
	{
		if (pthread_create(&gluttony, NULL, (void *)&satiety, data))
		{
			write(2, "Something wrong with thread creation\n", 40);
			return (1);
		}
		pthread_detach(gluttony);
	}
	pthread_mutex_unlock(data->mutex->etiquette); // when all philosophers are created we can destroy this mutex. Philos can start eating
	return (0);
}

int	main(int argc, char **argv)
{
	t_data data;

	if (get_input(argc, argv, &data.input))
		return (0);
	if (create_mutexes(&data))
		return (0);
	data.start_of_simulation = (time_ms *)malloc(sizeof(time_ms));
	pthread_mutex_lock(data.mutex->etiquette); // locking mutex, which not allowing philosophers start eating while all philosophers are not created
	pthread_mutex_lock(data.mutex->stop);
	if (create_philosophers(&data))
		return (0);
	pthread_mutex_lock(data.mutex->stop); // this mutex will unlock when philosopher dies or when all philosophers ate enough times;
	return (0);
}
