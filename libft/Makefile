# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dhill <dhill@student.42.us.org>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/18 01:50:34 by dhill             #+#    #+#              #
#    Updated: 2017/12/02 01:54:53 by dhill            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = 	libft.a
SRCS = 	ft_atoi.c ft_memalloc.c ft_putendl_fd.c ft_strdup.c ft_strncpy.c \
		ft_bzero.c ft_memccpy.c ft_putnbr.c ft_strequ.c ft_strnequ.c \
		ft_intlen.c ft_memchr.c ft_putnbr_fd.c ft_striter.c ft_strnew.c \
		ft_memcmp.c ft_putstr.c ft_striteri.c ft_strnstr.c ft_isalpha.c \
		ft_memcpy.c ft_putstr_fd.c ft_strjoin.c ft_strrchr.c ft_isascii.c \
		ft_memdel.c ft_strcat.c ft_strlcat.c ft_strsplit.c ft_isdigit.c \
		ft_memmove.c ft_strchr.c ft_strlen.c ft_strstr.c ft_ispositive.c \
		ft_memset.c ft_strclr.c ft_strmap.c ft_strsub.c ft_isprint.c \
		ft_putchar.c ft_strcmp.c ft_strmapi.c ft_strtrim.c ft_isalnum.c \
		ft_iswhitespace.c ft_putchar_fd.c ft_strcpy.c ft_strncat.c \
		ft_tolower.c ft_itoa.c ft_putendl.c ft_strdel.c ft_strncmp.c \
		ft_toupper.c ft_lstpop.c ft_lstnew.c ft_lstdelone.c ft_lstdel.c \
		ft_lstadd.c ft_lstiter.c ft_lstmap.c ft_tprint.c ft_findchr.c \
		ft_ceil.c ft_sqrt.c ft_realloc.c ft_tprint.c ft_strnjoin.c \
		ft_strjoin_free.c ft_strjoin_null.c get_next_line.c ft_isupper.c
OBJ = ${SRCS:.c=.o} 

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $^

%.o: %.c
	gcc -g -Wall -Wextra -Werror -c $<

clean: 
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
