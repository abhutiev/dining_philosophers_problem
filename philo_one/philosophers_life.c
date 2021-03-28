#include "philosophers.h"

void	philo_takes_forks(t_philo *philo)
{
	if (philo->index % 2)
	{
		pthread_mutex_lock(&philo->mutex->fork[philo->index_left_fork]);
		pthread_mutex_lock(philo->mutex->print);
		printf("%llu Philosopher %d has taken a left fork\n", get_current_time() - *philo->start_of_simulation, philo->index + 1);
		pthread_mutex_unlock(philo->mutex->print);
	}
	pthread_mutex_lock(&philo->mutex->fork[philo->index_right_fork]);
	pthread_mutex_lock(philo->mutex->print);
	printf("%llu Philosopher %d has taken a right fork\n", get_current_time() - *philo->start_of_simulation, philo->index + 1);
	pthread_mutex_unlock(philo->mutex->print);
	if (!philo->index % 2)
	{
		pthread_mutex_lock(&philo->mutex->fork[philo->index_left_fork]);
		pthread_mutex_lock(philo->mutex->print);
		printf("%llu Philosopher %d has taken a left fork\n", get_current_time() - *philo->start_of_simulation, philo->index + 1);
		pthread_mutex_unlock(philo->mutex->print);
	}
}

void	philo_eats(t_philo *philo)
{
	philo_takes_forks(philo);
	pthread_mutex_lock(philo->mutex->print);
	printf("%llu Philosopher %d eating\n", get_current_time() - *philo->start_of_simulation, philo->index + 1);
	pthread_mutex_unlock(philo->mutex->print);
	usleep(philo->info.time_to_eat * 1000);
	pthread_mutex_unlock(&philo->mutex->fork[philo->index_left_fork]);
	pthread_mutex_unlock(&philo->mutex->fork[philo->index_right_fork]);
	set_time_of_death(philo);
}

void	philo_sleeps(t_philo *philo)
{
	pthread_mutex_lock(philo->mutex->print);
	printf("%llu Philosopher %d sleeping\n", get_current_time() - *philo->start_of_simulation, philo->index + 1);
	pthread_mutex_unlock(philo->mutex->print);
	usleep(philo->info.time_to_sleep * 1000);
}

void	philo_thinks(t_philo *philo)
{
	pthread_mutex_lock(philo->mutex->print);
	printf("%llu Philosopher %d thinking\n", get_current_time() - *philo->start_of_simulation, philo->index + 1);
	pthread_mutex_unlock(philo->mutex->print);
}

void	*memento_mori(t_philo *philo)
{
	while (1)
	{
		if (get_current_time() > philo->time_of_death)
		{
			pthread_mutex_lock(philo->mutex->print);
			printf("%llu Philosopher %d died\n", get_current_time() - *philo->start_of_simulation, philo->index + 1);
			pthread_mutex_unlock(philo->mutex->stop);
			return (NULL);
		}
		usleep(1);
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
		philo_thinks(philo);
	}
}