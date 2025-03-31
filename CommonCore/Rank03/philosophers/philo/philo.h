/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmota-ma <rmota-ma@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 14:25:51 by rmota-ma          #+#    #+#             */
/*   Updated: 2025/03/31 18:16:36 by rmota-ma         ###   ########.fr       */
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

//MAIN.C
int	error_syntax(char **argv, int var);
int teste(void);
void* deposit(void *amount);
int read_balance();
void write_balance(int new_balance);

//LIB_INC.C
void	*ft_calloc(size_t nmemb, size_t size);
void	ft_bzero(void *s, size_t n);
long	ft_atol(char *str);
#endif