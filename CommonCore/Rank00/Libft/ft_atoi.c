/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmota-ma <rmota-ma@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 16:06:25 by rmota-ma          #+#    #+#             */
/*   Updated: 2024/10/31 16:48:32 by rmota-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

/*int    main(void)
{
    char    *nbr1 = " -1837ei821";
	printf("ft_atoi    (%s): %d\n", nbr1, ft_atoi(nbr1));
	char    *nbr2 = " -1837ei821";
	printf("atoi    (%s): %d\n", nbr1, atoi(nbr2));
}*/