#include "philosophers.h"

static void	philo_takes_forks(t_philo *philo)
{
	sem_wait(philo->semaphores->waiter);
	sem_wait(philo->semaphores->fork);
	sem_wait(philo->semaphores->fork);
	sem_post(philo->semaphores->waiter);
	print_take_fork_message(philo, RIGHT_FORK);
	print_take_fork_message(philo, LEFT_FORK);
}

static void	philo_eats(t_philo *philo)
{
	philo_takes_forks(philo);
	print_eating_message(philo);
	set_time_of_death(philo);
	better_usleep(philo->info.time_to_eat);
	sem_post(philo->semaphores->fork);
	sem_post(philo->semaphores->fork);
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
			print_death_message(philo);
			return (NULL);
		}
		better_usleep(1);
	}
}

void	*philo_hussle(t_philo *philo)
{
	pthread_t	death;

	sem_wait(philo->semaphores->etiquette);
	sem_post(philo->semaphores->etiquette);
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

static void	philosopher_backpack(t_data *data, t_philo *philo, int i)
{
	philo->semaphores = data->semaphores;
	philo->index = i;
	philo->info = data->input;
	philo->start_of_simulation = data->start_of_simulation;
	philo->number_of_dinners = 0;
}

int launch_processes(t_data *data)
{
	set_start_time(data);
	data->philo = (t_philo *)malloc(sizeof(t_philo) * data->input.number_of_philosophers);
	for (int i = 0; i < data->input.number_of_philosophers; i++)
	{
		philosopher_backpack(data, &data->philo[i], i);
		data->philo[i].pid = fork();
		if (data->philo[i].pid == 0)
		{
			philo_hussle(&data->philo[i]);
		}
	}
	sem_post(data->semaphores->etiquette);
	return (0);
}

void kill_all_philosophers(t_data *data)
{
//	while(1){}
	for (int i = 0; i < data->input.number_of_philosophers; i++)
	{
		kill(data->philo[i].pid, SIGKILL);
	}
	while (1){}
}

int main(int argc, char **argv)
{
	t_data data;

	if (get_input(argc, argv, &data.input))
		return (1);
	if (create_semaphores(&data))
		return (1);
	sem_wait(data.semaphores->etiquette);
	sem_wait(data.semaphores->stop);
	if (launch_processes(&data))
		return (1);
	sem_wait(data.semaphores->stop);
	kill_all_philosophers(&data);
	return(0);
}
