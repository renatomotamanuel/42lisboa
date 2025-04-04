/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmota-ma <rmota-ma@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 14:32:02 by rmota-ma          #+#    #+#             */
/*   Updated: 2025/04/04 15:14:58 by rmota-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"
# include <unistd.h>

int	main(int argc, char **argv)
{
	int	var;
	
	var = 0;
	if (!(argc == 5 || argc == 6))
		return (printf("Bad set of args"), 1);
	if (error_syntax(argv, 0) != 0)
		return (printf("Bad set of args"), 1);
	philo()->args = ft_calloc(sizeof(long), argc - 1);
	while (var < argc - 1)
	{
		philo()->args[var] = ft_atol(argv[var + 1]);
		if ((philo()->args[var] > INT_MAX || philo()->args[var] < 0) || philo()->args[0] < 1)
			return (free(philo()->args), printf("Bad set of args"), 1);
		var++;
	}
	init_philo();
	philo_rout(argc);
	free_func();
	return (0);
}

