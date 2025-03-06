/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doc_handle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmota-ma <rmota-ma@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 14:37:27 by rmota-ma          #+#    #+#             */
/*   Updated: 2025/03/06 17:29:38 by rmota-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	here_doc(char **argv, char **envp, int cmds)
{
	int i;
	char *line;
	int len;
	int infile;

	i = 0;
	len = ft_strlen(argv[2]);
	infile = open(".heredoc_temp", O_RDWR | O_CREAT, 0644);
	print_pipe(cmds);
	while(i == 0)
	{
		line = get_next_line(0);
		if (ft_strncmp(line, argv[2], len) == 0 && line[len] == '\n')
			i = 1;
		else
		{
			print_pipe(cmds);
			write(infile, line, ft_strlen(line));
		}
		free(line);
	}
	here_doc_pipe(argv, envp, infile, cmds);
	close(infile);
	unlink(".heredoc_temp");
}

int	here_doc_pipe(char **argv, char **envp, int infile, int cmds)
{
	int	**fd;
	int	pid1;
	
	fd = ft_calloc(sizeof(int *), cmds);
	fd[0] = ft_calloc(sizeof(int), 2);
	if (pipe(fd[0]) == -1)
		return(ft_printf("Bad pipe"), 1);
	pid1 = fork();
	if (pid1 < 0)
		return(ft_printf("Bad fork"), 1);
	if (pid1 == 0)
		child_here_doc(argv, envp, fd[0], infile);
	else
	{
		cmds--;
		define_fds(&fd[1], cmds);
		multiple_pipes(&argv[4], envp, fd, cmds);
		last_doc(fd, argv, envp, cmds);
		//close_fds(fd);
	}
	waitpid(pid1, NULL, 0);
	return (0);
}

void	last_doc(int **fd, char **argv, char **envp, int cmds)
{
	int	outfile;
	char *path;
	char **cmd1;

	cmd1 = ft_split(argv[cmds + 3], ' ');
	path = find_path(envp, cmd1[0]);
	if (path == 0)
	{
		ft_free(cmd1);
		error_exit();
	}
	outfile = open(argv[cmds + 4], O_WRONLY | O_CREAT, 0644);
	dup2(fd[cmds + 2][0], 0);
	dup2(outfile, 1);
	close(fd[cmds + 2][1]);
	if (execve(path, cmd1, envp) == -1)
		error_exit();
	close(outfile);
	free(path);
	ft_free(cmd1);
}

void	child_here_doc(char **argv, char **envp, int *fd, int infile)
{
	char *path;
	char **cmd1;
	
	cmd1 = ft_split(argv[3], ' ');
	path = find_path(envp, cmd1[0]);
	if (!path || !cmd1)
	{
		if (cmd1)
			ft_free(cmd1);
		error_exit();
	}
	dup2(fd[1], 1);
	dup2(infile, 0);
	close(fd[0]);
	if (execve(path, cmd1, envp) == -1)
		error_exit();
	free(path);
	ft_free(cmd1);
}

void print_pipe(int cmds)
{
	int var;

	var = 1;
	while (var < cmds)
	{
		ft_printf("pipe ");
		var++;
	}
	ft_printf("heredoc>");
}
