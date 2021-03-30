NAME =	philo_one

SRC =	philo_one.c \
		get_input.c \
		mutexes.c \
		keep_spendin_most_our_lives_livin_in_the_philos_paradise.c \
		philo_creation.c \
		printing.c \
		satiety.c \
		time.c \
		utils.c

OBJ =	${SRC:.c=.o}

CC		=	gcc

CFLAGS	= -Wall -Wextra -Werror


all: ${NAME}

%.o: %.c
	${CC} ${CFLAGS} -c $< -o $@

${NAME}: ${OBJ} philosophers.h
	${CC} ${OBJ} -o ${NAME}
	@echo "Binary file is ready"

clean:
	@rm ${OBJ}
	@echo "Objective files are cleaned"

test1:
	./${NAME} 5 800 200 200

test2:
	./${NAME} 5 800 200 200 7

test3:
	./${NAME} 4 410 200 200

test4:
	./${NAME} 5 310 200 100

test5:
	./${NAME} 2 410 200 200
fclean:
	@rm ./${NAME}
	@make clean
	@echo "Everything clear"

re:
	@make fclean
	@make all