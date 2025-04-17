/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_inc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmota-ma <rmota-ma@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 12:05:05 by rmota-ma          #+#    #+#             */
/*   Updated: 2025/04/16 12:05:20 by rmota-ma         ###   ########.fr       */
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

int	error_syntax(char **argv, int var)
{
	int	i;

	i = 1;
	while (argv[i] != NULL)
	{
		var = 0;
		if (argv[i][var] == '\0')
			return (1);
		while (argv[i][var] != '\0')
		{
			if ((argv[i][var] >= '0' && argv[i][var] <= '9') ||
					(argv[i][var] == '-' || argv[i][var] == '+'))
			{
				if ((argv[i][var] == '-' || argv[i][var] == '+') &&
					((argv[i][var + 1] < '0' || argv[i][var] > '9') ||
						(var != '\0')))
					return (1);
			}
			else
				return (1);
			var++;
		}
		i++;
	}
	return (0);
}


t_prog *prog(void)
{
	static t_prog	prog;

	return (&prog);
}
