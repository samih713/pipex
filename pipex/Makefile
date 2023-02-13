# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sabdelra <sabdelra@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/22 16:16:17 by sabdelra          #+#    #+#              #
#    Updated: 2023/02/13 18:30:14 by sabdelra         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC:= command.c error.c ft_split.c open_file.c pipex.c

BSRC:= ./bonus/command_bonus.c ./bonus/error_bonus.c ./bonus/ft_split_bonus.c ./bonus/open_file_bonus.c ./bonus/pipex_bonus.c

BOBJ:= $(BSRC:.c=.o)

OBJ:=$(SRC:.c=.o)

CFLAGS:= -Wall -Wextra -Werror -g

NAME:= pipex

LIBDIR:= ./utils

all:

bonus: $(BOBJ) libutils
	$(CC) $(CFLAGS) $(BOBJ) ./utils/libutils.a  -o $(NAME)

$(NAME): $(OBJ) libutils
	$(CC) $(CFLAGS) $(OBJ) ./utils/libutils.a  -o $@

libutils:
	$(MAKE) -C $(LIBDIR)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	rm -f $(BOBJ)
	$(MAKE) -C $(LIBDIR) clean

re: fclean all
	$(MAKE) -C $(LIBDIR) re

.PHONY: re fclean clean libutils all
