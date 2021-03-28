#include "philosophers.h"

int	create_philo(t_data *data)
{
	size_t	i;

	i = 0;
	data->philo = (t_philo *)malloc(data->info.number_of_philosophers * sizeof(t_philo));
	if (!data->philo)
	{
		write(2, "Something wrong with memory allocation\n", 39);
		return (1);
	}
	while (i < (size_t)data->info.number_of_philosophers)
	{
		data->philo[i].fork = data->fork;
		data->philo[i].left_fork_index = i;
		data->philo[i].right_fork_index = (i == 0 ? data->info.number_of_philosophers - 1 : i - 1);
		data->philo[i].input = data->info;
		data->philo[i].index = i;
		data->philo[i].death = &data->death;
		if (pthread_create(&data->philo[i].thread, NULL, (void *)&philo_hussle, &data->philo[i]))
		{
			write(2, "Something wrong inside philo thread\n", 40);
			return (1);
		}
		pthread_detach(data->philo[i].thread);
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_data			data;

	if (get_and_validate_input_data(argc, argv, &data.info))
		return (1);
	data.info.time_of_start = timestamp();
	if (create_mutexes(&data))
		return (1);
	pthread_mutex_lock(&data.death);
	if (create_philo(&data))
		return (1);
	pthread_mutex_lock(&data.death);
	return (0);
}
