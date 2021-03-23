NAME =	philo_one

SRC =	main.c \
		get_and_validate_input_data.c

OBJ =	${SRC:.c=.o}

CC		=	gcc

CFLAGS	=	-Wall -Wextra -Werror


all: ${NAME}

%.o: %.c
	${CC} ${CFLAGS} -c $< -o $@

${NAME}: ${OBJ} philosophers.h
	${CC} ${OBJ} -o ${NAME}
	@echo "Binary file is ready"

clean:
	@rm ${OBJ}
	@echo "Objective files are cleaned"


fclean:
	@rm ./${NAME}
	@make clean
	@echo "Everything clear"

re:
	@make fclean
	@make all