/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_file_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdelra <sabdelra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 15:21:17 by sabdelra          #+#    #+#             */
/*   Updated: 2023/02/13 18:59:40 by sabdelra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	open_file(char *path, int option, int here_doc)
{
	int	fd;

	fd = -1;
	if (option == INFILE)
	{
		if (access(path, R_OK) == -1)
			msg_error("Infile error");
		else if (!here_doc)
			fd = open(path, O_RDONLY | O_TRUNC);
		else if (here_doc)
			fd = open(path, O_RDONLY | O_APPEND);
	}
	else if (!here_doc)
		fd = open(path, O_CREAT | O_TRUNC | O_WRONLY, 0777);
	else if (here_doc)
		fd = open(path, O_CREAT | O_APPEND | O_WRONLY, 0777);
	if (fd < 0)
		msg_error("File error");
	return (fd);
}
