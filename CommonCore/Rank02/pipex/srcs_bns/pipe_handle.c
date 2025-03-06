/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_handle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scorpot <scorpot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 14:40:26 by rmota-ma          #+#    #+#             */
/*   Updated: 2025/03/06 22:19:07 by scorpot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	pimping(char *cmd1, char **envp)
{
	int pid1;
	int fd[2];
	
	if (pipe(fd) == -1)
		error_exit();
	pid1 = fork();
	if (pid1 < 0)
		error_exit();
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
}

void process(char *argv, char **envp)
{
	char **cmd1;
	char *path;

	cmd1 = ft_split(argv, ' ');
	path = find_path(envp, cmd1[0]);
	if (!path || !cmd1)
	{
		if (cmd1)
			ft_free(cmd1);
		free(path);
		error_exit();
	}
	if (execve(path, cmd1, envp) == -1)
	{
		ft_free(cmd1);
		free(path);
		error_exit();
	}
	ft_free(cmd1);
	free(path);
}

void	multiple_pipes(int argc, char **argv, char **envp)
{
	int infile;
	int var;
	int outfile;

	var = 2;
	infile = open(argv[1], O_RDWR | O_CREAT, 0644);
	outfile = open(argv[argc - 1], O_RDWR | O_CREAT, 0644);
	dup2(infile, 0);
	while (var < argc - 2)
	{
		pimping(argv[var], envp);
		var++;
	}
	dup2(outfile, 1);
	process(argv[argc - 2], envp);
}