/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_handle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmota-ma <rmota-ma@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 14:40:26 by rmota-ma          #+#    #+#             */
/*   Updated: 2025/03/13 15:32:31 by rmota-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	pimping(char *cmd1, char **envp)
{
	int	pid1;
	int	fd[2];

	if (pipe(fd) == -1)
		error_exit();
	pid1 = fork();
	if (pid1 < 0)
		error_exit();
	if (pid1 == 0)
	{
		close(fd[0]);
		dup2(fd[1], 1);
		process(cmd1, envp, fd[1]);
	}
	else
	{
		close(fd[1]);
		dup2(fd[0], 0);
	}
	close(fd[0]);
	close(fd[1]);
}

void	process(char *argv, char **envp, int fd)
{
	char	**cmd1;
	char	*path;

	cmd1 = ft_split(argv, ' ');
	path = find_path(envp, cmd1[0]);
	if (path == 0)
	{
		if (fd != -1)
			close(fd);
		error_env(cmd1);
	}
	if (execve(path, cmd1, envp) == -1)
		error_exit();
	ft_free(cmd1);
	free(path);
}

void	multiple_pipes(int argc, char **argv, char **envp)
{
	int	infile;
	int	var;
	int	outfile;

	var = 2;
	infile = open(argv[1], O_RDWR);
	if (infile < 0)
	{
		perror("Error");
		var = -1;
	}
	outfile = open(argv[argc - 1], O_RDWR | O_CREAT, 0644);
	if (outfile < 0 || var == -1)
		error_file(infile, outfile);
	dup2(infile, 0);
	while (var < argc - 2)
	{
		pimping(argv[var], envp);
		var++;
	}
	close(infile);
	dup2(outfile, 1);
	last_process(argv[argc - 2], envp, outfile);
	close(outfile);
}

void	last_process(char *argv, char **envp, int outfile)
{
	char	**cmd1;
	char	*path;

	cmd1 = ft_split(argv, ' ');
	path = find_path(envp, cmd1[0]);
	if (path == 0)
	{
		perror("Error");
		if (cmd1)
			ft_free(cmd1);
		close(outfile);
		exit(127);
	}
	if (execve(path, cmd1, envp) == -1)
		error_exit();
	ft_free(cmd1);
	free(path);
}

void	close_fds(void)
{
	int	var;

	var = 3;
	while (var < 1024)
	{
		close(var);
		var++;
	}
}
