/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdelra <sabdelra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 15:22:47 by sabdelra          #+#    #+#             */
/*   Updated: 2023/02/10 17:42:52 by sabdelra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	exec_error(char **argv, char **path);

void	exec_cmd(char *cmd, char **envp)
{
	char	**argv;
	char	**path;
	char	*pth_cmd;
	int		cmd_size;
	int		i;

	i = 0;
	argv = ft_split(cmd, ' ');
	while (ft_strncmp(envp[i], "PATH=", 5))
		i++;
	path = ft_split(envp[i] + 5, ':');
	i = 0;
	while (path[i])
	{
		cmd_size = ft_strlen(path[i]) + ft_strlen(argv[0]) + 2;
		pth_cmd = ft_calloc(sizeof(char), cmd_size);
		ft_strcat(pth_cmd, path[i]);
		ft_strcat(pth_cmd, "/");
		ft_strcat(pth_cmd, argv[0]);
		execve(pth_cmd, argv, envp);
		free(pth_cmd);
		i++;
	}
	exec_error(argv, path);
}

static void	exec_error(char **argv, char **path)
{
	write(STDERR_FILENO, argv[0], ft_strlen(argv[0]));
	write(STDERR_FILENO, ": command not found\n", 21);
	free_split(argv);
	free_split(path);
	exit(EXIT_FAILURE);
}
