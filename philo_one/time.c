#include "philosophers.h"

time_ms	get_current_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time_ms)(time.tv_sec * 1000 + time.tv_usec / 1000));
}

void	set_start_time(t_data *data)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	*(data->start_of_simulation) = ((time_ms)(time.tv_sec * 1000 + time.tv_usec / 1000));
}

void	set_first_time_of_death(t_philo *philo)
{
	philo->time_of_death = *(philo->start_of_simulation) + philo->info.time_to_die;
}

void	set_time_of_death(t_philo *philo)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	philo->time_of_death = (time_ms)(time.tv_sec * 1000 + time.tv_usec / 1000) + philo->info.time_to_die + philo->info.time_to_sleep;
}

void	better_usleep(time_ms time_to_sleep)
{
	time_ms	stop;

	stop = get_current_time() + time_to_sleep;
	while (get_current_time() < stop)
		usleep (1);
}
