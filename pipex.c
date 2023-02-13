/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdelra <sabdelra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 15:15:46 by sabdelra          #+#    #+#             */
/*   Updated: 2023/02/13 18:33:35 by sabdelra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	close_fds(int *fd);
static void	child(int *fd, char *argv, char **envp);
static void	child_loop(int *fd, char **argv, char **envp, int i);

int	main(int argc, char **argv, char **envp)
{
	int	fd[6];
	int	pstat;
	int	i;

	arg_error(argc);
	i = argc - 4;
	fd[5] = i;
	fd[INFILE] = open_file(argv[1], INFILE);
	fd[OUTFILE] = open_file(argv[argc - 1], OUTFILE);
	if (pipe(fd) < 0)
		msg_error("pipe()");
	while (i > 0)
	{
		child_loop(fd, argv, envp, i);
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
