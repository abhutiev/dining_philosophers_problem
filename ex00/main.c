#include "philosophers.h"

int	create_philo(t_data *data)
{
	size_t	i;

	i = 0;
	data->philo = (t_philo *)malloc(data->input_data.number_of_philosophers * sizeof(t_philo));
	if (!data->philo)
	{
		write(2, "Something wrong with memory allocation\n", 39);
		return (1);
	}
	while (i < (size_t)data->input_data.number_of_philosophers)
	{
		if (pthread_create(&data->philo[i].thread, NULL, ))
		{
			write(2, "Something wrong with thread creation\n", 37);
			return (1);
		}
		i++;
	}
	return (0);
}

int	create_forks(t_data *data)
{
	size_t	i;

	data->fork = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * data->input_data.number_of_philosophers);
	if (!data->fork)
	{
		write(2, "Something wrong with memory allocation\n", 39);
		return (1);
	}
	i = 0;
	while (i < (size_t)data->input_data.number_of_philosophers)
	{
		if (pthread_mutex_init(&data->fork[i], NULL))
		{
			write(2, "Something wrong with mutex creation\n", 36);
			return (1);
		}
		i++;
	}
	if (pthread_mutex_init(&data->output, NULL))
	{
		write(2, "Something wrong with mutex creation\n", 36);
		return (1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_data			data;

	if (get_and_validate_input_data(argc, argv, &data.input_data))
		return (1);
	if (create_forks(&data))
		return (1);
	if (create_philo(&data))
		return (1);
	return (0);
}
