/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdelra <sabdelra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 15:21:17 by sabdelra          #+#    #+#             */
/*   Updated: 2023/02/13 18:50:59 by sabdelra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	open_file(char *path, int option)
{
	int	fd;

	fd = -1;
	if (option == INFILE)
	{
		if (access(path, R_OK) == -1)
			msg_error("Infile error");
		else
			fd = open(path, O_RDONLY);
	}
	else
		fd = open(path, O_CREAT | O_TRUNC | O_WRONLY, 0777);
	if (fd < 0)
		msg_error("File error");
	return (fd);
}
