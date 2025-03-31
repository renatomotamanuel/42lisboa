/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmota-ma <rmota-ma@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 14:32:02 by rmota-ma          #+#    #+#             */
/*   Updated: 2025/03/31 15:03:19 by rmota-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	main(int argc, char **argv, char **envp)
{
	long	*args;
	int	var;
	
	var = 0;
	if (!(argc == 5 || argc == 6))
		return (printf("Bad set of args"), 1);
	if (error_syntax(argv, 0) != 0)
		return (printf("Bad set of args"), 1);
	args = ft_calloc(sizeof(long), argc - 2);
	while (var < argc - 1)
	{
		args[var] = ft_atol(argv[var + 1]);
		if (args[var] > INT_MAX)
			return (printf("Bad set of args"), 1);
		var++;
	}
	var = 0;
	while (var < argc -1)
	{
		printf("%ld\n", args[var]);
		var++;
	}
	(void)argv;
	(void)argc;
	(void)envp;
	return (0);
}

int	error_syntax(char **argv, int var)
{
	int	i;

	i = 1;
	while (argv[i] != NULL)
	{
		var = 0;
		if (argv[i][var] == '\0')
			return (1);
		while (argv[i][var] != '\0')
		{
			if ((argv[i][var] >= '0' && argv[i][var] <= '9') ||
					(argv[i][var] == '-' || argv[i][var] == '+'))
			{
				if ((argv[i][var] == '-' || argv[i][var] == '+') &&
					((argv[i][var + 1] < '0' || argv[i][var] > '9') ||
						(var != '\0')))
					return (1);
			}
			else
				return (1);
			var++;
		}
		i++;
	}
	return (0);
}
