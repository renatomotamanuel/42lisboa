/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmota-ma <rmota-ma@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 16:11:19 by scorpot           #+#    #+#             */
/*   Updated: 2025/02/18 16:50:13 by rmota-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int	len;
	int	var;
	int	error;

	var = 0;
	error = 0;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (0);
	else if (argc == 2)
		argv = ft_split(argv[1], ' ');
	else if (argc > 2)
		argv = &argv[1];
	len = error_syntax(argv, var);
	if (len > 0)
		error = init_stack(argv, len, var);
	else
	{
		write(2, "Error\n", 6);
		len = error_len(argv);
		error = 1;
	}
	if (argc == 2)
		ft_free(argv, len);
	return (error);
}

int	error_syntax(char **array, int var)
{
	int	i;

	i = 0;
	while (array[i] != NULL)
	{
		var = 0;
		if (array[i][var] == '\0')
			return (0);
		while (array[i][var] != '\0')
		{
			if ((array[i][var] >= '0' && array[i][var] <= '9') ||
					(array[i][var] == '-' || array[i][var] == '+'))
			{
				if ((array[i][var] == '-' || array[i][var] == '+') &&
					((array[i][var + 1] < '0' || array[i][var] > '9') ||
						(var != '\0')))
					return (0);
			}
			else
				return (0);
			var++;
		}
		i++;
	}
	return (i);
}

int	init_stack(char **argv, int len, int var)
{
	int	*a;
	int	*b;

	if (ver_atoi(argv, len) == 0)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	a = ft_calloc(sizeof(int *), len);
	b = ft_calloc(sizeof(int *), len);
	while (var < len)
	{
		a[var] = ft_atoi(argv[var]);
		var++;
	}
	len = equal_nbr(&a, len);
	if (len == 0)
	{
		write(2, "Error\n", 6);
		return (free(a), free(b), 1);
	}
	a = normalize(a, len);
	sort(&a, &b, len);
	return (free(a), free(b), 0);
}

int	*normalize(int *a, int len)
{
	int	*temp;
	int	var;
	int	nbr;
	int	var2;

	var = 0;
	temp = ft_calloc(sizeof(int *), len + 1);
	while (var < len)
	{
		nbr = 1;
		var2 = 0;
		while (var2 < len)
		{
			if (a[var] > a[var2])
				nbr++;
			var2++;
		}
		temp[var] = nbr;
		var++;
	}
	return (free(a), temp);
}

int	equal_nbr(int **a, int len)
{
	int	var;
	int	var2;

	var = 0;
	while (var < len - 1)
	{
		var2 = 0;
		while (var2 < len)
		{
			if (var2 == var)
				var2++;
			if ((*a)[var] == (*a)[var2])
				return (0);
			var2++;
		}
		var++;
	}
	return (len);
}
