/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdelra <sabdelra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 15:21:17 by sabdelra          #+#    #+#             */
/*   Updated: 2023/02/06 21:46:01 by sabdelra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// option is either as INFILE or OUTFILE, they both have different permissions
int	open_file(char *path, int option)
{
	int fd;

	fd = -1;
	if (option == INFILE)
	{
		if (access(path, R_OK) == -1) // R_OK has a pre-requisete F_OK
			error_msg("Infile error");
		else
			fd = open(path, O_RDONLY);
	}
	else
		fd = open(path, O_CREAT | O_TRUNC | O_WRONLY, 0644); // owner user/write, everyone else read
	if (fd < 0)
		error_msg("File error");
	 return (fd);
}

