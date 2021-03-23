#include "philosophers.h"

int	philo_eat(t_data *data)
{

}

int	philo_sleep(t_data *data)
{

}

int	philo_thinking(t_data *data)
{

}

void	*philo_hussle(t_data *data)
{
	data->philo->time_to_die = time_to_die_in_ms(data);
	philo_eat(data);
	philo_sleep(data);
	philo_thinking(data);
	return (NULL);
}

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
		if (pthread_create(&data->philo[i].thread, NULL, philo_hussle(data), data))
		{
			write(2, "Something wrong with thread creation\n", 37);
			return (1);
		}
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_data			data;

	if (get_and_validate_input_data(argc, argv, &data.input_data))
		return (1);
	if (create_mutexes(&data))
		return (1);
	if (create_philo(&data))
		return (1);
	return (0);
}
