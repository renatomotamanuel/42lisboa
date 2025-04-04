/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmota-ma <rmota-ma@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 14:25:51 by rmota-ma          #+#    #+#             */
/*   Updated: 2025/04/04 16:38:26 by rmota-ma         ###   ########.fr       */
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
	long			*args;
	pthread_t	*thread;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*l_fork;
	int				dead;
}				t_philo;

//PHILO.C
void	philo_rout(int argc);
void	init_philo(void);
void	think_eat_sleep(void);
void	free_func(void);

//LIB_INC.C
void	*ft_calloc(size_t nmemb, size_t size);
void	ft_bzero(void *s, size_t n);
long	ft_atol(char *str);
t_philo *philo(void);
int	error_syntax(char **argv, int var);

//ACTIONS.C
void	*eat(void *nada);
#endif