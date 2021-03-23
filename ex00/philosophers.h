#ifndef EX00_PHILOSOPHERS_H
#define EX00_PHILOSOPHERS_H

# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <semaphore.h>

typedef struct s_info
{
	int number_of_philosophers;
	int time_to_die;
	int time_to_eat;
	int time_to_sleep;
	int number_of_times_each_philo_must_eat;
} t_info;

int	get_and_validate_input_data(int argc, char **argv, t_info *info);

#endif
