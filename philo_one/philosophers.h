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

typedef unsigned long long time_ms;

typedef struct s_input
{
	int				number_of_philosophers;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				number_of_times_each_philo_must_eat;
}	t_input;

typedef struct s_philo
{
	size_t			index;
	time_ms			last_dinner;
	time_ms			time_to_die;
	size_t	left_fork_index;
	size_t right_fork_index;
	pthread_t 		thread;
	t_input			input;
	pthread_mutex_t	output;
	pthread_mutex_t	*fork;
	int				number;
	int				consuming;
}	t_philo;

typedef struct s_data
{
	t_input			input;
	t_philo			*philo;
	pthread_mutex_t	output;
	pthread_mutex_t	*fork;
}	t_data;

int		get_and_validate_input_data(int argc, char **argv, t_input *info);
int		create_mutexes(t_data *data);
time_ms time_to_die_in_ms(t_input input);
time_ms timestamp(void);

//time_ms
#endif
