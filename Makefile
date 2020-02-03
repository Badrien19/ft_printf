# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: badrien <badrien@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/28 11:23:25 by badrien           #+#    #+#              #
#    Updated: 2020/02/03 15:31:46 by badrien          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =	ft_printf.c printf_utils.c conversion_1.c conversion_2.c flags.c \
		conversion_utils_1.c conversion_utils_2.c conversion_utils_3.c

OBJS = ${SRCS:.c=.o}

NAME = libftprintf.a

CC = gcc

LIB = ar rc

RM = rm -rf

CFLAGS = -Wall -Wextra -Werror

all:	${NAME}

${NAME}:	${OBJS}
			${LIB} ${NAME} ${OBJS}

clean:
			${RM} ${OBJS} ${OBJSBONUS}

fclean: 	clean
			${RM} ${NAME}

re: fclean all

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}