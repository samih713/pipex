/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdelra <sabdelra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 14:35:54 by sabdelra          #+#    #+#             */
/*   Updated: 2023/02/13 14:58:48 by sabdelra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

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
# include "../utils/utils.h"

char	**ft_split(char *s, char del);
int		open_file(char *path, int option);
void	free_split(char **split);

enum {
	READ_END = 0,
	WRITE_END = 1,
	INFILE = 2,
	OUTFILE = 3
};
// command
void	exec_cmd(char *cmd, char **envp);
//error
void	msg_error(char *msg);
void	arg_error(int argc);
void	exec_error(char **argv, char **path);
void	mem_error(void *allocd);

#endif
