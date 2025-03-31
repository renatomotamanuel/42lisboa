/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scorpot <scorpot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 14:32:02 by rmota-ma          #+#    #+#             */
/*   Updated: 2025/03/31 23:12:50 by scorpot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	main(int argc, char **argv, char **envp)
{
	int	var;
	
	var = 0;
	if (!(argc == 5 || argc == 6))
		return (printf("Bad set of args"), 1);
	if (error_syntax(argv, 0) != 0)
		return (printf("Bad set of args"), 1);
	philo()->args = ft_calloc(sizeof(long), argc - 2);
	while (var < argc - 1)
	{
		philo()->args[var] = ft_atol(argv[var + 1]);
		if (philo()->args[var] > INT_MAX || philo()->args[var] < 0)
			return (free(philo()->args), printf("Bad set of args"), 1);
		var++;
	}
	(void)argv;
	(void)argc;
	(void)envp;
	return (free(philo()->args), 0);
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
