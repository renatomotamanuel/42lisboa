/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmota-ma <rmota-ma@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 14:38:16 by rmota-ma          #+#    #+#             */
/*   Updated: 2025/01/14 16:07:36 by rmota-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_sorted(int **a, int len)
{
	int	var;

	var = 0;
	while (var < len - 1)
	{
		if ((*a)[var] > (*a)[var + 1])
			return (0);
		var++;
	}
	return (1);
}

void	sort_big(int **a, int **b, int len)
{
	int	bit;
	int	var;

	bit = 0;
	while (stack_sorted(a, len) == 0)
	{
		var = ft_arrlen(a);
		while (var > 0)
		{
			if (((*a)[0] >> bit & 1) == 1)
				rot_a(a);
			else if (((*a)[0] >> bit & 1) == 0)
				push_b(a, b);
			var--;
		}
		while (ft_arrlen(b) > 0)
			push_a(a, b);
		bit++;
	}
}

void	sort_small(int **a, int **b, int len)
{
	int	var;

	var = 0;
	if (len == 2)
		rot_a(a);
	else if (len == 3)
		sort_three(a);
	else if (len > 3)
	{
		push_b(a, b);
		push_b(a, b);
		sort_three(a);
		if ((*b)[0] < (*b)[1])
			swap_b(b);
		sort_four(a, b, len, var);
		sort_four(a, b, len, var);
		while ((*a)[0] != 1)
			rotrot_a(a);
	}
}

void	sort_three(int **a)
{
	if ((*a)[0] > (*a)[1] && (*a)[1] < (*a)[2] && (*a)[0] > (*a)[2])
		rot_a(a);
	else if ((*a)[0] > (*a)[1] && (*a)[1] > (*a)[2] && (*a)[2] < (*a)[0])
	{
		swap_a(a);
		rotrot_a(a);
	}
	else if ((*a)[0] < (*a)[1] && (*a)[1] > (*a)[2] && (*a)[0] > (*a)[2])
		rotrot_a(a);
	else if ((*a)[0] < (*a)[1] && (*a)[1] > (*a)[2] && (*a)[0] < (*a)[2])
	{
		rotrot_a(a);
		swap_a(a);
	}
	else if ((*a)[0] > (*a)[1] && (*a)[1] < (*a)[2] && (*a)[2] > (*a)[0])
		swap_a(a);
}

void	sort_four(int **a, int **b, int len, int var)
{
	int	nbr;

	var = 0;
	while (var < len)
	{
		if ((*a)[var] == ((*b)[0] + 1))
			nbr = ((*b)[0] + 1);
		if (((*a)[var] == 1 && (*b)[0] == 5) || ((*a)[var] == 1 &&
			(*b)[0] == 4 && len == 4))
			nbr = 1;
		if ((((*a)[var] == 2 && (*b)[0] == 5) || ((*a)[var] == 2 &&
			(*b)[0] == 4 && len == 4)) && (*b)[1] == 1)
			nbr = 2;
		var++;
	}
	while ((*a)[0] != nbr)
		rotrot_a(a);
	push_a(a, b);
}
