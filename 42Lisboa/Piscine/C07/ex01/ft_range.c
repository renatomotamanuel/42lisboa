/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmota-ma <rmota-ma@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 11:32:44 by rmota-ma          #+#    #+#             */
/*   Updated: 2024/09/05 13:12:38 by rmota-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int	*ft_range(int min, int max)
{
	int	*mal;
	int	len;
	int	i;

	i = 0;
	len = max - min;
	mal = malloc (len * sizeof(int));
	if (max <= min)
	{
		return (0);
	}
	while (min < max)
	{
		mal[i] = min;
		min++;
		i++;
	}
	return (mal);
}

/*int main(void)
{
	int max;
	int min;
	int size;
	int *range;
	
	max = 0;
	min = 0;
	range = ft_range(min, max);
	size = max - min;
	for (int i = 0; i < size; i++)
	{
		printf("%d\n", range[i]);
	}
	free(range);
}*/