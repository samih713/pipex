# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sabdelra <sabdelra@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/10 21:57:08 by sabdelra          #+#    #+#              #
#    Updated: 2023/02/12 17:59:52 by sabdelra         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CCFLAGS:= -Wall -Wextra -Werror -g

SRC:= ft_strncpy.c ft_calloc.c ft_memset.c ft_strcat.c ft_strncmp.c ft_strlen.c

OBJ:= ft_strncpy.o ft_calloc.o ft_memset.o ft_strcat.o ft_strncmp.o ft_strlen.o

NAME:= libutils.a

all:$(NAME)

$(NAME): $(OBJ)
	ar rcs $@ $^

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: all fclean
