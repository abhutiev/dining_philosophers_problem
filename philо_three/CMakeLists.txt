cmake_minimum_required(VERSION 3.17)
project(phil_three C)

set(CMAKE_C_STANDARD 99)

add_executable(phil_three philo_three.c
		semaphores.c
		get_input.c
		time.c
		utils.c
		printing.c)