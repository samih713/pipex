/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdelra <sabdelra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 14:35:54 by sabdelra          #+#    #+#             */
/*   Updated: 2023/02/11 15:23:32 by sabdelra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <stdlib.h>
# include <assert.h>
# include <stdbool.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdint.h>
# include <assert.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <errno.h>
# include "./utils/utils.h"

char	**ft_split(char *s, char del);
int		open_file(char *path, int option);
void	free_split(char **split);

enum e_open_m {
	INFILE,
	OUTFILE,
};

enum e_pipe_end {
	READ_END,
	WRITE_END
} ;
// command
void	exec_cmd(char *cmd, char **envp);
//error
void	error_msg(char *msg);
void	argcheck(int argc);

#endif
