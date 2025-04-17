/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmota-ma <rmota-ma@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 11:02:45 by rmota-ma          #+#    #+#             */
/*   Updated: 2025/04/17 18:04:10 by rmota-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	eat_even(int id)
{
	pthread_mutex_lock(&prog()->philo[id].fork);
	pthread_mutex_lock(&prog()->death);
	gettimeofday(&prog()->philo[id].current, NULL);
	if(prog()->stop == 0)
		printf("%ld %d has taken a fork\n",(prog()->philo[id].current.tv_sec - prog()->start.tv_sec) * 1000 + (prog()->philo[id].current.tv_usec - prog()->start.tv_usec) / 1000, id);
	pthread_mutex_unlock(&prog()->death);
	if (id == prog()->args[0] - 1)
		pthread_mutex_lock(&prog()->philo[0].fork);
	else
		pthread_mutex_lock(&prog()->philo[id + 1].fork);
	pthread_mutex_lock(&prog()->death);
	gettimeofday(&prog()->philo[id].current, NULL);
	if(prog()->stop == 0)
		printf("%ld %d has taken a fork\n",(prog()->philo[id].current.tv_sec - prog()->start.tv_sec) * 1000 + (prog()->philo[id].current.tv_usec - prog()->start.tv_usec) / 1000, id);
	pthread_mutex_unlock(&prog()->death);
	gettimeofday(&prog()->philo[id].current, NULL);
	pthread_mutex_lock(&prog()->death);
	if(prog()->stop == 0)
		printf("%ld %d is eating\n",(prog()->philo[id].current.tv_sec - prog()->start.tv_sec) * 1000 + (prog()->philo[id].current.tv_usec - prog()->start.tv_usec) / 1000, id);
	pthread_mutex_unlock(&prog()->death);
	death_checker(id, prog()->args[2]);
	prog()->philo[id].eat_counter++;
	if (id == prog()->args[0] - 1)
		pthread_mutex_unlock(&prog()->philo[0].fork);
	else
		pthread_mutex_unlock(&prog()->philo[id + 1].fork);
	pthread_mutex_unlock(&prog()->philo[id].fork);
}

void	eat_odd(int id)
{
	if (id == prog()->args[0] - 1)
		pthread_mutex_lock(&prog()->philo[0].fork);
	else
		pthread_mutex_lock(&prog()->philo[id + 1].fork);
	pthread_mutex_lock(&prog()->death);
	gettimeofday(&prog()->philo[id].current, NULL);
	if(prog()->stop == 0)
		printf("%ld %d has taken a fork\n",(prog()->philo[id].current.tv_sec - prog()->start.tv_sec) * 1000 + (prog()->philo[id].current.tv_usec - prog()->start.tv_usec) / 1000, id);
	pthread_mutex_unlock(&prog()->death);
	pthread_mutex_lock(&prog()->philo[id].fork);
	gettimeofday(&prog()->philo[id].current, NULL);
	pthread_mutex_lock(&prog()->death);
	if(prog()->stop == 0)
		printf("%ld %d has taken a fork\n",(prog()->philo[id].current.tv_sec - prog()->start.tv_sec) * 1000 + (prog()->philo[id].current.tv_usec - prog()->start.tv_usec) / 1000, id);
	pthread_mutex_unlock(&prog()->death);
	pthread_mutex_lock(&prog()->death);
	gettimeofday(&prog()->philo[id].current, NULL);
	if(prog()->stop == 0)
		printf("%ld %d is eating\n",(prog()->philo[id].current.tv_sec - prog()->start.tv_sec) * 1000 + (prog()->philo[id].current.tv_usec - prog()->start.tv_usec) / 1000, id);
	pthread_mutex_unlock(&prog()->death);
	death_checker(id, prog()->args[2]);
	prog()->philo[id].eat_counter++;
	pthread_mutex_unlock(&prog()->philo[id].fork);
	if (id == prog()->args[0] - 1)
		pthread_mutex_unlock(&prog()->philo[0].fork);
	else
		pthread_mutex_unlock(&prog()->philo[id + 1].fork);
}

void	philo_sleep(int id)
{
	gettimeofday(&prog()->philo[id].current, NULL);
	pthread_mutex_lock(&prog()->death);
	if(prog()->stop == 0)
		printf("%ld %d is sleeping\n",(prog()->philo[id].current.tv_sec - prog()->start.tv_sec) * 1000 + (prog()->philo[id].current.tv_usec - prog()->start.tv_usec) / 1000, id);
	pthread_mutex_unlock(&prog()->death);
	death_checker(id, prog()->args[3]);
	gettimeofday(&prog()->philo[id].current, NULL);
	pthread_mutex_lock(&prog()->death);
	if(prog()->stop == 0)
		printf("%ld %d is thinking\n",(prog()->philo[id].current.tv_sec - prog()->start.tv_sec) * 1000 + (prog()->philo[id].current.tv_usec - prog()->start.tv_usec) / 1000, id);
	pthread_mutex_unlock(&prog()->death);
}

void	death_checker(int id, int sleep_time)
{
	long	diff;

	diff = 0;
	gettimeofday(&prog()->philo[id].current, NULL);
	if (((prog()->philo[id].current.tv_sec - prog()->philo[id].cycle_start.tv_sec) * 1000 + (prog()->philo[id].current.tv_usec - prog()->philo[id].cycle_start.tv_usec) / 1000) + sleep_time >= prog()->args[1])
	{
		diff = (((prog()->philo[id].current.tv_sec - prog()->philo[id].cycle_start.tv_sec) * 1000 + (prog()->philo[id].current.tv_usec - prog()->philo[id].cycle_start.tv_usec) / 1000) + sleep_time) - prog()->args[1];
		usleep((sleep_time - diff) * 1000);
		gettimeofday(&prog()->philo[id].current, NULL);
		pthread_mutex_lock(&prog()->death);
		if (prog()->stop == 0)
		{
			prog()->stop = 1;
			printf("%ld %d has died\n",(prog()->philo[id].current.tv_sec - prog()->start.tv_sec) * 1000 + (prog()->philo[id].current.tv_usec - prog()->start.tv_usec) / 1000, id);
		}
		pthread_mutex_unlock(&prog()->death);
	}
	else
		usleep(sleep_time * 1000);
}
