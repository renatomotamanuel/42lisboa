/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_handle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmota-ma <rmota-ma@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 14:40:26 by rmota-ma          #+#    #+#             */
/*   Updated: 2025/03/18 18:22:17 by rmota-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int	pimping(char *cmd1, char **envp)
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
		close(fd[0]);
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
	return(pid1);
}

void	process(char *argv, char **envp)
{
	char	**cmd1;
	char	*path;

	cmd1 = NULL;
	if (!argv[0])
		error_env(cmd1);
	cmd1 = ft_split(argv, ' ', 0, 0);
	if (!cmd1)
		error();
	path = find_path(envp, cmd1[0]);
	if (path == 0)
		error_env(cmd1);
	close_fds();
	if (execve(path, cmd1, envp) == -1)
		execve_error(path, cmd1);
}

int	multiple_pipes(int argc, char **argv, char **envp, int *pids)
{
	int	infile;
	int	var;
	int	var2;
	int	outfile;

	var = 2;
	var2 = 0;
	infile = open(argv[1], O_RDWR);
	if (infile < 0)
	{
		perror("Error");
		var = -1;
	}
	outfile = open(argv[argc - 1], O_RDWR | O_CREAT, 0644);
	if (outfile < 0 || var == -1)
		error();
	dup2(infile, 0);
	while (var < argc - 2)
	{
		pids[var2] = pimping(argv[var], envp);
		var++;
		var2++;
	}
	dup2(outfile, 1);
	close_fds();
	return (last_process(argv[argc - 2], envp, argc - 4, pids));
}

int	last_process(char *argv, char **envp, int argc, int *pids)
{
	char	**cmd1;
	char	*path;
	int 	pid1;

	cmd1 = NULL;
	pid1 = fork();
	if (pid1 == 0)
	{
		if (!argv[0])
			error_env(cmd1);
		cmd1 = ft_split(argv, ' ', 0, 0);
		if (!cmd1)
			error();
		path = find_path(envp, cmd1[0]);
		if (path == 0)
			error_env(cmd1);
		close_fds();
		if (execve(path, cmd1, envp) == -1)
			execve_error(path, cmd1);
	}
	close_fds();
	waitpids(pids, argc);
	argc = 0;
	waitpid(pid1, &argc, 0);
	return(argc);
}

int waitpids(int *pids, int argc)
{
	int var;
	int code;

	var = 0;
	code = 0;
	while (var < argc -1)
	{
		waitpid(pids[var], NULL, 0);
		var++;
	}
	waitpid(pids[var], &code, 0);
	return (code);
}