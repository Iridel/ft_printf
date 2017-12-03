# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dhill <dhill@student.42.us.org>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/18 01:50:34 by dhill             #+#    #+#              #
#    Updated: 2017/12/02 17:22:32 by dhill            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = 	libftprintf.a

SRCS = $(wildcard *.c)

OBJ = ${SRCS:.c=.o} 

LIB_S = $(wildcard libft/*.c)
LIB_O = $(patsubst libft/%.c, %.o, $(LIB_S))
	
.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ) $(LIB_O)
	ar rcs $(NAME) $(OBJ) $(LIB_O)
	ranlib $(NAME)

%.o: %.c
	gcc -g -Wall -Wextra -Werror -Ilibft -Ift_printf -c $<

%.o: libft/%.c
	gcc -g -Wall -Wextra -Werror -Ilibft -c $<

clean: 
	rm -f $(LIB_O)
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
