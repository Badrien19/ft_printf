# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: badrien <badrien@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/28 11:23:25 by badrien           #+#    #+#              #
#    Updated: 2019/11/13 13:34:19 by badrien          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = ft_printf.c printf_utils_lst.c printf_utils.c

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