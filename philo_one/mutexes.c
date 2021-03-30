#include "philosophers.h"

static pthread_mutex_t **create_forks_mutex(int number_of_philosophers)
{
	pthread_mutex_t	**forks;

	forks = (pthread_mutex_t **)malloc(sizeof(pthread_mutex_t *) * number_of_philosophers);
	if (!forks)
	{
		write(2, "Something wrong with memory allocation\n", 39);
		return (NULL);
	}
	for (int i = 0; i < number_of_philosophers; i++)
	{
		forks[i] = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
		if (pthread_mutex_init(forks[i], NULL))
		{
			write(2, "Something wrong with mutex creation\n", 36);
			return (NULL);
		}
	}
	return (forks);
}

static pthread_mutex_t *create_print_mutex(void)
{
	pthread_mutex_t *print;

	print = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
	if (!print || pthread_mutex_init(print, NULL))
	{
		write(2, "Something wrong with mutex creation\n", 36);
		return (NULL);
	}
	return (print);
}

static pthread_mutex_t *create_death_mutex(void)
{
	pthread_mutex_t *death;

	death = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
	if (!death || pthread_mutex_init(death, NULL))
	{
		write(2, "Something wrong with mutex creation\n", 36);
		return (NULL);
	}
	return (death);
}

static pthread_mutex_t *create_etiquette_mutex(void)
{
	pthread_mutex_t *etiquette;

	etiquette = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
	if (!etiquette || pthread_mutex_init(etiquette, NULL))
	{
		write(2, "Something wrong with mutex creation\n", 36);
		return (NULL);
	}
	return (etiquette);
}

static	pthread_mutex_t *create_satiety_mutex(void)
{
	pthread_mutex_t *satiety;

	satiety = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
	if (!satiety || pthread_mutex_init(satiety, NULL))
	{
		write(2, "Something wrong with mutex creation\n", 36);
		return (NULL);
	}
	return (satiety);
}

int	create_mutexes(t_data *data)
{
	data->mutex = (t_mutexes *)malloc(sizeof(t_mutexes));
	data->mutex->fork = create_forks_mutex(data->input.number_of_philosophers);
	if (!data->mutex->fork)
		return (1);
	data->mutex->print = create_print_mutex();
	if (!data->mutex->print)
		return (1);
	data->mutex->stop = create_death_mutex();
	if (!data->mutex->stop)
		return (1);
	data->mutex->etiquette = create_etiquette_mutex();
	if (!data->mutex->etiquette)
		return (1);
	data->mutex->satiety = create_satiety_mutex();
	if (!data->mutex->satiety)
		return (1);
	return (0);
}
