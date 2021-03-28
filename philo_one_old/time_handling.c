#include "philosophers.h"

time_ms time_to_die_in_ms(t_input input)
{
	struct timeval	time;
	time_ms			result;

	gettimeofday(&time, NULL);
	result = time.tv_sec * 1000 + time.tv_usec / 1000 + input.time_to_die;
	return (result);
}

time_ms timestamp(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time_ms)(time.tv_sec * 1000 + time.tv_usec / 1000));
}