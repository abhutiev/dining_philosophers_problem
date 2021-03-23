#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <semaphore.h>

typedef struct s_input_data
{
	int	number_of_philosophers;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	number_of_times_each_philo_must_eat;
}	t_input_data;

typedef struct s_philo
{
	long			last_dinner;
	long			time_to_die;
	pthread_t 	thread;
}	t_philo;

typedef struct s_data
{
	t_input_data	input_data;
	t_philo			*philo;
	pthread_mutex_t	output;
	pthread_mutex_t	*fork;
}	t_data;

int	get_and_validate_input_data(int argc, char **argv, t_input_data *info);
int	create_mutexes(t_data *data);

#endif
