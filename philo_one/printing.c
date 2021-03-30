#include "philosophers.h"

void	print_death_meassage(t_philo *philo)
{
	char *string;

	string = ft_ulltoa(get_current_time() - *philo->start_of_simulation);
	pthread_mutex_lock(philo->mutex->print);
	write(1, string, ft_strlen(string));
	write(1, " Philosopher ", 13);
	string = ft_ulltoa((time_ms)philo->index);
	write(1, string, ft_strlen(string));
	write(1, " died\n", 6);
	pthread_mutex_unlock(philo->mutex->stop);
}

void	print_take_fork_message(t_philo *philo, int flag)
{
	char *string;

	string = ft_ulltoa(get_current_time() - *philo->start_of_simulation);
	pthread_mutex_lock(philo->mutex->print);
	write(1, string, ft_strlen(string));
	write(1, " Philosopher ", 13);
	string = ft_ulltoa((time_ms)philo->index);
	write(1, string, ft_strlen(string));
	if (flag == RIGHT_FORK)
		write(1, " has taken a right fork\n", 24);
	else if (flag == LEFT_FORK)
		write(1, " has taken a left fork\n", 23);
	pthread_mutex_unlock(philo->mutex->print);
}

void	print_eating_message(t_philo *philo)
{
	char *string;

	string = ft_ulltoa(get_current_time() - *philo->start_of_simulation);
	pthread_mutex_lock(philo->mutex->print);
	write(1, string, ft_strlen(string));
	write(1, " Philosopher ", 13);
	string = ft_ulltoa((time_ms)philo->index);
	write(1, string, ft_strlen(string));
	write(1, " eating\n", 8);
	pthread_mutex_unlock(philo->mutex->print);
}

void	print_sleeping_message(t_philo *philo)
{
	char *string;

	string = ft_ulltoa(get_current_time() - *philo->start_of_simulation);
	pthread_mutex_lock(philo->mutex->print);
	write(1, string, ft_strlen(string));
	write(1, " Philosopher ", 13);
	string = ft_ulltoa((time_ms)philo->index);
	write(1, string, ft_strlen(string));
	write(1, " sleeping\n", 10);
	pthread_mutex_unlock(philo->mutex->print);
}

void	print_thinking_message(t_philo *philo)
{
	char *string;

	string = ft_ulltoa(get_current_time() - *philo->start_of_simulation);
	pthread_mutex_lock(philo->mutex->print);
	write(1, string, ft_strlen(string));
	write(1, " Philosopher ", 13);
	string = ft_ulltoa((time_ms)philo->index);
	write(1, string, ft_strlen(string));
	write(1, " thinking\n", 10);
	pthread_mutex_unlock(philo->mutex->print);
}