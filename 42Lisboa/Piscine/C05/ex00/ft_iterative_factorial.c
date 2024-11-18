/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmota-ma <rmota-ma@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 22:57:37 by rmota-ma          #+#    #+#             */
/*   Updated: 2024/08/31 21:05:23 by rmota-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_iterative_factorial(int nb)
{
	int	a;
	int	fatorial;

	a = 1;
	fatorial = 1;
	if (nb == 0)
	{
		return (1);
	}
	if (nb < 0)
	{
		return (0);
	}
	while (a <= nb)
	{
		fatorial = fatorial * a;
		a++;
	}
	return (fatorial);
}

/*int main()
{
	printf("result: %d\n", ft_iterative_factorial(-12));
}*/