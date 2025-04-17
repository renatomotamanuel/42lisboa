/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmota-ma <rmota-ma@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 14:25:51 by rmota-ma          #+#    #+#             */
/*   Updated: 2025/04/16 17:10:45 by rmota-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <pthread.h>
# include <stdlib.h>
# include <stdarg.h>
# include <fcntl.h>
# include <stdio.h>
# include <sys/wait.h>
# include <string.h>
# include <limits.h>
# include <sys/time.h>
# include <time.h>

typedef struct s_philo
{
	struct timeval	current;
	struct timeval	cycle_start;
	pthread_t	thread;
	int			id;
	pthread_mutex_t	fork;
	int				dead;
	int				eat_counter;
}				t_philo;

typedef struct s_prog
{
	struct timeval	start;
	long			*args;
	t_philo			*philo;
	int				argc;
	int				exit;
}				t_prog;


//PHILO.C
void	init_philo(void);
void	*philo_rout(void *argc);
int	think_eat_sleep(int id);
void	joiner(int odd);
void	free_func(void);

//LIB_INC.C
void	*ft_calloc(size_t nmemb, size_t size);
void	ft_bzero(void *s, size_t n);
long	ft_atol(char *str);
t_prog *prog(void);
int	error_syntax(char **argv, int var);

//ACTIONS.C
int	eat(int id);
int	philo_sleep(int id);
void	death_checker(int id, int sleep_time);
int	reaper(int id);


#endif