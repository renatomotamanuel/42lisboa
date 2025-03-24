/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bns.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmota-ma <rmota-ma@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 14:36:34 by rmota-ma          #+#    #+#             */
/*   Updated: 2025/03/24 16:39:49 by rmota-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int	main(int argc, char **argv, char **envp)
{
	int	cmds;
	int	code;
	int	*pids;

	code = 0;
	if (argc < 5)
		return (ft_printf("Bad set of args\n"), 1);
	if (ft_strncmp(argv[1], "here_doc", 9) == 0)
	{
		cmds = argc -4;
		if (argc < 6)
			return (ft_printf("Bad set of args\n"), 1);
		pids = ft_calloc(cmds, sizeof(int));
		code = here_doc(argv, envp, cmds, pids);
	}
	else
	{
		pids = ft_calloc(argc - 4, sizeof(int));
		code = multiple_pipes(argc, argv, envp, pids);
	}
	if (pids)
		free(pids);
	return (code / 256);
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

void	cut_word(char *s, size_t *var)
{
	*var += 1;
	while (s[*var] != 39)
		*var += 1;
}
