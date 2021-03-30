#include "philosophers.h"

int	create_all_threads(t_data *data)
{
	if (create_philosophers(data))
		return (1);
	set_start_time(data);
	create_satiety_thread(data);
	pthread_mutex_unlock(data->mutex->etiquette); // when all philosophers are created we can this mutex should be unlocked. Philos can start eating
	return (0);
}

int	main(int argc, char **argv)
{
	t_data data;

	if (get_input(argc, argv, &data.input))
		return (0);
	if (create_mutexes(&data))
		return (0);
	data.start_of_simulation = (time_ms *)malloc(sizeof(time_ms));
	pthread_mutex_lock(data.mutex->etiquette); // locking mutex, which not allowing philosophers start eating while all philosophers are not created
	pthread_mutex_lock(data.mutex->stop);
	if (create_all_threads(&data))
		return (0);
	pthread_mutex_lock(data.mutex->stop); // this mutex will unlock when philosopher dies or when all philosophers ate enough times;
	return (0);
}
