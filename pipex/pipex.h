/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdelra <sabdelra@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 14:35:54 by sabdelra          #+#    #+#             */
/*   Updated: 2023/01/22 16:24:23 by sabdelra         ###   ########.fr       */
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


char	**ft_split(char *s, char del);
// [to-do] put proper error message for malloc failure
// open file
int		open_file(char *path, int option);

enum open_m {
	INFILE,
	OUTFILE,
};

enum pipe_end {
	READ_END,
	WRITE_END
} ;
// command
void	exec_cmd(char *cmd, char **envp);
//error
void	error_msg(char *msg);
//utils
char	*ft_strncpy(char *dest, char *src, int n);
int		ft_strncmp(char *s1, char *s2, int n);
void	free_split(char **split);
char	*ft_strcat(char *dest, char *src);
int		ft_strlen(char *s);
void	*ft_calloc(size_t count, size_t size);
void	*ft_memset(void *dest, int c, size_t len);

#endif
