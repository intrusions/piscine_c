# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jucheval <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/22 01:15:23 by jucheval          #+#    #+#              #
#    Updated: 2022/02/22 01:20:13 by jucheval         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= main.c ft_classic.c ft_math.c

NAME	= do-op

OBJS	= ${SRCS:.c=.o}

CFLAG	= -Wall -Wextra -Werror

CC		= gcc

.c.o:
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}: ${OBJS}
			${CC} ${CFLAG} ${OBJS} -o ${NAME}

all:		${NAME}

clean:
			rm -f ${OBJS}

fclean : 	clean
			rm -f ${NAME}

re : 		fclean all

.PHONY:		all clean fclean re

