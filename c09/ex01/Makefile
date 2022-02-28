# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jucheval <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/12 22:10:54 by jucheval          #+#    #+#              #
#    Updated: 2022/02/19 16:17:56 by jucheval         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= srcs/ft_putchar.c srcs/ft_swap.c srcs/ft_putstr.c srcs/ft_strlen.c srcs/ft_strcmp.c

NAME	= libft.a

OBJS	= ${SRCS:.c=.o}

CFLAG	= -Wall -Wextra -Werror

CC		= gcc

ICLD 	= includes	

.c.o:
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o} -I${ICLD}

${NAME}: ${OBJS}
			ar rc ${NAME} ${OBJS}

all:		${NAME}

clean:
			rm -f ${OBJS}

fclean : 	clean
			rm -f ${NAME}

re : 		fclean all

.PHONY:		all clean fclean re
