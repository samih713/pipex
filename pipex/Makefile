# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sabdelra <sabdelra@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/22 16:16:17 by sabdelra          #+#    #+#              #
#    Updated: 2023/02/11 22:17:33 by sabdelra         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC:= command.c error.c ft_split.c open_file.c pipex.c

OBJ:=$(SRC:.c=.o)

CFLAGS:= -Wall -Wextra -Werror -g

NAME:= pipex

LIBDIR:= ./utils

all: $(NAME)

$(NAME): $(OBJ) libutils
	$(CC) $(CFLAGS) $(OBJ) ./utils/libutils.a  -o $@

libutils:
	cd $(LIBDIR) && make

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: re fclean clean libutils all
