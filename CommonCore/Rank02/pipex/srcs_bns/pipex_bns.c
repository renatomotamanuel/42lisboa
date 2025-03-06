/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bns.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scorpot <scorpot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 14:36:34 by rmota-ma          #+#    #+#             */
/*   Updated: 2025/03/06 22:21:10 by scorpot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int	main(int argc, char **argv, char **envp)
{
	int cmds;
	
	if (argc < 5)
		return(ft_printf("Bad set of args\n"), 1);
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

char *find_path(char **envp, char *cmd)
{
	char **path;
	char	*line;
	char	*temp;
	int	var;
	
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
		if(access(line, 0) == 0)
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
	exit(1);
}
