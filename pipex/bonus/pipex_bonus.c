/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdelra <sabdelra@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 15:15:46 by sabdelra          #+#    #+#             */
/*   Updated: 2023/02/13 03:54:28 by sabdelra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"
/* TO-FIX */
/* MULTIPLE PIPE */
/* SIMPLIFY */
/* IMPROVE MAKE */

static void	close_fds(int *p_fd, int *fd);

enum {
	READ_END = 0,
	WRITE_END = 1,
	INFILE = 2,
	OUTFILE = 3
};

int	main(int argc, char **argv, char **envp)
{
	// VARIABLES
	int fd[4]; // [0,1 -> pipe; 2,3 -> infile/outfile]
	int	ch_pid;
	// int	pstat;
	// int i;
	// VARIABLES END

	// arg_error(argc);
	//
	fd[INFILE] = open_file(argv[1], INFILE);
	fd[OUTFILE] = open_file(argv[argc - 1], OUTFILE);
	if (pipe(fd) < 0)
		msg_error("pipe()");
	// FIRST PROCESS

	for (int i = argc - 4; i > 0; --i) {
		ch_pid = fork();
		if (!ch_pid) {
			dup2(fd[INFILE], STDIN_FILENO);
			dup2(fd[WRITE_END], STDOUT_FILENO);
			close(fd[WRITE_END]);
			exec_cmd(argv[i + 1], envp);
		}
		if (i == 1) {
			close(fd[INFILE]);
			fd[INFILE] = fd[READ_END]; // children start reading from pipe after first iteration
		}
	}
	// MIDDLE PROCESS
	dup2(fd[READ_END], STDIN_FILENO);
	dup2(fd[WRITE_END], STDOUT_FILENO);
	close(fd[0]);
	close(fd[1]);
	// // LAST PROCESS PARENT?
	// dup2(p_fd[READ_END], STDIN_FILENO);
	// dup2(fd[1], STDOUT_FILENO);
	// exec_cmd(argv[i], envp);
	close_fds(p_fd, fd);
	// wait(&pstat);
	// return (0);
}

static void	close_fds(int *p_fd, int *fd)
{
	close(p_fd[0]);
	close(fd[0]);
	close(p_fd[1]);
	close(fd[1]);
}
// fork how many times?
/* static void child(int *fd, int *p_fd, char *cmd, char *envp[])
{

	// COMMON
	close(p_fd[READ_END]);
	close(p_fd[WRITE_END]);
} */
