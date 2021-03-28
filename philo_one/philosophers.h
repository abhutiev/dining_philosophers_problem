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

typedef unsigned long long time_ms;

typedef struct	s_input
{
	int				number_of_philosophers;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				number_of_times_each_philo_must_eat;
}	t_input;

typedef struct	s_mutexes
{
	pthread_mutex_t	*stop;
	pthread_mutex_t	*print;
	pthread_mutex_t	*fork;
	pthread_mutex_t *etiquette;
}	t_mutexes;

typedef struct	s_philo
{
	pthread_t	thread;
	t_mutexes	*mutex;
	t_input		info;
	time_ms		*start_of_simulation;
	time_ms		time_of_death;
	int			index_left_fork;
	int			index_right_fork;
	int			index;
}	t_philo;

typedef struct	s_data
{
	t_input		input;
	t_mutexes	*mutex;
	t_philo		*philo;
	time_ms		*start_of_simulation;
}	t_data;

int	get_input(int argc, char **argv, t_input *data);
int	create_mutexes(t_data *data);
void	set_start_time(t_data *data);
void	set_first_time_of_death(t_philo *philo);
void	set_time_of_death(t_philo *philo);
time_ms	get_current_time(void);
void	*philo_hussle(t_philo *philo);

#endif
