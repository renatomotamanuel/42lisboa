/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_handle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmota-ma <rmota-ma@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 14:40:26 by rmota-ma          #+#    #+#             */
/*   Updated: 2025/03/19 16:55:17 by rmota-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int	multiple_pipes(int argc, char **argv, char **envp, int *pids)
{
	int	infile;
	int code;

	code = 0;
	infile = open(argv[1], O_RDWR);
	if (infile < 0)
		perror("Error");
	if (infile != -1)
		dup2(infile, 0);
	else
	{
		infile = open(".failsafe", O_RDWR | O_CREAT, 0644);
		dup2(infile, 0);
		unlink(".failsafe");
		close_fds();
	}
	code = parent(argc, argv, envp, pids);
	return (code);
}

int parent(int argc, char **argv, char **envp, int *pids)
{
	int	var;
	int	var2;
	int	pid1;
	
	var = 2;
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
		last_process(argv, envp, argc);
	}
	var2 = 0;
	close_fds();
	waitpids(pids, argc - 4);
	waitpid(pid1, &var2, 0);
	return (var2);
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
	{
		perror("Error");
		close_fds();
		exit(126);
	}
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

void	last_process(char **argv, char **envp, int argc)
{
	char	**cmd1;
	char	*path;
	int		outfile;

	cmd1 = NULL;
	if (!argv[argc -2][0])
	{
		perror("Error");
		close_fds();
		exit(126);
	}
	outfile = open(argv[argc - 1], O_RDWR | O_CREAT, 0644);
	if (outfile < 0)
		error();
	cmd1 = ft_split(argv[argc - 2], ' ', 0, 0);
	if (!cmd1)
		error();
	path = find_path(envp, cmd1[0]);
	if (path == 0)
		error_env(cmd1);
	dup2(outfile, 1);
	close_fds();
	if (execve(path, cmd1, envp) == -1)
		execve_error(path, cmd1);
}

void waitpids(int *pids, int argc)
{
	int var;
	
	var = 0;
	while (var < argc)
	{
		waitpid(pids[var], NULL, 0);
		var++;
	}
}