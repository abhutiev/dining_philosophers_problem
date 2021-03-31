cmake_minimum_required(VERSION 3.17)
project(philo_two C)

set(CMAKE_C_STANDARD 99)

add_executable(philo_two philo_two.c
		get_input.c
		semaphores.c
		time.c
		satiety.c
		printing.c
		philosophers_creation.c
		keep_spendin_most_our_lives_livin_in_the_philos_paradise.c
		utils.c
		)