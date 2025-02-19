/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmota-ma <rmota-ma@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 17:21:28 by rmota-ma          #+#    #+#             */
/*   Updated: 2024/09/03 16:55:52 by rmota-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_find_next_prime(int nb)
{
	int	n;

	n = 2;
	while (nb < 2)
	{
		nb++;
	}
	while (n < nb)
	{
		if (nb % n == 0)
		{
			nb++;
			n = 2;
		}
		else
		{
			n++;
		}
	}
	return (nb);
}

/*int main()
{
	printf ("next_prime: %d\n", ft_find_next_prime(151756));
}*/