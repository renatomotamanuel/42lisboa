/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_op.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmota-ma <rmota-ma@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 16:02:19 by rmota-ma          #+#    #+#             */
/*   Updated: 2025/01/14 16:04:04 by rmota-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(int **a)
{
	int	temp;

	temp = (*a)[0];
	(*a)[0] = (*a)[1];
	(*a)[1] = temp;
	ft_printf("sa\n");
}

void	push_a(int **a, int **b)
{
	int	var;
	int	var2;

	var2 = 0;
	var = ft_arrlen(a);
	while (var > 0)
	{
		(*a)[var] = (*a)[var - 1];
		var--;
	}
	(*a)[0] = *b[0];
	var = ft_arrlen(b);
	while (var2 < var)
	{
		(*b)[var2] = (*b)[var2 + 1];
		var2++;
	}
	ft_printf("pa\n");
}

void	rot_a(int **a)
{
	int	var;
	int	temp;

	temp = (*a)[0];
	var = 0;
	while ((*a)[var + 1])
	{
		(*a)[var] = (*a)[var + 1];
		var++;
	}
	(*a)[var] = temp;
	ft_printf("ra\n");
}

void	rotrot_a(int **a)
{
	int	var;
	int	temp;

	var = ft_arrlen(a) - 1;
	temp = (*a)[var];
	while (var > 0)
	{
		(*a)[var] = (*a)[var - 1];
		var--;
	}
	(*a)[0] = temp;
	ft_printf("rra\n");
}

int	error_len(char **array)
{
	int	i;

	i = 0;
	while (array[i] != NULL)
		i++;
	return (i);
}
