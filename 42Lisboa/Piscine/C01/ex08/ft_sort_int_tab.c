/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmota-ma <rmota-ma@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 11:57:31 by rmota-ma          #+#    #+#             */
/*   Updated: 2024/08/21 23:09:56 by rmota-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

void	ft_sort_int_tab(int *tab, int size)
{
	int	a;
	int	b;
	int	c;

	a = 0;
	while (a < size -1)
	{
		b = a + 1;
		while (b < size)
		{
			if (tab[b] < tab[a])
			{
				c = tab[a];
				tab[a] = tab[b];
				tab[b] = c;
			}
			b++;
		}
		a++;
	}
}

/*int	main()
{
	int tab[6] = {76, 44, 288, 33, 6767, -999999};
	int size = 6;
	
	ft_sort_int_tab(tab, size);
	printf("%d, %d, %d, ", tab[0], tab[1], tab[2]);
	printf("%d, %d, %d\n", tab[3], tab[4], tab[5]);
	return(0);
}*/
