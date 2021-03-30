cmake_minimum_required(VERSION 3.17)
project(philo_one C)

set(CMAKE_C_STANDARD 99)

add_executable(philo_one philo_one.c
		get_input.c
		mutexes.c
		keep_spendin_most_our_lives_livin_in_the_philos_paradise.c
		philo_creation.c
		satiety.c
		time.c
		utils.c
		printing.c)