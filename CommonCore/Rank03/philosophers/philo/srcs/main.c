/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmota-ma <rmota-ma@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 10:58:29 by rmota-ma          #+#    #+#             */
/*   Updated: 2025/04/17 11:00:16 by rmota-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	main(int argc, char **argv)
{
	int	var;
	
	var = 0;
	prog()->argc = argc;
	if (!(prog()->argc == 5 || prog()->argc == 6))
		return (printf("Bad set of args"), 1);
	if (error_syntax(argv, 0) != 0)
		return (printf("Bad set of args"), 1);
	prog()->args = ft_calloc(sizeof(long), argc - 1);
	while (var < argc - 1)
	{
		prog()->args[var] = ft_atol(argv[var + 1]);
		if ((prog()->args[var] > INT_MAX || prog()->args[var] < 0) || prog()->args[0] < 1)
			return (free(prog()->args), printf("Bad set of args"), 1);
		var++;
	}
	/* if (prog()->args[0] == 1)
		lone_philo(); */
	init_philo();
	free_func();
	return (0);
}
