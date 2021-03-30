#include "philosophers.h"

static void	philo_takes_forks(t_philo *philo)
{
	if (philo->index % 2 == 0)
	{
		pthread_mutex_lock(philo->mutex->fork[philo->index_left_fork]);
		pthread_mutex_lock(philo->mutex->fork[philo->index_right_fork]);
		print_take_fork_message(philo, LEFT_FORK);
	}
	print_take_fork_message(philo, RIGHT_FORK);
	if (philo->index % 2 == 1)
	{
		pthread_mutex_lock(philo->mutex->fork[philo->index_right_fork]);
		pthread_mutex_lock(philo->mutex->fork[philo->index_left_fork]);
		print_take_fork_message(philo, LEFT_FORK);
	}
}

static void	philo_eats(t_philo *philo)
{
	philo_takes_forks(philo);
	print_eating_message(philo);
	set_time_of_death(philo);
	better_usleep(philo->info.time_to_eat);
	philo->number_of_dinners[philo->index]++;
	pthread_mutex_unlock(philo->mutex->fork[philo->index_left_fork]);
	pthread_mutex_unlock(philo->mutex->fork[philo->index_right_fork]);
}

static void	philo_sleeps(t_philo *philo)
{
	print_sleeping_message(philo);
	better_usleep(philo->info.time_to_sleep);
}

static void	*memento_mori(t_philo *philo)
{
	time_ms time;
	while (1)
	{
		time = get_current_time();
		if (time > philo->time_of_death)
		{
			print_death_meassage(philo);
			return (NULL);
		}
		better_usleep(100);
	}
}

void	*philo_hussle(t_philo *philo)
{
	pthread_t	death;
	pthread_mutex_lock(philo->mutex->etiquette);
	pthread_mutex_unlock(philo->mutex->etiquette);
	set_first_time_of_death(philo);
	if (pthread_create(&death, NULL, (void *)&memento_mori, philo))
		return (NULL);
	pthread_detach(death);
	while (1)
	{
		philo_eats(philo);
		philo_sleeps(philo);
		print_thinking_message(philo);
	}
}