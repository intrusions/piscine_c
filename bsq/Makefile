# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lgiband <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/21 15:51:19 by lgiband           #+#    #+#              #
#    Updated: 2022/02/23 19:40:39 by jucheval         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = srcs/parsing.c srcs/ft_display.c srcs/main.c srcs/parsing_map.c srcs/utils.c srcs/ft_find_big_square.c srcs/ft_find_big_square2.c srcs/utils2.c srcs/ft_stdin.c

OBJS = ${SRCS:.c=.o}

NAME = bsq

.c.o:
	gcc -Wall -Wextra -Werror -c $< -o $(<:.c=.o)

${NAME}:        ${OBJS}
	${CC} ${CFLAGS} -o ${NAME} ${OBJS}

all :   ${NAME}

clean :
	rm -f ${OBJS}

fclean : clean
	rm -f ${NAME}

re : fclean all

.PHONY : clean re all fclean
