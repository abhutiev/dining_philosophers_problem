cmake_minimum_required(VERSION 3.17)
project(philo_one C)

set(CMAKE_C_STANDARD 99)

add_executable(philo_one main.c
		get_and_validate_input_data.c
		initial_mutex_creation.c
		passing_time_mutex_creation.c
		time_handling.c
		)