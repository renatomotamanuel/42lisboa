/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmota-ma <rmota-ma@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 11:00:19 by rmota-ma          #+#    #+#             */
/*   Updated: 2025/04/17 18:14:40 by rmota-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	init_philo(void)
{
	int	var;
	int	check;
	
	var = 0;
	prog()->philo = ft_calloc(sizeof(t_philo), prog()->args[0]);
	prog()->stop = 0;
	pthread_mutex_init(&prog()->death, NULL);
	while(var < prog()->args[0])
	{
		prog()->philo[var].eat_counter = 0;
		prog()->philo[var].id = var;
		prog()->philo[var].dead = 0;
		pthread_mutex_init(&prog()->philo[var].fork, NULL);
		pthread_mutex_init(&prog()->philo[var].finish, NULL);
		var++;
	}
	var = 0;
	gettimeofday(&prog()->start, NULL);
	while (var < prog()->args[0])
	{
		pthread_create(&prog()->philo[var].thread, NULL, philo_rout, (void*)&prog()->philo[var].id);
		var++;
	}
	pthread_mutex_lock(&prog()->death);
	prog()->done = 1;
	pthread_mutex_unlock(&prog()->death);
	while(1)
	{
		check = 0;
		var = 0;
		while (var < prog()->args[0])
		{
			pthread_mutex_lock(&prog()->philo[var].finish);
			if (prog()->philo[var].dead == 1)
				check++;
			pthread_mutex_unlock(&prog()->philo[var].finish);
			var++;
		}
		if (check == prog()->args[0])
			break ;
	}
}

void	*philo_rout(void *id)
{
	int	var;

	var = 2;
	while (1)
	{
		pthread_mutex_lock(&prog()->death);
		if (prog()->done == 1)
			break ;
		pthread_mutex_unlock(&prog()->death);
	}
	pthread_mutex_unlock(&prog()->death);
	while(1)
	{
		if (*(int*)id % 2 == 0)
		{
			think_eat_sleep(*(int*)id);
			pthread_mutex_lock(&prog()->death);
			if(prog()->stop == 1 || (prog()->philo[*(int*)id].eat_counter == prog()->args[4] && prog()->argc == 6))
			{
				pthread_mutex_lock(&prog()->philo[*(int*)id].finish);
				prog()->philo[*(int*)id].dead = 1;
				pthread_mutex_unlock(&prog()->philo[*(int*)id].finish);
				break ;
			}
			pthread_mutex_unlock(&prog()->death);
		}
		else
		{
			if (var == 2)
				usleep(prog()->args[2] * 1000);
			var = 0;
			think_eat_sleep((*(int*)id));
			pthread_mutex_lock(&prog()->death);
			if (prog()->stop == 1 || (prog()->philo[*(int*)id].eat_counter == prog()->args[4] && prog()->argc == 6))
			{
				pthread_mutex_lock(&prog()->philo[*(int*)id].finish);
				prog()->philo[*(int*)id].dead = 1;
				pthread_mutex_unlock(&prog()->philo[*(int*)id].finish);
				pthread_mutex_unlock(&prog()->death);
				break ;
			}
			pthread_mutex_unlock(&prog()->death);
		}
	}
	return (0);
}

void	think_eat_sleep(int id)
{
	gettimeofday(&prog()->philo[id].cycle_start, NULL);
	if (id % 2 == 0)
		eat_even(id);
	else
		eat_odd(id);
	philo_sleep(id);
}

void	free_func(void)
{
	int	var;

	var = 0;
	while (var < prog()->args[0])
	{
		pthread_join(prog()->philo[var].thread, NULL);
		var++;
	}
	var = 0;
	while(var < prog()->args[0])
	{
		pthread_mutex_destroy(&prog()->philo[var].fork);
		pthread_mutex_destroy(&prog()->philo[var].finish);
		var++;
	}
	pthread_mutex_destroy(&prog()->death);
	free(prog()->philo);
	free(prog()->args);
}
