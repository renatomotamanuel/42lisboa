/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmota-ma <rmota-ma@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 20:57:21 by scorpot           #+#    #+#             */
/*   Updated: 2025/01/03 17:44:10 by rmota-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*str;

	i = 0;
	str = s;
	while (i < n)
	{
		str[i] = 0;
		i++;
	}
}

int	ft_atoi(const char *str)
{
	int	a;
	int	res;
	int	count;

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

size_t	ft_strlen(const char *str)
{
	int	a;

	a = 0;
	while (str[a] != '\0')
	{	printf("%d", a->nbr);
		a++;
	}
	return (a);
}