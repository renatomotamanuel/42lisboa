/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_op.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmota-ma <rmota-ma@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 13:02:58 by rmota-ma          #+#    #+#             */
/*   Updated: 2025/01/14 22:09:48 by rmota-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_b(int **b)
{
	int	temp;

	temp = (*b)[0];
	(*b)[0] = (*b)[1];
	(*b)[1] = temp;
	ft_printf("sb\n");
}

void	push_b(int **a, int **b)
{
	int	var;
	int	var2;

	var2 = 0;
	var = ft_arrlen(b);
	while (var > 0)
	{
		(*b)[var] = (*b)[var - 1];
		var--;
	}
	(*b)[0] = *a[0];
	var = ft_arrlen(a);
	while (var2 < var)
	{
		(*a)[var2] = (*a)[var2 + 1];
		var2++;
	}
	ft_printf("pb\n");
}

void	rot_b(int **b)
{
	int	var;
	int	temp;

	temp = (*b)[0];
	var = 0;
	while ((*b)[var + 1])
	{
		(*b)[var] = (*b)[var + 1];
		var++;
	}
	(*b)[var] = temp;
	ft_printf("rb\n");
}

void	rotrot_b(int **b)
{
	int	var;
	int	temp;

	var = ft_arrlen(b) - 1;
	temp = (*b)[var];
	while (var > 0)
	{
		(*b)[var] = (*b)[var - 1];
		var--;
	}
	(*b)[0] = temp;
	ft_printf("rrb\n");
}

int	ver_atoi(char **argv, int len)
{
	int			var;
	long int	*check;

	var = 0;
	check = ft_calloc(sizeof(long int *), len);
	while (var < len)
	{
		check[var] = ft_atoi_check(argv[var]);
		if (check[var] > INT_MAX || check[var] < INT_MIN)
			return (free(check), 0);
		var++;
	}
	return (free(check), 1);
}
