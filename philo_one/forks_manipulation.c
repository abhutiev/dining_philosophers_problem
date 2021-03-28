#include "philosophers.h"

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

