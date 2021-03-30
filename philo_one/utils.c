#include "philosophers.h"

int	ft_strlen(char *s)
{
	int i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}


static size_t	len_str_to_prepare(time_ms n)
{
	size_t			counter;

	counter = 1;
	while (n /= 10)
		counter++;
	return (counter);
}

char	*ft_ulltoa(time_ms n)
{
	char				*result;
	int					length;

	length = len_str_to_prepare(n);
	result = (char *)malloc(sizeof(char) * (length + 1));
	result[length] = '\0';
	while (--length >= 0)
	{
		result[length] = (n % 10) + '0';
		n = n / 10;
	}
	return (result);
}
