#include "philosophers.h"

static void	*satiety(t_data *data)
{
	int	i;

	pthread_mutex_lock(data->mutex->etiquette);
	pthread_mutex_unlock(data->mutex->etiquette);
	while (1)
	{
		for (i = 0; i < data->input.number_of_philosophers; i++) {
			if (data->number_of_dinners[i] < data->input.number_of_times_each_philo_must_eat)
				break;
		}
		if (i == data->input.number_of_philosophers)
			break;
	}
	sem_wait(data->semaphores->print);
	printf("%llu Philosophers fed up", get_current_time() - *data->start_of_simulation);
	sem_post(data->semaphores->stop);
	return (NULL);
}

int    create_satiety_thread(t_data *data)
{
   	pthread_t gluttony;

    if (data->input.number_of_times_each_philo_must_eat)
	{
		if (pthread_create(&gluttony, NULL, (void *)&satiety, data))
		{
			write(2, "Something wrong with thread creation\n", 40);
			return (1);
		}
		pthread_detach(gluttony);
	}
    return (0);
}