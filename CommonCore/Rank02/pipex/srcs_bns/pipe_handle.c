/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_handle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmota-ma <rmota-ma@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 14:40:26 by rmota-ma          #+#    #+#             */
/*   Updated: 2025/03/06 17:33:49 by rmota-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	define_fds(int **fd, int cmds)
{
	int var;

	var = 0;
	while (var < cmds)
	{
		fd[var] = ft_calloc(sizeof(int), 2);
		var++;
	}
}

void multiple_pipes(char **argv, char **envp, int **fd, int cmds)
{
	int	var;
	char *path;
	char **cmd1;
	int pid1;

	var = 0;
	while (var < cmds -1)
	{
		if (pipe(fd[var]) == -1)
			error_exit();
		pid1 = fork();
		if (pid1 == 0)
		{
			cmd1 = ft_split(argv[var], ' ');
			path = find_path(envp, cmd1[0]);
			if (!path || !cmd1)
			{
				if (cmd1)
					ft_free(cmd1);
				error_exit();
			}
			dup2(fd[var][0], 0);
			dup2(fd[var + 1][1], 1);
			close(fd[var][1]);
			close(fd[var + 1][0]);
			if (execve(path, cmd1, envp) == -1)
				error_exit();
			free(path);
			ft_free(cmd1);
		}
		/* close(fd[var][1]);
		close(fd[var][0]);
		close(fd[var + 1][1]);
		close(fd[var + 1][0]); */
		var++;
	}
}
