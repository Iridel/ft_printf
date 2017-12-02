# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dhill <dhill@student.42.us.org>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/18 01:50:34 by dhill             #+#    #+#              #
#    Updated: 2017/12/02 02:41:10 by dhill            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = 	printf_libft.a

SRCS = *.c

OBJ = ${SRCS:.c=.o} 

LIB_S = libft/*.c
LIB_O = ${LIB_S:.c=.o}
	
.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ) $(LIB_O)
	ar rcs $(NAME) $^
	ranlib $(NAME)

%.o: %.c
	gcc -g -Wall -Wextra -Werror -Ilibft -Ift_printf -c $<

clean: 
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
