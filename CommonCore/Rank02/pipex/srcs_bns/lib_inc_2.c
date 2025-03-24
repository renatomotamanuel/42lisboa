/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_inc_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmota-ma <rmota-ma@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 19:37:22 by scorpot           #+#    #+#             */
/*   Updated: 2025/03/24 16:41:15 by rmota-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	a;

	a = 0;
	while ((a < n) && (s1[a]) && (s2[a]))
	{
		if (s1[a] != s2[a])
		{
			return ((unsigned char)s1[a] - (unsigned char)s2[a]);
		}
		a++;
	}
	if (a < n)
	{
		return ((unsigned char)s1[a] - (unsigned char)s2[a]);
	}
	return (0);
}

void	last_process(char **argv, char **envp, int argc, int perm)
{
	char	**cmd1;
	char	*path;
	int		outfile;

	if (!argv[argc -2][0])
	{
		perror("Error");
		close_fds();
		exit(126);
	}
	if (perm == 0)
		outfile = open(argv[argc - 1], O_RDWR | O_APPEND | O_CREAT, 0644);
	else
		outfile = open(argv[argc - 1], O_RDWR | O_TRUNC | O_CREAT, 0644);
	if (outfile < 0)
		error();
	cmd1 = ft_split(argv[argc - 2], ' ', 0, 0);
	if (!cmd1)
		error();
	path = find_path(envp, cmd1[0]);
	dup2(outfile, 1);
	close_fds();
	if (execve(path, cmd1, envp) == -1)
		execve_error(path, cmd1);
}
