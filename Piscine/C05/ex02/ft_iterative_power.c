/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmota-ma <rmota-ma@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 19:55:05 by rmota-ma          #+#    #+#             */
/*   Updated: 2024/08/31 21:15:44 by rmota-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_iterative_power(int nb, int power)
{
	int	a;

	a = 1;
	if (nb == 0 && power == 0)
	{
		return (1);
	}
	if (power < 0)
	{
		return (0);
	}
	while (power > 0)
	{
		a = nb * a;
		power--;
	}
	return (a);
}

/*int main()
{
	int nb = 0;
	int power = 2;
	printf("%d\n", ft_iterative_power(nb, power));
}*/