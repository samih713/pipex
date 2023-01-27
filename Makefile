# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sabdelra <sabdelra@student.42abudhabi.a    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/22 16:16:17 by sabdelra          #+#    #+#              #
#    Updated: 2023/01/22 16:28:33 by sabdelra         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC:= command.c error.c ft_split.c open_file.c pipex.c utils.c

OBJ:=$(SRC:.c=.o)

CFLAGS:= -Wall -Wextra -Werror -g

NAME = pipex

all:$(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@ -g

clean:
	rm $(OBJ)

fclean: clean
	rm $(NAME)

re: all fclean
