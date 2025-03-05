/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bns.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scorpot <scorpot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 14:36:34 by rmota-ma          #+#    #+#             */
/*   Updated: 2025/03/05 14:58:44 by scorpot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int	main(int argc, char **argv, char **envp)
{
	if (argc < 5)
		return(ft_printf("Bad set of args\n"), 1);
	if (ft_strncmp(argv[1], "here_doc", 8) == 0)
		here_doc(argv, envp, argc);
	else
		return (0);
	return (0);
}

void	here_doc(char **argv, char **envp, int argc)
{
	int	fd[2];
	int	pid1;
	int i = 0;

	if (argc != 6 || access(argv[5], 0) != 0)
	{
		ft_printf("Bad set of args\n");
		exit(1);
	}
	if (pipe(fd) == -1)
		error_exit();
	pid1 = fork();
	if(pid1 < 0)
		error_exit();
	if (pid1 == 0)
	{
		while(i == 0)
		{
		if (get_next_line(0) != argv[2])
			child_here_doc(argv, envp, fd);
		else
			i = 1;
		}
	}
	waitpid(pid1, NULL, 0);
}

void	child_here_doc(char **argv, char **envp, int *fd)
{
	int	infile;
	char *path;
	char **cmd1;

	
	cmd1 = ft_split(argv[3], ' ');
	infile = open(argv[5], O_RDONLY);
	path = find_path(envp, cmd1[0]);
	if (path == 0 || infile < 0)
	{
		free(path);
		close(infile);
		ft_free(cmd1);
		error_exit();
	}
	dup2(fd[1], 1);
	close(fd[0]);
	if (execve(path, cmd1, envp) == -1)
		error_exit();
	close(infile);
	free(path);
	ft_free(cmd1);
}

char *find_path(char **envp, char *cmd)
{
	char **path;
	char	*line;
	char	*temp;
	int	var;
	
	var = 0;
	while (ft_strnstr(envp[var], "PATH", 4) == 0)
		var++;
	path = ft_split(envp[var] + 5, ':');
	var = 0;
	while (envp[var] != NULL)
	{
		temp = ft_strjoin(path[var], "/");
		line = ft_strjoin(temp, cmd);
		free(temp);
		if(access(line, 0) == 0)
			return (ft_free(path), line);
		free(line);
		var++;
	}
	ft_free(path);
	return (0);
}

void	error_exit(void)
{
	perror("Error");
	exit(1);
}
