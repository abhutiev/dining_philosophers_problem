#include "philosophers.h"


int main(int argc, char **argv)
{
	t_data data;

	if (get_input(argc, argv, &data.input))
		return (0);
	if (!create_semaphores(&data))
		return (0);
	return 0;
}
