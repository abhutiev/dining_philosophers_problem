#include "philosophers.h"

int	philo_eat(t_philo *philo)
{

}

int	philo_sleep(t_philo *philo)
{

}

int	philo_thinking(t_philo *philo)
{

}

void	*memento_mori(t_philo *philo)
{
	while (1)
	{
		if (timestamp() > philo->time_to_die && !philo->consuming)
		{
			pthread_mutex_lock(&philo->output);
			printf("%llu Philosopher %zu died\n", timestamp(), philo->index + 1);
			pthread_mutex_unlock(&philo->output);
			return (NULL);
			//pthread_mutex_unlock()
		}
	}
}

void	philo_took_left_fork(t_philo *philo)
{
	pthread_mutex_lock(&philo->output);
	printf("%llu Philosopher %zu has taken a left fork\n", timestamp(), philo->index + 1);
	pthread_mutex_unlock(&philo->output);
}

void	philo_took_right_fork(t_philo *philo)
{
	pthread_mutex_lock(&philo->output);
	printf("%llu Philosopher %zu has taken a right fork\n", timestamp(), philo->index + 1);
	pthread_mutex_unlock(&philo->output);
}

void	philo_takes_forks(t_philo *philo)
{
	pthread_mutex_lock((&philo->fork[philo->left_fork_index]));
	pthread_mutex_lock(&philo->output);
	printf("%llu Philosopher %zu has taken a left fork\n", timestamp(), philo->index + 1);
	pthread_mutex_unlock(&philo->output);
	pthread_mutex_lock(&(philo->fork[philo->right_fork_index]));
	pthread_mutex_lock(&philo->output);
	printf("%llu Philosopher %zu has taken a right fork\n", timestamp(), philo->index + 1);
	pthread_mutex_unlock(&philo->output);
	philo->consuming = 1;
}

void	philo_drops_forks(t_philo *philo)
{
	pthread_mutex_unlock((&philo->fork[philo->left_fork_index]));
	pthread_mutex_lock(&philo->output);
	printf("%llu Philosopher %zu has dropped a left fork\n", timestamp(), philo->index + 1);
	pthread_mutex_unlock(&philo->output);
	pthread_mutex_unlock(&(philo->fork[philo->right_fork_index]));
	pthread_mutex_lock(&philo->output);
	printf("%llu Philosopher %zu has dropped a right fork\n", timestamp(), philo->index + 1);
	pthread_mutex_unlock(&philo->output);
	philo->consuming = 1;
}

void	*philo_hussle(t_philo *philo)
{
	pthread_t	thread_of_death;

	philo->time_to_die = time_to_die_in_ms(philo->input);
//	if (pthread_create(&thread_of_death, NULL, (void *)&memento_mori, philo))
//		return (NULL);
//	pthread_detach(thread_of_death);
//	philo->left_fork_index = &philo->fork[philo->index];
//	philo->right_fork_index = &philo->fork[philo->index == 0 ? philo->input.number_of_philosophers - 1 : philo->index];
	while (1)
	{
		philo_takes_forks(philo);
		philo_eat(philo);
		philo_drops_forks(philo);
		philo_sleep(philo);
		philo_thinking(philo);
	}
	return NULL;
}

int	create_philo(t_data *data)
{
	size_t	i;

	i = 0;
	data->philo = (t_philo *)malloc(data->input.number_of_philosophers * sizeof(t_philo));
	if (!data->philo)
	{
		write(2, "Something wrong with memory allocation\n", 39);
		return (1);
	}
	while (i < (size_t)data->input.number_of_philosophers)
	{
		data->philo[i].fork = data->fork;
		data->philo[i].left_fork_index = i;
		data->philo[i].right_fork_index = (i == 0 ? data->input.number_of_philosophers - 1 : i - 1);
		data->philo[i].input = data->input;
		data->philo[i].index = i;
		if (pthread_create(&data->philo[i].thread, NULL, (void *)&philo_hussle, &data->philo[i]))
		{
			write(2, "Something wrong inside philo thread\n", 40);
			return (1);
		}
		pthread_detach(data->philo[i].thread);
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_data			data;

	if (get_and_validate_input_data(argc, argv, &data.input))
		return (1);
	if (create_mutexes(&data))
		return (1);
	if (create_philo(&data))
		return (1);
	while (1);
	return (0);
}
