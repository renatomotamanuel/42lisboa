/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmota-ma <rmota-ma@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 12:49:46 by rmota-ma          #+#    #+#             */
/*   Updated: 2025/03/24 16:36:12 by rmota-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int	main(int argc, char **argv, char **envp)
{
	int	fd[2];
	int	pid1;
	int	pid2;
	int	code;

	code = 0;
	if (argc != 5)
		return (ft_printf("Bad set of args"), 1);
	if (pipe(fd) == -1)
		error();
	pid1 = fork();
	if (pid1 < 0)
		error();
	if (pid1 == 0)
		child_process(argv, envp, fd);
	pid2 = fork();
	if (pid2 == 0)
		child_process_2(argv, envp, fd);
	close_fds();
	waitpid(pid1, NULL, 0);
	waitpid(pid2, &code, 0);
	return (code / 256);
}

void	child_process(char **argv, char **envp, int *fd)
{
	int		infile;
	char	*path;
	char	**cmd1;

	cmd1 = NULL;
	if (!argv[2][0])
		error_env(cmd1);
	infile = open(argv[1], O_RDWR);
	if (infile < 0)
		error();
	cmd1 = ft_split(argv[2], ' ', 0, 0);
	if (!cmd1)
		error();
	path = find_path(envp, cmd1[0]);
	dup2(fd[1], 1);
	dup2(infile, 0);
	close_fds();
	if (execve(path, cmd1, envp) == -1)
		execve_error(path, cmd1);
}

void	child_process_2(char **argv, char **envp, int *fd)
{
	int		outfile;
	char	*path;
	char	**cmd1;

	cmd1 = NULL;
	if (!argv[3][0])
		error_env(cmd1);
	outfile = open(argv[4], O_RDWR | O_TRUNC | O_CREAT, 0644);
	if (outfile < 0)
		error();
	cmd1 = ft_split(argv[3], ' ', 0, 0);
	if (!cmd1)
		error();
	path = find_path(envp, cmd1[0]);
	dup2(fd[0], 0);
	dup2(outfile, 1);
	close_fds();
	if (execve(path, cmd1, envp) == -1)
		execve_error(path, cmd1);
}

char	*find_path(char **envp, char *cmd)
{
	char	**path;
	char	*line;
	char	*temp;
	int		var;

	var = 0;
	while (ft_strnstr(envp[var], "PATH", 4) == 0 && envp[var + 1])
		var++;
	if (!envp[var + 1])
		return (cmd);
	path = ft_split(envp[var] + 5, ':', 0, 0);
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
	return (ft_free(path), cmd);
}

int	check_plica(char *s)
{
	int	check;
	int	var;

	var = 0;
	check = 0;
	while (s[var])
	{
		if (s[var] == 39)
			check++;
		var++;
	}
	if (check == 2)
		return (0);
	else
		return (1);
}
