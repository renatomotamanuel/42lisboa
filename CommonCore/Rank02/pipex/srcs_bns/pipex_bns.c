/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bns.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmota-ma <rmota-ma@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 14:36:34 by rmota-ma          #+#    #+#             */
/*   Updated: 2025/03/13 15:31:11 by rmota-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int	main(int argc, char **argv, char **envp)
{
	int	cmds;

	if (argc < 5)
		return (ft_printf("Bad set of args\n"), 1);
	if (ft_strncmp(argv[1], "here_doc", 9) == 0)
	{
		cmds = argc -4;
		if (argc < 6)
		{
			ft_printf("Bad set of args\n");
			exit(1);
		}
		here_doc(argv, cmds);
		here_doc_pipe(argv, argc, envp);
	}
	else
	{
		cmds = argc - 3;
		multiple_pipes(argc, argv, envp);
	}
	return (0);
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
	while (ft_strnstr(envp[var], "PATH", 4) == 0)
		var++;
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
	if (path)
		ft_free(path);
	return (NULL);
}

void	error_exit(void)
{
	perror("Error");
	close_fds();
	exit(1);
}

void	error_env(char **cmd1)
{
	perror("Error");
	ft_free(cmd1);
	close_fds();
	exit(127);
}

void	error_file(int fd, int fd2)
{
	perror("Error");
	if (fd != -1)
		close(fd);
	if (fd2 != -1)
		close(fd2);
	close_fds();
	exit(1);
}
