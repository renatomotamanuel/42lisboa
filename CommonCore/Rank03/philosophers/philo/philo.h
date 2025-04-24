/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmota-ma <rmota-ma@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 14:25:51 by rmota-ma          #+#    #+#             */
/*   Updated: 2025/04/24 13:29:17 by rmota-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <pthread.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include <sys/time.h>

typedef struct s_philo
{
	struct timeval	current;
	struct timeval	cycle;
	pthread_t		thread;
	pthread_mutex_t	fork;
	int				id;
	int				dead;
	int				stop;
	int				eat_counter;
}				t_philo;

typedef struct s_prog
{
	struct timeval	start;
	long			*args;
	int				argc;
	int				stop;
	int				meal;
	pthread_mutex_t	eat_lock;
	pthread_mutex_t	death;
	t_philo			*philo;
}				t_prog;

//MAIN.C
t_prog	*prog(void);

//PHILO.C
void	init_philo(void);
void	*philo_rout(void *id);
void	think_eat_sleep(int id);
void	multiple_philos(void);
void	free_func(void);

//LIB_INC.C
void	*ft_calloc(size_t nmemb, size_t size);
void	ft_bzero(void *s, size_t n);
long	ft_atol(char *str);
int		error_syntax(char **argv, int var);
int		ft_isalpha(int c, int next);

//ACTIONS.C
void	eat_even(int id);
void	eat_odd(int id);
void	philo_sleep(int id);
void	death_checker(int id, int sleep_time, long diff);
void	grim_reaper(int id, int sleep_time, long diff);

//PRINTS.C
void	fork_left(int id);
void	fork_right(int id);
void	eating(int id);
void	*lone_philo(void *id);
void	finish_eating(int id);

#endif