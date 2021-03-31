cmake_minimum_required(VERSION 3.17)
project(philo_two C)

set(CMAKE_C_STANDARD 99)

add_executable(philo_two philo_two.c
		get_input.c
		semaphores.c)