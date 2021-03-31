#include "philosophers.h"

int	create_threads(t_data *data)
{
	if (create_philosophers(data))
		return (1);
	set_start_time(data);
	create_satiety_thread(data);
	pthread_mutex_unlock(data->mutex->etiquette);
	return (0);
}

int main(int argc, char **argv)
{
	t_data data;

	if (get_input(argc, argv, &data.input))
		return (0);
	if (create_semaphores(&data))
		return (0);
	sem_wait(data.semaphores->etiquette);
	if (create_threads(&data))
		return (0);
	sem_wait(data.semaphores->stop);
	return (0);
}
