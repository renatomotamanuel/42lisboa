/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmota-ma <rmota-ma@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 15:56:01 by rmota-ma          #+#    #+#             */
/*   Updated: 2025/04/23 14:27:11 by rmota-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	eat_even(int id)
{
	fork_left(id);
	fork_right(id);
	eating(id);
	if (id == prog()->args[0] - 1)
		pthread_mutex_unlock(&prog()->philo[0].fork);
	else
		pthread_mutex_unlock(&prog()->philo[id + 1].fork);
	pthread_mutex_unlock(&prog()->philo[id].fork);
}

void	eat_odd(int id)
{
	fork_right(id);
	fork_left(id);
	eating(id);
	pthread_mutex_unlock(&prog()->philo[id].fork);
	if (id == prog()->args[0] - 1)
		pthread_mutex_unlock(&prog()->philo[0].fork);
	else
		pthread_mutex_unlock(&prog()->philo[id + 1].fork);
}

void	philo_sleep(int id)
{
	pthread_mutex_lock(&prog()->death);
	if(prog()->stop == 0)
	{
		gettimeofday(&prog()->philo[id].current, NULL);
		printf("%ld %d is sleeping\n",(prog()->philo[id].current.tv_sec - prog()->start.tv_sec) * 1000 + (prog()->philo[id].current.tv_usec - prog()->start.tv_usec) / 1000, id + 1);
	}
	pthread_mutex_unlock(&prog()->death);
	death_checker(id, prog()->args[3], 0);
	pthread_mutex_lock(&prog()->death);
	if(prog()->stop == 0)
	{
		gettimeofday(&prog()->philo[id].current, NULL);
		printf("%ld %d is thinking\n",(prog()->philo[id].current.tv_sec - prog()->start.tv_sec) * 1000 + (prog()->philo[id].current.tv_usec - prog()->start.tv_usec) / 1000, id + 1);
	}
	pthread_mutex_unlock(&prog()->death);
	}

void	death_checker(int id, int sleep_time, long diff)
{
	diff = 0;
	gettimeofday(&prog()->philo[id].current, NULL);
	if (((prog()->philo[id].current.tv_sec - prog()->philo[id].cycle_start.tv_sec) * 1000 + (prog()->philo[id].current.tv_usec - prog()->philo[id].cycle_start.tv_usec) / 1000) + sleep_time >= prog()->args[1])
	{
		prog()->philo[id].dead = 1;
		diff = (((prog()->philo[id].current.tv_sec - prog()->philo[id].cycle_start.tv_sec) * 1000 + (prog()->philo[id].current.tv_usec - prog()->philo[id].cycle_start.tv_usec) / 1000) + sleep_time) - prog()->args[1];
		pthread_mutex_lock(&prog()->death);
		if(prog()->stop == 0)
		{
			pthread_mutex_unlock(&prog()->death);
			usleep((sleep_time - diff) * 1000);
			pthread_mutex_lock(&prog()->death);
		}
		pthread_mutex_unlock(&prog()->death);
		pthread_mutex_lock(&prog()->death);
		if(prog()->stop == 0)
		{
			prog()->stop = 1;
			gettimeofday(&prog()->philo[id].current, NULL);
			printf("%ld %d died\n",(prog()->philo[id].current.tv_sec - prog()->start.tv_sec) * 1000 + (prog()->philo[id].current.tv_usec - prog()->start.tv_usec) / 1000, id + 1);
		}
		pthread_mutex_unlock(&prog()->death);
	}
	else
		usleep(sleep_time * 1000);
}
