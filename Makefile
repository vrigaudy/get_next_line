
NAME		= get_next_line.a
OBJ			= ${SRC:.c=.o}
CC 			= cc
CC_FLAGS 	= -Wall -Wextra -Werror
SRC			= get_next_line.c get_next_line_utils.c

.c.o:
			${CC} ${CC_FLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJ}
			ar rcs ${NAME} ${OBJ}

all:		${NAME}

clean:
			rm -f ${OBJ}

fclean:		clean
			rm -f ${NAME}

re:			fclean all

.PHONY:		all bonus clean fclean re
