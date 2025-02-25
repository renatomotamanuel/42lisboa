/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmota-ma <rmota-ma@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 21:05:40 by rmota-ma          #+#    #+#             */
/*   Updated: 2024/08/31 21:16:29 by rmota-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_recursive_power(int nb, int power)
{
	if ((nb == 0 && power == 0) || power == 0)
	{
		return (1);
	}
	if (power < 0)
	{
		return (0);
	}
	if (power > 1)
	{
		return (nb * ft_recursive_power(nb, power - 1));
	}
	return (nb);
}

/*int	main()
{
	int nb = 3456;
	int power = 0;
	printf("%d\n", ft_recursive_power(nb, power));
}*/