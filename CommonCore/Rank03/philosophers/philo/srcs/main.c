/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scorpot <scorpot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 14:32:02 by rmota-ma          #+#    #+#             */
/*   Updated: 2025/04/01 16:33:56 by scorpot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	main(int argc, char **argv)
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
		if ((philo()->args[var] > INT_MAX || philo()->args[var] < 0) || philo()->args[0] < 1)
			return (free(philo()->args), printf("Bad set of args"), 1);
		var++;
	}
	philo_rout(argc);
	return (free(philo()->args), 0);
}

