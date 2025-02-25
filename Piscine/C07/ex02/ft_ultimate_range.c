/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmota-ma <rmota-ma@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 14:24:40 by rmota-ma          #+#    #+#             */
/*   Updated: 2024/09/05 19:59:50 by rmota-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	size;
	int	i;

	i = 0;
	size = max - min;
	if (max <= min)
	{
		*range = NULL;
		return (0);
	}
	*range = malloc (size * sizeof(int));
	if (!*range)
	{
		*range = NULL;
		return (-1);
	}
	while (i < size)
	{
		(*range)[i] = min + i;
		i++;
	}
	return (size);
	return (size);
}

/*int main(void)
{
    int max = 10;
    int min = 1;
    int *ran;
    int size;

    size = ft_ultimate_range(&ran, min, max);
    printf("Array size: %d\n", size);
    free(ran);
    return (0);
}*/