#include "philosophers.h"

void	almost_real_usleep(time_ms time_to_sleep)
{
	const time_ms start = timestamp();

	while (timestamp() < start + time_to_sleep)
		usleep(1);
}
