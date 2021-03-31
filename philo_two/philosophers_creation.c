#include "philosophers.h"

static void	philosopher_backpack(t_data *data, t_philo *philo, int i)
{
	philo->semaphores = data->semaphores;
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

int	create_philosophers(t_data *data)
{
	t_philo	*philo;

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
	return (0);
}