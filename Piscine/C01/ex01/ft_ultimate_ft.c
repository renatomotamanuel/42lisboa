/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_ft.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmota-ma <rmota-ma@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 16:31:03 by rmota-ma          #+#    #+#             */
/*   Updated: 2024/08/23 22:52:28 by rmota-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_ultimate_ft(int *********nbr)
{
	*********nbr = 42;
}
int	main(void)
{
	int	a = 0;
	int	*b = &a;
	int	**c = &b;
	int	***d = &c;
	int	****e = &d;
	int	*****f = &e;
	int	******g = &f;
	int	*******h = &g;
	int	********i = &h;
	int	*********j = &i;
	ft_ultimate_ft(j);
	printf("%d\n", a);	
}
