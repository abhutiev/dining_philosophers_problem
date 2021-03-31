#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <semaphore.h>

# define RIGHT_FORK 1
# define LEFT_FORK 2

typedef unsigned long long time_ms;

typedef struct	s_input
{
	int				number_of_philosophers;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				number_of_times_each_philo_must_eat;
}	t_input;

typedef struct	s_semaphores
{
	sem_t			*stop;
	sem_t			*print;
	sem_t			*fork;
	sem_t 			*etiquette;
}	t_semaphores;

typedef struct	s_philo
{
	pthread_t		thread;
	t_semaphores	*semaphores;
	t_input			info;
	time_ms			*start_of_simulation;
	time_ms			time_of_death;
	int				index_left_fork;
	int				index_right_fork;
	int				index;
	int				*number_of_dinners;
}	t_philo;

typedef struct	s_data
{
	t_input			input;
	t_semaphores	*semaphores;
	t_philo			*philo;
	time_ms			*start_of_simulation;
	int				*number_of_dinners;
}	t_data;

int		get_input(int argc, char **argv, t_input *data);
int		create_philosophers(t_data *data);
void	better_usleep(time_ms time_to_sleep);
void	set_time_of_death(t_philo *philo);
void	set_first_time_of_death(t_philo *philo);
void	set_start_time(t_data *data);
time_ms	get_current_time(void);
int    create_satiety_thread(t_data *data);
git

#endif
