/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmota-ma <rmota-ma@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 14:36:34 by rmota-ma          #+#    #+#             */
/*   Updated: 2025/02/21 18:06:21 by rmota-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int	main(int argc, char **argv)
{
	int pid;
	int fd[2];
	char buffer[13];
	(void)argc;
	//(void)argv;
	if(pipe(fd) == -1)
		return (1);
	
	pid = fork();
	if(pid == -1)
		return (1);
	fd[0] = open(argv[1], O_RDWR);
	if (pid == 0)
	{
		close(fd[0]);
		write(fd[1], "Hello World", 11);
		close(fd[1]);
		return (0);
	}
	else
	{
		close(fd[1]);
		read(fd[0], buffer, 13);
		close(fd[0]);
		printf("Hello world222 %s\n", buffer);
		return (0);
	}
	return (0);
}