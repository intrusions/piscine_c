SRCS	= main.c read_dict.c read_nbr_dict.c utils_string.c print_number.c ft_atoi_spe.c array_utils.c

OBJS	= ${SRCS:.c=.o}

NAME	= rush-02

GCC		= gcc

RM		= rm -f

CFLAGS	= -Wall -Wextra -Werror

.c.o:
		${GCC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
		${GCC} -o ${NAME} ${OBJS}

all:		${NAME}

clean:
		${RM} ${OBJS}

fclean:		clean
		${RM} ${NAME}

re:		fclean all

.PHONY:		all clean fclean re
