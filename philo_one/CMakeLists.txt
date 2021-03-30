cmake_minimum_required(VERSION 3.17)
project(philo_one C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(philo_one
		get_input.c
		main.c
		mutexes.c
		philo_life.c
		time.c
		philosophers_life.c
		philosophers.h
		printing.c
		utils.c)
