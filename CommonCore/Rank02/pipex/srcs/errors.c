/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmota-ma <rmota-ma@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 12:50:29 by rmota-ma          #+#    #+#             */
/*   Updated: 2025/03/19 11:50:51 by rmota-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	error(void)
{
	perror("Error");
	close_fds();
	exit(1);
}

void	error_env(char **cmd1)
{
	perror("Error");
	if (cmd1)
		ft_free(cmd1);
	close_fds();
	exit(127);
}

void	execve_error(char *path, char **cmd1)
{
	perror("Error");
	if (path)
		free(path);
	if (cmd1)
		ft_free(cmd1);
	close_fds();
	exit(1);
}

void	close_fds(void)
{
	int	var;

	var = 3;
	while (var < 1024)
	{
		close(var);
		var++;
	}
}
