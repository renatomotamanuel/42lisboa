/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_handle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmota-ma <rmota-ma@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 14:40:26 by rmota-ma          #+#    #+#             */
/*   Updated: 2025/03/24 16:41:06 by rmota-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int	multiple_pipes(int argc, char **argv, char **envp, int *pids)
{
	int	pid1;
	int	proc;
	int	fd[2];

	if (pipe(fd) == -1)
		error();
	pid1 = fork();
	if (pid1 < 0)
		error();
	if (pid1 == 0)
	{
		free(pids);
		first_process(argv, envp, fd);
	}
	else
		dup2(fd[0], 0);
	close_fds();
	proc = parent(argc, argv, envp, pids);
	close_fds();
	close(0);
	waitpid(pid1, NULL, 0);
	waitpids(pids, argc - 5);
	argc = 0;
	waitpid(proc, &argc, 0);
	return (argc);
}

void	first_process(char **argv, char **envp, int *fd)
{
	int		infile;
	char	*path;
	char	**cmd1;

	cmd1 = NULL;
	if (!argv[2][0])
		error_env(cmd1);
	infile = open(argv[1], O_RDWR);
	if (infile < 0)
		error();
	cmd1 = ft_split(argv[2], ' ', 0, 0);
	if (!cmd1)
		error();
	path = find_path(envp, cmd1[0]);
	dup2(fd[1], 1);
	dup2(infile, 0);
	close_fds();
	if (execve(path, cmd1, envp) == -1)
		execve_error(path, cmd1);
}

int	parent(int argc, char **argv, char **envp, int *pids)
{
	int	var;
	int	var2;
	int	pid1;

	var = 3;
	var2 = 0;
	while (var < argc - 2)
	{
		pids[var2] = pimping(argv[var], envp, pids);
		var++;
		var2++;
	}
	pid1 = fork();
	if (pid1 < 0)
		error();
	if (pid1 == 0)
	{
		free(pids);
		last_process(argv, envp, argc, 1);
	}
	return (pid1);
}

int	pimping(char *cmd1, char **envp, int *pids)
{
	int	pid1;
	int	fd[2];

	if (pipe(fd) == -1)
		error();
	pid1 = fork();
	if (pid1 < 0)
		error();
	if (pid1 == 0)
	{
		free(pids);
		dup2(fd[1], 1);
		process(cmd1, envp);
	}
	else
	{
		close(fd[1]);
		dup2(fd[0], 0);
	}
	close(fd[0]);
	close(fd[1]);
	return (pid1);
}

void	process(char *argv, char **envp)
{
	char	**cmd1;
	char	*path;

	cmd1 = NULL;
	if (!argv[0])
	{
		perror("Error");
		close_fds();
		exit(126);
	}
	cmd1 = ft_split(argv, ' ', 0, 0);
	if (!cmd1)
		error();
	path = find_path(envp, cmd1[0]);
	close_fds();
	if (execve(path, cmd1, envp) == -1)
		execve_error(path, cmd1);
}
