/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmota-ma <rmota-ma@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 16:34:53 by scorpot           #+#    #+#             */
/*   Updated: 2025/04/04 17:27:17 by rmota-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	philo_rout(int argc)
{
	int	var;

	var = 0;
	if (argc == 5)
	{
		while(1)
		{
			think_eat_sleep();
			if(philo()->dead == 1)
				break;
		}
	}
	else
	{
		while (var < philo()->args[4])
		{
			think_eat_sleep();
			if(philo()->dead == 1)
				break;
			var++;
		}
	}
}

void	think_eat_sleep(void)
{
	int	var;

	var = 0;
	while (var < philo()->args[0])
	{
		if (var % 2 == 0)
		{
			pthread_mutex_lock(&philo()->r_fork[var]);
			printf("timestamp_in_ms %d has taken a fork\n", var);
			pthread_mutex_lock(&philo()->r_fork[var + 1]);
			printf("timestamp_in_ms %d has taken a fork\n", var);
			pthread_create(&philo()->thread[var], NULL, eat, (void*)&var);
			pthread_mutex_unlock(&philo()->r_fork[var]);
			pthread_mutex_unlock(&philo()->r_fork[var + 1]);
			pthread_join(philo()->thread[var], NULL);
		}
		else
		{
			pthread_mutex_lock(&philo()->r_fork[var - 1]);
			printf("timestamp_in_ms %d has taken a fork\n", var);
			pthread_mutex_lock(&philo()->r_fork[var]);
			printf("timestamp_in_ms %d has taken a fork\n", var);
			pthread_create(&philo()->thread[var], NULL, eat, (void*)&var);
			pthread_mutex_unlock(&philo()->r_fork[var - 1]);
			pthread_mutex_unlock(&philo()->r_fork[var]);
			pthread_join(philo()->thread[var], NULL);
		}

		var++;
	}
}

void	init_philo(void)
{
	int	var;

	var = 0;
	philo()->thread = ft_calloc(sizeof(pthread_t), philo()->args[0]);
	philo()->r_fork = ft_calloc(sizeof(pthread_mutex_t), philo()->args[0]);
	philo()->l_fork = ft_calloc(sizeof(pthread_mutex_t), philo()->args[0]);
	philo()->dead = 0;
}

void	free_func(void)
{
	int	var;

	var = 0;
	while(var < philo()->args[0])
	{
		pthread_mutex_destroy(&philo()->r_fork[var]);
		pthread_mutex_destroy(&philo()->l_fork[var]);
		var++;
	}
	free(philo()->thread);
	free(philo()->l_fork);
	free(philo()->r_fork);
	free(philo()->args); 
}