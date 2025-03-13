/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doc_handle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmota-ma <rmota-ma@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 14:37:27 by rmota-ma          #+#    #+#             */
/*   Updated: 2025/03/13 13:01:42 by rmota-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	here_doc(char **argv, int cmds)
{
	int	fd[2];
	int	pid1;

	if (pipe(fd) == -1)
		error_exit();
	pid1 = fork();
	if (pid1 < 0)
		error_exit();
	if (pid1 == 0)
	{
		close(fd[0]);
		loop(argv, cmds, fd[1]);
	}
	else
	{
		close(fd[1]);
		dup2(fd[0], 0);
		wait(NULL);
	}
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

void	here_doc_pipe(char **argv, int argc, char **envp)
{
	int	var;
	int	outfile;

	var = 3;
	outfile = open(argv[argc - 1], O_RDWR | O_CREAT, 0644);
	if (outfile < 0)
		error_exit();
	while (var < argc - 2)
	{
		pimping(argv[var], envp);
		var++;
	}
	dup2(outfile, 1);
	process(argv[argc - 2], envp, -1);
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
