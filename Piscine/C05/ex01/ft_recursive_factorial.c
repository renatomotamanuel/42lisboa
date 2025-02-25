/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_fatorial.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmota-ma <rmota-ma@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 23:05:27 by rmota-ma          #+#    #+#             */
/*   Updated: 2024/09/02 20:31:03 by rmota-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_recursive_factorial(int nb)
{
	if (nb == 0)
	{
		return (1);
	}
	if (nb < 0)
	{
		return (0);
	}
	else
	{
		return (nb * ft_recursive_factorial(nb - 1));
	}
}

/*int main()
{
	printf("result: %d\n", ft_recursive_factorial(5));
}*/
