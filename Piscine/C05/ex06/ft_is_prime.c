/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmota-ma <rmota-ma@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 17:11:52 by rmota-ma          #+#    #+#             */
/*   Updated: 2024/09/03 16:36:43 by rmota-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_is_prime(int nb)
{
	int	n;

	n = 2;
	if (nb < 2)
	{
		return (0);
	}
	while (n < nb)
	{
		if (nb % n == 0)
		{
			return (0);
		}
		else
		{
			n++;
		}
	}
	return (1);
}

/*int main()
{
	printf ("%d\n", ft_is_prime(-2));
}*/