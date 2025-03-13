/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmota-ma <rmota-ma@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 12:29:34 by rmota-ma          #+#    #+#             */
/*   Updated: 2025/03/13 15:31:41 by rmota-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

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
		close(fd);
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
