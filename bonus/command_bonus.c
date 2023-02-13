/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdelra <sabdelra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 15:22:47 by sabdelra          #+#    #+#             */
/*   Updated: 2023/02/12 20:22:57 by sabdelra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static char	**get_path(char **envp);
static void	exec_path(char **path, char **argv, char **envp);

void	exec_cmd(char *cmd, char **envp)
{
	char	**argv;
	char	**path;

	argv = ft_split(cmd, ' ');
	path = get_path(envp);
	if (!access(cmd, X_OK))
		execve(argv[0], argv, envp);
	else
		exec_path(path, argv, envp);
	exec_error(argv, path);
}

static char	**get_path(char **envp)
{
	char	**path;
	int		i;

	i = 0;
	while (ft_strncmp(envp[i], "PATH=", 5))
		i++;
	path = ft_split(envp[i] + 5, ':');
	return (path);
}

static void	exec_path(char **path, char **argv, char **envp)
{
	int		i;
	int		cmd_size;
	char	*pth_cmd;

	i = 0;
	while (path[i])
	{
		cmd_size = ft_strlen(path[i]) + ft_strlen(argv[0]) + 2;
		pth_cmd = ft_calloc(sizeof(char), cmd_size);
		ft_strcat(pth_cmd, path[i]);
		ft_strcat(pth_cmd, "/");
		ft_strcat(pth_cmd, argv[0]);
		if (!access(pth_cmd, X_OK))
			execve(pth_cmd, argv, envp);
		free(pth_cmd);
		i++;
	}
}
