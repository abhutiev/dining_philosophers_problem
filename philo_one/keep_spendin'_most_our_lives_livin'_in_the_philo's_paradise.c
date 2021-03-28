#include "philosophers.h"

static void	philo_eat(t_philo *philo)
{
	philo_takes_forks(philo);
	almost_real_usleep(philo->input.time_to_eat);
	philo_drops_forks(philo);
}

static void	philo_sleep(t_philo *philo)
{
	pthread_mutex_lock(&philo->output);
	printf("%llu Philosopher %zu sleeping\n", timestamp() - philo->input.time_of_start, philo->index + 1);
	pthread_mutex_unlock(&philo->output);
	almost_real_usleep(philo->input.time_to_sleep);
}

static void	philo_thinking(t_philo *philo)
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
			pthread_mutex_unlock(&(*philo->death));
			usleep(2);
			return (NULL);
		}
	}
}

void	*philo_hussle(t_philo *philo)
{
	pthread_t	thread_of_death;

	philo->time_to_die = time_to_die_in_ms(philo->input);
	if (pthread_create(&thread_of_death, NULL, (void *)&memento_mori, philo))
		return (NULL);
//	pthread_detach(thread_of_death);
	while (1)
	{
		philo_eat(philo);
		philo_sleep(philo);
		philo_thinking(philo);
	}
}