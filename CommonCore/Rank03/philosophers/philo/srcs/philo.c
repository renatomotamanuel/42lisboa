/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmota-ma <rmota-ma@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 15:56:03 by rmota-ma          #+#    #+#             */
/*   Updated: 2025/04/23 18:01:12 by rmota-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	init_philo(void)
{
	int	var;

	var = 0;
	prog()->philo = ft_calloc(sizeof(t_philo), prog()->args[0]);
	prog()->stop = 0;
	prog()->meal = 0;
	pthread_mutex_init(&prog()->death, NULL);
	pthread_mutex_init(&prog()->eat_lock, NULL);
	while (var < prog()->args[0])
	{
		prog()->philo[var].eat_counter = 0;
		prog()->philo[var].id = var;
		prog()->philo[var].dead = 0;
		prog()->philo[var].stop = 0;
		pthread_mutex_init(&prog()->philo[var].fork, NULL);
		var++;
	}
	if (prog()->args[0] == 1)
		pthread_create(&prog()->philo[0].thread, NULL, lone_philo,
			(void *)&prog()->philo[0].id);
	else
		multiple_philos();
	free_func();
}

void	multiple_philos(void)
{
	int	var;

	var = 0;
	gettimeofday(&prog()->start, NULL);
	while (var < prog()->args[0])
	{
		pthread_create(&prog()->philo[var].thread, NULL, philo_rout,
			(void *)&prog()->philo[var].id);
		var++;
	}
}

void	*philo_rout(void *id)
{
	int	var;

	var = 2;
	while (1)
	{
		if (*(int *)id % 2 == 0 && var == 2)
			usleep(prog()->args[2] * 1000);
		else if (*(int *)id % 2 == 0)
			usleep(500);
		var = 0;
		think_eat_sleep(*(int *)id);
		pthread_mutex_lock(&prog()->death);
		if (prog()->stop == 1)
			break ;
		pthread_mutex_unlock(&prog()->death);
	}
	pthread_mutex_unlock(&prog()->death);
	return (0);
}

void	think_eat_sleep(int id)
{
	if (id % 2 == 0)
		eat_even(id);
	else
		eat_odd(id);
	pthread_mutex_lock(&prog()->eat_lock);
	if (prog()->philo[id].dead == 1 || (prog()->meal
			== prog()->args[0] && prog()->argc == 6))
	{
		pthread_mutex_unlock(&prog()->eat_lock);
		return ;
	}
	pthread_mutex_unlock(&prog()->eat_lock);
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
	while (var < prog()->args[0])
	{
		pthread_mutex_destroy(&prog()->philo[var].fork);
		var++;
	}
	pthread_mutex_destroy(&prog()->death);
	pthread_mutex_destroy(&prog()->eat_lock);
	free(prog()->philo);
	free(prog()->args);
}
