/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdelra <sabdelra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 14:35:17 by sabdelra          #+#    #+#             */
/*   Updated: 2023/02/12 22:19:13 by sabdelra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	msg_error(char *msg)
{
	perror(msg);
	exit(EXIT_FAILURE);
}

void	arg_error(int argc)
{
	if (argc != 5)
	{
		write(2, "Invalid number of arguments\n", 29);
		exit (EXIT_FAILURE);
	}
}

void	exec_error(char **argv, char **path)
{
	write(STDERR_FILENO, argv[0], ft_strlen(argv[0]));
	write(STDERR_FILENO, ": command not found\n", 21);
	free_split(argv);
	free_split(path);
	exit(EXIT_FAILURE);
}

void	mem_error(void *allocd)
{
	if (!allocd)
	{
		perror("");
		exit(EXIT_FAILURE);
	}
}
