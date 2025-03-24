/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doc_handle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmota-ma <rmota-ma@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 14:37:27 by rmota-ma          #+#    #+#             */
/*   Updated: 2025/03/24 16:39:11 by rmota-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int	here_doc(char **argv, char**envp, int argc, int *pids)
{
	int	fd[2];
	int	pid1;

	if (pipe(fd) == -1)
		error();
	pid1 = fork();
	if (pid1 < 0)
		error();
	if (pid1 == 0)
	{
		close(fd[0]);
		free(pids);
		loop(argv, argc, fd[1]);
	}
	else
	{
		close(fd[1]);
		dup2(fd[0], 0);
		wait(NULL);
	}
	close_fds();
	return (here_doc_pipe(argv, argc + 4, envp, pids));
}

int	here_doc_pipe(char **argv, int argc, char **envp, int *pids)
{
	int	pid1;
	int	var;
	int	var2;

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
		last_process(argv, envp, argc, 0);
	}
	var2 = 0;
	close_fds();
	waitpids(pids, argc - 5);
	waitpid(pid1, &var2, 0);
	return (var2);
}

void	loop(char **argv, int cmds, int infile)
{
	int		len;
	int		i;
	char	*line;

	i = 0;
	len = ft_strlen(argv[2]);
	print_pipe(cmds);
	while (i == 0)
	{
		line = get_next_line(0);
		if (ft_strncmp(line, argv[2], len) == 0 && line[len] == '\n')
		{
			free(line);
			close(infile);
			exit(0);
		}
		print_pipe(cmds);
		write(infile, line, ft_strlen(line));
		free(line);
	}
}

void	print_pipe(int cmds)
{
	int	var;

	var = 1;
	while (var < cmds)
	{
		ft_printf("pipe ");
		var++;
	}
	ft_printf("heredoc>");
}
