/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdelra <sabdelra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 15:15:46 by sabdelra          #+#    #+#             */
/*   Updated: 2023/02/13 18:56:28 by sabdelra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static void	close_fds(int *fd);
static void	child(int *fd, char *argv, char **envp);
static void	child_loop(int *fd, char **argv, char **envp, int i);

int	main(int argc, char **argv, char **envp)
{
	int	fd[7];
	int	pstat;
	int	i;

	arg_error(argc);
	i = argc - 4;
	fd[6] = 0;
	if (!ft_strncmp(argv[1], "here_doc", 9))
		fd[6] = 1;
	fd[5] = i;
	fd[INFILE] = open_file(argv[1 + fd[6]], INFILE, fd[6]);
	fd[OUTFILE] = open_file(argv[argc - 1], OUTFILE, fd[6]);
	if (pipe(fd) < 0)
		msg_error("pipe()");
	while (i > 0)
	{
		child_loop(fd, argv, envp, i + fd[6]);
		--i;
	}
	dup2(fd[READ_END], STDIN_FILENO);
	dup2(fd[OUTFILE], STDOUT_FILENO);
	close_fds(fd);
	exec_cmd(argv[argc - 2], envp);
	wait(&pstat);
	return (0);
}

static void	close_fds(int *fd)
{
	close(fd[INFILE]);
	close(fd[OUTFILE]);
	close(fd[READ_END]);
	close(fd[WRITE_END]);
}

static void	child(int *fd, char *argv, char **envp)
{
	dup2(fd[INFILE], STDIN_FILENO);
	dup2(fd[WRITE_END], STDOUT_FILENO);
	close_fds(fd);
	exec_cmd(argv, envp);
}

static void	child_loop(int *fd, char **argv, char **envp, int i)
{
	int	ch_pid;

	ch_pid = 1;
	if (ch_pid)
	ch_pid = fork();
	if (!ch_pid)
	{
		if (!ch_pid && i < fd[5])
		{
			fd[4] = fd[INFILE];
			fd[INFILE] = fd[READ_END];
			close(fd[4]);
		}
		if (!ch_pid)
			child(fd, argv[i + 1], envp);
	}
}
