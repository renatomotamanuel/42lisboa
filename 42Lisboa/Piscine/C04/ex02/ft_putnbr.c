/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmota-ma <rmota-ma@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 21:40:16 by rmota-ma          #+#    #+#             */
/*   Updated: 2024/08/28 22:02:28 by rmota-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

void	ft_putnbr(int nb);

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	long int	bnb;

	bnb = nb;
	if (bnb < 0)
	{
		ft_putchar ('-');
		bnb = -bnb;
	}
	if (bnb >= 10)
	{
		ft_putnbr(bnb / 10);
		bnb = bnb % 10;
	}
	if (bnb < 10)
	{
		ft_putchar(bnb + 48);
	}
}

/*int main()
{
	ft_putnbr(2147483647);
}*/