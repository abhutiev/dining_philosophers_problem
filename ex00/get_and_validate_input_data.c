#include "philosophers.h"

static int	ft_atoi(const char *str)
{
	int				i;
	int				sign;
	unsigned int	res;

	sign = 1;
	i = 0;
	res = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			(sign = -1);
	while (str[i] >= '0' && str[i] <= '9')
		res = res * 10 + str[i++] - '0';
	return ((int)(res) * sign);
}

int	get_and_validate_input_data(int argc, char **argv, t_input_data *info)
{
	if (argc != 5 && argc != 6)
	{
		write(2, "Wrong number of arguments\n", 26);
		return (1);
	}
	info->number_of_philosophers = ft_atoi(argv[1]);
	info->time_to_die = ft_atoi(argv[2]);
	info->time_to_eat = ft_atoi(argv[3]);
	info->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		info->number_of_times_each_philo_must_eat = ft_atoi(argv[5]);
	else
		info->number_of_times_each_philo_must_eat = 0;
	if (info->time_to_sleep <= 0 || info->time_to_eat <= 0
		|| info->time_to_die <= 0
		|| info->number_of_philosophers <= 0
		|| (argc == 6 && info->number_of_times_each_philo_must_eat <= 0))
	{
		write(2, "Incorrect input data\n", 21);
		return (1);
	}
	return (0);
}
