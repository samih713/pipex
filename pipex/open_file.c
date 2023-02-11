/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdelra <sabdelra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 15:21:17 by sabdelra          #+#    #+#             */
/*   Updated: 2023/02/10 20:37:23 by sabdelra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// option is either as INFILE or OUTFILE, they both have different permissions
int	open_file(char *path, int option)
{
	int	fd;

	fd = -1;
	if (option == INFILE)
	{
		if (access(path, R_OK) == -1)
			error_msg("Infile error");
		else
			fd = open(path, O_RDONLY);
	}
	else
		fd = open(path, O_CREAT | O_TRUNC | O_WRONLY, 0644);
	if (fd < 0)
		error_msg("File error");
	return (fd);
}
