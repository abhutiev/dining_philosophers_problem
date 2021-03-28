#include "philosophers.h"

static int create_forks_mutex(t_data *data)
{
	size_t	i;

	i = 0;
	data->fork = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * data->info.number_of_philosophers);
	if (!data->fork)
	{
		write(2, "Something wrong with memory allocation\n", 39);
		return (1);
	}
	while (i < (size_t)data->info.number_of_philosophers)
	{
		if (pthread_mutex_init(&data->fork[i], NULL))
		{
			write(2, "Something wrong with mutex creation\n", 36);
			return (1);
		}
		i++;
	}
	return (0);
}

static int	create_output_mutex(t_data *data)
{
	if (pthread_mutex_init(&data->output, NULL))
	{
		write(2, "Something wrong with mutex creation\n", 36);
		return (1);
	}
	return (0);
}

static int	create_death_mutex(t_data *data)
{
	if (pthread_mutex_init(&data->death, NULL))
	{
		write(2, "Something wrong with mutex creation\n", 36);
		return (1);
	}
	return (0);
}

int	create_mutexes(t_data *data)
{
	if (create_forks_mutex(data))
		return (1);
	if (create_output_mutex(data))
		return (1);
	if (create_death_mutex(data))
		return (1);
	return (0);
}