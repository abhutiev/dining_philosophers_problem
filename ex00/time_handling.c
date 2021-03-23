#include "philosophers.h"

time_ms time_to_die_in_ms(t_data *data)
{
	struct timeval	time;
	time_ms			result;

	gettimeofday(&time, NULL);
	result = time.tv_sec * 1000 + time.tv_usec / 1000 + data->input_data.time_to_die;
	return (result);
}

//time_ms time_to_die(t_data *data)
//{
//
//}