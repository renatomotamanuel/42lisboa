/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prints.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmota-ma <rmota-ma@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 14:16:04 by rmota-ma          #+#    #+#             */
/*   Updated: 2025/04/23 14:28:01 by rmota-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	fork_left(int id)
{
	pthread_mutex_lock(&prog()->philo[id].fork);
	pthread_mutex_lock(&prog()->death);
	if(prog()->stop == 0)
	{
		gettimeofday(&prog()->philo[id].cycle_start, NULL);
		gettimeofday(&prog()->philo[id].current, NULL);
		printf("%ld %d has taken a fork\n",(prog()->philo[id].current.tv_sec - prog()->start.tv_sec) * 1000 + (prog()->philo[id].current.tv_usec - prog()->start.tv_usec) / 1000, id + 1);
	}
	pthread_mutex_unlock(&prog()->death);
}

void	fork_right(int id)
{
	if (id == prog()->args[0] - 1)
		pthread_mutex_lock(&prog()->philo[0].fork);
	else
		pthread_mutex_lock(&prog()->philo[id + 1].fork);
	pthread_mutex_lock(&prog()->death);
	if(prog()->stop == 0)
	{
		gettimeofday(&prog()->philo[id].current, NULL);
		printf("%ld %d has taken a fork\n",(prog()->philo[id].current.tv_sec - prog()->start.tv_sec) * 1000 + (prog()->philo[id].current.tv_usec - prog()->start.tv_usec) / 1000, id + 1);
	}
	pthread_mutex_unlock(&prog()->death);
}

void	eating(int id)
{
	pthread_mutex_lock(&prog()->death);
	if(prog()->stop == 0)
	{
		gettimeofday(&prog()->philo[id].current, NULL);
		printf("%ld %d is eating\n",(prog()->philo[id].current.tv_sec - prog()->start.tv_sec) * 1000 + (prog()->philo[id].current.tv_usec - prog()->start.tv_usec) / 1000, id + 1);
	}
	pthread_mutex_unlock(&prog()->death);
	prog()->philo[id].eat_counter++;
	if (prog()->philo[id].eat_counter == prog()->args[4] && prog()->argc == 6 && prog()->philo[id].stop == 0)
	{
		pthread_mutex_lock(&prog()->eat_lock);
		prog()->meal++;
		if(prog()->meal == prog()->args[0])
		{
			pthread_mutex_lock(&prog()->death);
			if (prog()->stop == 0)
				prog()->stop = 1;
			pthread_mutex_unlock(&prog()->death);
		}
		pthread_mutex_unlock(&prog()->eat_lock);
		prog()->philo[id].stop = 1;
	}
	death_checker(id, prog()->args[2], 0);
}

void	*lone_philo(void *id)
{
	gettimeofday(&prog()->start, NULL);
	fork_left(*(int*)id);
	usleep(prog()->args[1] * 1000);
	gettimeofday(&prog()->philo[*(int*)id].current, NULL);
	printf("%ld %d died\n",(prog()->philo[*(int*)id].current.tv_sec - prog()->start.tv_sec) * 1000 + (prog()->philo[*(int*)id].current.tv_usec - prog()->start.tv_usec) / 1000, *(int*)id + 1);
	pthread_mutex_unlock(&prog()->philo[*(int*)id].fork);
	return(0);
}