/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmota-ma <rmota-ma@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 14:36:34 by rmota-ma          #+#    #+#             */
/*   Updated: 2025/03/13 11:55:14 by rmota-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int	main(int argc, char **argv, char **envp)
{
	int	fd[2];
	int	pid1;

	if (argc != 5)
		return (ft_printf("Bad set of args"), 1);
	if (pipe(fd) == -1)
		return (ft_printf("Bad pipe"), 1);
	pid1 = fork();
	if (pid1 < 0)
		return (ft_printf("Bad fork"), 1);
	if (pid1 == 0)
		child_process(argv, envp, fd);
	else
		child_process_2(argv, envp, fd);
	close(fd[0]);
	close(fd[1]);
	waitpid(pid1, NULL, 0);
	return (0);
}

void	child_process(char **argv, char **envp, int *fd)
{
	int		infile;
	char	*path;
	char	**cmd1;

	cmd1 = ft_split(argv[2], ' ');
	infile = open(argv[1], O_RDWR);
	if (infile < 0)
		error_file(-1, infile);
	path = find_path(envp, cmd1[0]);
	if (path == 0)
	{
		close(infile);
		error_env(cmd1);
	}
	dup2(fd[1], 1);
	dup2(infile, 0);
	close(fd[0]);
	if (execve(path, cmd1, envp) == -1)
		error_exit();
	close(infile);
	free(path);
	ft_free(cmd1);
}

void	child_process_2(char **argv, char **envp, int *fd)
{
	int		outfile;
	char	*path;
	char	**cmd1;

	outfile = open(argv[4], O_RDWR | O_CREAT, 0644);
	if (outfile < 0)
		error_file(-1, outfile);
	cmd1 = ft_split(argv[3], ' ');
	path = find_path(envp, cmd1[0]);
	if (path == 0)
	{
		close(outfile);
		error_env(cmd1);
	}
	dup2(fd[0], 0);
	dup2(outfile, 1);
	close(fd[1]);
	if (execve(path, cmd1, envp) == -1)
		error_exit();
	close(outfile);
	free(path);
	ft_free(cmd1);
}

char	*find_path(char **envp, char *cmd)
{
	char	**path;
	char	*line;
	char	*temp;
	int		var;

	var = 0;
	if (access(cmd, 0) == 0)
		return (cmd);
	while (ft_strnstr(envp[var], "PATH", 4) == 0 && envp[var + 1])
		var++;
	if (!envp[var + 1])
		return (0);
	path = ft_split(envp[var] + 5, ':');
	var = 0;
	while (path[var] != NULL)
	{
		temp = ft_strjoin(path[var], "/");
		line = ft_strjoin(temp, cmd);
		free(temp);
		if (access(line, 0) == 0)
			return (ft_free(path), line);
		free(line);
		var++;
	}
	return (ft_free(path), NULL);
}
