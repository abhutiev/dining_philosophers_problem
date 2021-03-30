cmake_minimum_required(VERSION 3.17)
project(philo_one C)

set(CMAKE_C_STANDARD 99)

add_executable(philo_one philo_one.c
		get_input.c
		mutexes.c
		philosophers_life.c
		time.c
		utils.c
		printing.c)