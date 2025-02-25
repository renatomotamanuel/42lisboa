/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juldelga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 18:43:54 by juldelga          #+#    #+#             */
/*   Updated: 2024/08/18 18:47:11 by juldelga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

void	ft_top(int x)
{
	int	c;

	c = 0;
	while (c < x)
	{
		if (c == 0 || c == x - 1)
			ft_putchar('o');
		else
			ft_putchar('-');
		c++;
	}
	ft_putchar('\n');
}

void	ft_middle(int x, int y)
{
	int	r;
	int	c;

	r = 0;
	while (r < y - 2)
	{
		c = 0;
		while (c < x)
		{
			if (c == 0 || c == x - 1)
				ft_putchar('|');
			else
				ft_putchar(' ');
			c++;
		}
		ft_putchar('\n');
		r++;
	}
}

void	rush(int x, int y)
{
	if (x <= 0 || y <= 0)
	{
		write(1, "Invalid arguments", 17);
	}
	if (x > 0 && y > 0)
	{
		ft_top(x);
		if (y > 1)
		{
			ft_middle(x, y);
			ft_top(x);
		}
	}
}
