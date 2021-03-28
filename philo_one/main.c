#include "philosophers.h"

void	usleep_real(time_ms time_to_sleep)
{
	const time_ms start = timestamp();

	while (timestamp() < start + time_to_sleep)
		usleep(1);
}

void	philo_sleep(t_philo *philo)
{
	pthread_mutex_lock(&philo->output);
	printf("%llu Philosopher %zu sleeping\n", timestamp() - philo->input.time_of_start, philo->index + 1);
	pthread_mutex_unlock(&philo->output);
	usleep_real(philo->input.time_to_sleep);
}

void	philo_thinking(t_philo *philo)
{
	pthread_mutex_lock(&philo->output);
	printf("%llu Philosopher %zu thinking\n", timestamp() - philo->input.time_of_start, philo->index + 1);
	pthread_mutex_unlock(&philo->output);
}

void	*memento_mori(t_philo *philo)
{
	while (1)
	{
		if (timestamp() > philo->time_to_die && !philo->consuming)
		{
			pthread_mutex_lock(&philo->output);
			printf("%llu Philosopher %zu died\n", timestamp() - philo->input.time_of_start, philo->index + 1);
			pthread_mutex_unlock(&philo->output);
			return (NULL);
		}
	}
}

void	philo_takes_forks(t_philo *philo)
{
	if (philo->index % 2)
	{
		pthread_mutex_lock((&philo->fork[philo->left_fork_index]));
		pthread_mutex_lock(&philo->output);
		printf("%llu Philosopher %zu has taken a left fork\n", timestamp() - philo->input.time_of_start, philo->index + 1);
		pthread_mutex_unlock(&philo->output);
	}
	pthread_mutex_lock(&(philo->fork[philo->right_fork_index]));
	pthread_mutex_lock(&philo->output);
	printf("%llu Philosopher %zu has taken a right fork\n", timestamp() - philo->input.time_of_start, philo->index + 1);
	pthread_mutex_unlock(&philo->output);
	if (!(philo->index % 2))
	{
		pthread_mutex_lock((&philo->fork[philo->left_fork_index]));
		pthread_mutex_lock(&philo->output);
		printf("%llu Philosopher %zu has taken a left fork\n", timestamp() - philo->input.time_of_start, philo->index + 1);
		pthread_mutex_unlock(&philo->output);
	}
	pthread_mutex_lock(&philo->output);
	printf("%llu Philosopher %zu eating\n", timestamp() - philo->input.time_of_start, philo->index + 1);
	pthread_mutex_unlock(&philo->output);
	philo->consuming = 1;
}

void	philo_drops_forks(t_philo *philo)
{
	pthread_mutex_unlock((&philo->fork[philo->left_fork_index]));
	pthread_mutex_unlock(&(philo->fork[philo->right_fork_index]));
	philo->time_to_die = timestamp() + philo->input.time_to_die;
	philo->consuming = 0;
}

void	philo_eat(t_philo *philo)
{
	philo_takes_forks(philo);
	usleep_real(philo->input.time_to_eat);
	philo_drops_forks(philo);
}

void	*philo_hussle(t_philo *philo)
{
	pthread_t	thread_of_death;

	philo->time_to_die = time_to_die_in_ms(philo->input);
	if (pthread_create(&thread_of_death, NULL, (void *)&memento_mori, philo))
		return (NULL);
	pthread_detach(thread_of_death);
	while (1)
	{
		philo_eat(philo);
		philo_sleep(philo);
		philo_thinking(philo);
	}
}

int	create_philo(t_data *data)
{
	size_t	i;

	i = 0;
	data->philo = (t_philo *)malloc(data->info.number_of_philosophers * sizeof(t_philo));
	if (!data->philo)
	{
		write(2, "Something wrong with memory allocation\n", 39);
		return (1);
	}
	while (i < (size_t)data->info.number_of_philosophers)
	{
		data->philo[i].fork = data->fork;
		data->philo[i].left_fork_index = i;
		data->philo[i].right_fork_index = (i == 0 ? data->info.number_of_philosophers - 1 : i - 1);
		data->philo[i].input = data->info;
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

	if (get_and_validate_input_data(argc, argv, &data.info))
		return (1);
	data.info.time_of_start = timestamp();
	if (create_mutexes(&data))
		return (1);
	if (create_philo(&data))
		return (1);
	while (1);
	return (0);
}
