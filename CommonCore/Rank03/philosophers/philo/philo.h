/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scorpot <scorpot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 14:25:51 by rmota-ma          #+#    #+#             */
/*   Updated: 2025/03/31 23:11:26 by scorpot          ###   ########.fr       */
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

typedef struct s_philo
{
	pthread_t	*thread;
	pthread_mutex_t	mutex;
	long			*args;
	int *start;
}				t_philo;

//MAIN.C
int	error_syntax(char **argv, int var);

//LIB_INC.C
void	*ft_calloc(size_t nmemb, size_t size);
void	ft_bzero(void *s, size_t n);
long	ft_atol(char *str);
t_philo *philo(void);

#endif