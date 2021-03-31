#include "philosophers.h"

int	create_threads(t_data *data)
{
	set_start_time(data);
	if (create_philosophers(data))
		return (1);
	create_satiety_thread(data);
	sem_post(data->semaphores->etiquette);
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
	sem_wait(data.semaphores->stop);
	if (create_threads(&data))
		return (0);
	sem_wait(data.semaphores->stop);
	return (0);
}
