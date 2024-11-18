/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmota-ma <rmota-ma@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 23:32:14 by rmota-ma          #+#    #+#             */
/*   Updated: 2024/08/26 14:26:03 by rmota-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

int	ft_str_is_printable(char *str);

int	ft_str_is_printable(char *str)
{
	while (*str)
	{
		if (*str > 126 || *str < 32)
		{
			return (0);
		}
		str++;
	}
	return (1);
}

/*int	main()
{
	char str[] = " ";
	int b = ft_str_is_printable(str);
	printf("%d\n", b);
}*/
