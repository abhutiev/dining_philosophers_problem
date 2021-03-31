#include "philosophers.h"

static int	create_forks_semaphore(t_data *data)
{
	sem_unlink("/forks");
	data->semaphores->forks = sem_open("/forks", O_CREAT, 644, data->input.number_of_philosophers);
	if (data->semaphores->forks == (sem_t *)-1)
	{
		write(1, "Something wrong with semaphore creation\n", 40);
		return (1);
	}
	return (0);
}

static int	create_print_semaphore(t_data *data)
{
	sem_unlink("/print");
	data->semaphores->print = sem_open("/print", O_CREAT, 644, 1);
	if (data->semaphores->print == (sem_t *)-1)
	{
		write(1, "Something wrong with semaphore creation\n", 40);
		return (1);
	}
	return (0);
}

static int	create_stop_semaphore(t_data *data)
{
	sem_unlink("/stop");
	data->semaphores->stop = sem_open("/stop", O_CREAT, 644, 1);
	if (data->semaphores->stop == (sem_t *)-1)
	{
		write(1, "Something wrong with semaphore creation\n", 40);
		return (1);
	}
	return (0);
}

static int	create_etiquette_semaphore(t_data *data)
{
	sem_unlink("/etiquette");
	data->semaphores->etiquette = sem_open("/etiquette", O_CREAT, 644, 1);
	if (data->semaphores->etiquette == (sem_t *)-1)
	{
		write(1, "Something wrong with semaphore creation\n", 40);
		return (1);
	}
	return (0);
}

int	create_semaphores(t_data *data)
{
	data->semaphores = (t_semaphores *)malloc(sizeof(t_semaphores));
	if (create_forks_semaphore(&data))
		return (1);
	if (create_print_semaphore(data))
		return (1);
	if (create_stop_semaphore(data))
		return (1);
	if (create_etiquette_semaphore(data))
		return (1);
	return (0);
}