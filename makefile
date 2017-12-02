# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dhill <dhill@student.42.us.org>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/23 16:05:03 by dhill             #+#    #+#              #
#    Updated: 2017/12/02 02:08:13 by dhill            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_printf

FLAGS = -g -Wall -Wextra -Werror

FILES = ft_printf.c parsing.c handle.c helper.c signed_utility.c \
		unsigned_utility.c

OBJS = ${FILES:.c=.o}

LIB = libft/libft.a

.PHONY: all clean fclean re

all: $(NAME)

$(LIB): force
	make -C libft

$(NAME): $(LIB) $(OBJS)
	gcc $(FLAGS) $(LIB) $(OBJS) -o $(NAME)

force:
	@true

%.o: %.c
	@echo "Building... $@"
	@gcc $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	make clean -C libft

fclean: clean
	rm -f $(NAME)
	make fclean -C libft

re: fclean all
