# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dhill <dhill@student.42.us.org>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/18 01:50:34 by dhill             #+#    #+#              #
#    Updated: 2017/12/05 19:48:16 by dhill            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	libftprintf.a

SRCS =	ft_printf.c parsing.c handle.c helper.c help_cont.c signed_utility.c \
		unsigned_utility.c

OBJ =	${SRCS:.c=.o} 

LIB_O =	libft/*.o

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	cd libft && make
	ar rcs $(NAME) $(OBJ) $(LIB_O)
	ranlib $(NAME)

%.o: %.c
	gcc -g -Wall -Wextra -Werror -Ilibft -Ift_printf -c $<

clean: 
	rm -f $(LIB_O)
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
