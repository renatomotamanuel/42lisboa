/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmota-ma <rmota-ma@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 19:15:14 by rmota-ma          #+#    #+#             */
/*   Updated: 2024/08/22 19:02:23 by rmota-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

/*void	ft_rev_int_tab(int *tab, int size)
{
	int	a;
	int	b;

	a = 0;
	while (a < size / 2)
	{
		b = tab [a];
		tab[a] = tab[size -1 - a];
		tab [size -1 - a] = b;
		a++;
	}
}*/

void    ft_swap(int *a, int *b)
{
    int     temp;

    temp = *a;
    *a = *b;
    *b = temp;
}

void    ft_rev_int_tab(int *tab, int size)
{
    int     *i;
    int     *j;

    i = &tab[0];
    j = &tab[size - 1];
    while (i < j)
    {
        ft_swap(i, j);
        i++;
        j--;
    }
}

int	main()
{
	int tab[6] = {-23, 43, 1, 2, -44, 9};
	int size = 6;
	
	ft_rev_int_tab(tab, size);
	printf("%d, %d, %d, ", tab[0], tab[1], tab[2]);
	printf("%d, %d, %d\n", tab[3], tab[4], tab[5]);
	return(0);
}
