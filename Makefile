# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpulgar- <mpulgar-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/05 16:07:11 by mpulgar-          #+#    #+#              #
#    Updated: 2025/06/05 16:54:46 by mpulgar-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

INCLUDE = ft_printf.h

SRC = fun1.c \
		fun2.c \
		ft_printf.c \

OBJ = $(SRC:.c=.o)

CC = cc

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

AR = @ar rcs

all: ${NAME}

${NAME} : ${OBJ}
	${AR} ${NAME} ${OBJ}

clean: 
	@${RM} ${OBJ}

fclean: clean
	@${RM} ${NAME}
	
re: fclean all

.PHONY: all clean fclean re
	