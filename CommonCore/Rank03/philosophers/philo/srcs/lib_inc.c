/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_inc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmota-ma <rmota-ma@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 14:47:59 by rmota-ma          #+#    #+#             */
/*   Updated: 2025/03/31 15:54:22 by rmota-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

long	ft_atol(char *str)
{
	int			a;
	long int	res;
	long int	count;

	a = 0;
	res = 0;
	count = 1;
	while (str[a] == ' ' || (str[a] > 8 && str[a] < 14))
	{
		a++;
	}
	if ((str[a] == '-' || str[a] == '+'))
	{
		if (str[a] == '-')
			count *= -1;
		a++;
	}
	while (str[a] >= '0' && str[a] <= '9')
	{
		res = res * 10 + (str[a] - '0');
		if (res > INT_MAX || res < INT_MIN)
			return (2147483648);
		a++;
	}
	return (count * res);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*temp;
	size_t			len;

	temp = malloc(nmemb * size);
	len = nmemb * size;
	if (size && (len / size) != nmemb)
		return (NULL);
	if (temp == NULL)
		return (NULL);
	if (nmemb == 0 || size == 0)
		return (temp);
	ft_bzero(temp, nmemb * size);
	return (temp);
}

void	ft_bzero(void *s, size_t n)
{
	size_t			var;
	unsigned char	*str;

	var = 0;
	str = s;
	while (var < n)
	{
		str[var] = '\0';
		var++;
	}
}
