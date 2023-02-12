/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdelra <sabdelra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 15:15:46 by sabdelra          #+#    #+#             */
/*   Updated: 2023/02/12 21:10:30 by sabdelra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static void	child_one(char *cmd, int fd[], int pipe_fd[], char **envp);
static void	child_two(char *cmd, int fd[], int pipe_fd[], char **envp);
static void	close_fds(int *pipe_fd, int *fd);

int	main(int argc, char **argv, char **envp)
{
	int	fd[2];
	int	pipe_fd[2];
	int	child[2];
	int	pstat;
	int i;

	i = 0;
	arg_error(argc);
	fd[0] = open_file(argv[1], INFILE);
	fd[1] = open_file(argv[argc], OUTFILE);
	if (pipe(pipe_fd) < 0)
		msg_error("pipe()");
	while (i < argc - 1)
	{
		child[0] = fork();
		if (child[0] < 0)
			msg_error("fork");
		else if (child[0] == 0 && !i)
			child_one(argv[2], fd, pipe_fd, envp);
		else
		{

		}
		i++;
	}
	child[1] = fork();
	if (child[1] < 0)
		msg_error("fork");
	if (child[1] == 0)
		child_two(argv[argc - 1], fd, pipe_fd, envp); //
	close_fds(pipe_fd, fd);
	wait(&pstat);
	return (0);
}

static void	close_fds(int *pipe_fd, int *fd)
{
	close(pipe_fd[0]);
	close(fd[0]);
	close(pipe_fd[1]);
	close(fd[1]);
}

static void	child_one(char *cmd, int fd[], int pipe_fd[], char **envp)
{
	dup2(fd[0], STDIN_FILENO);
	dup2(pipe_fd[WRITE_END], STDOUT_FILENO);
	close(pipe_fd[READ_END]);
	close(pipe_fd[WRITE_END]);
	close(fd[1]);
	exec_cmd(cmd, envp);
}

static void	child_two(char *cmd, int fd[], int pipe_fd[], char **envp)
{
	dup2(fd[1], STDOUT_FILENO);
	dup2(pipe_fd[READ_END], STDIN_FILENO);
	close(pipe_fd[READ_END]);
	close(pipe_fd[WRITE_END]);
	close(fd[0]);
	exec_cmd(cmd, envp);
}
/* -->  */
