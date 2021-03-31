#include "philosophers.h"

void	print_death_message(t_philo *philo)
{
	char *string;

	string = ft_ulltoa(get_current_time() - *philo->start_of_simulation);
	write(1, string, ft_strlen(string));
	sem_wait(philo->semaphores->print);
	write(1, " Philosopher ", 13);
	string = ft_ulltoa((time_ms)philo->index);
	write(1, string, ft_strlen(string));
	write(1, " died\n", 6);
	sem_post(philo->semaphores->stop);
}

void	print_take_fork_message(t_philo *philo, int flag)
{
	char *string;

	string = ft_ulltoa(get_current_time() - *philo->start_of_simulation);
	write(1, string, ft_strlen(string));
	sem_wait(philo->semaphores->print);
	write(1, " Philosopher ", 13);
	string = ft_ulltoa((time_ms)philo->index);
	write(1, string, ft_strlen(string));
	if (flag == RIGHT_FORK)
		write(1, " has taken a right fork\n", 24);
	else if (flag == LEFT_FORK)
		write(1, " has taken a left fork\n", 23);
	sem_post(philo->semaphores->print);
}

void	print_eating_message(t_philo *philo)
{
	char *string;

	string = ft_ulltoa(get_current_time() - *philo->start_of_simulation);
	write(1, string, ft_strlen(string));
	sem_wait(philo->semaphores->print);
	write(1, " Philosopher ", 13);
	string = ft_ulltoa((time_ms)philo->index);
	write(1, string, ft_strlen(string));
	write(1, " eating\n", 8);
	sem_post(philo->semaphores->print);
}

void	print_sleeping_message(t_philo *philo)
{
	char *string;

	string = ft_ulltoa(get_current_time() - *philo->start_of_simulation);
	write(1, string, ft_strlen(string));
	sem_wait(philo->semaphores->print);
	write(1, " Philosopher ", 13);
	string = ft_ulltoa((time_ms)philo->index);
	write(1, string, ft_strlen(string));
	write(1, " sleeping\n", 10);
	sem_post(philo->semaphores->print);
}

void	print_thinking_message(t_philo *philo)
{
	char *string;

	string = ft_ulltoa(get_current_time() - *philo->start_of_simulation);
	write(1, string, ft_strlen(string));
	sem_wait(philo->semaphores->print);
	write(1, " Philosopher ", 13);
	string = ft_ulltoa((time_ms)philo->index);
	write(1, string, ft_strlen(string));
	write(1, " thinking\n", 10);
	sem_post(philo->semaphores->print);
}