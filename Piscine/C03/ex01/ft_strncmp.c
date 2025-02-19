/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmota-ma <rmota-ma@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 14:30:28 by rmota-ma          #+#    #+#             */
/*   Updated: 2024/08/28 21:37:07 by rmota-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <stdio.h>
#include <string.h>*/

int	ft_strncmp(char *s1, char *s2, unsigned int n);

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	a;

	a = 0;
	while ((a < n) && (s1[a] != '\0') && (s2[a] != '\0'))
	{
		if (s1[a] != s2[a])
		{
			return (s1[a] - s2[a]);
		}
		a++;
	}
	if (a < n)
	{
		return (s1[a] - s2[a]);
	}
	return (0);
}

/*int	main()
{
	char s1[] = "asd\0asda";
	char s2[] = "a\0";
	unsigned int n = 4;
	printf("%d\n",ft_strncmp(s1, s2, n));
	printf("%d\n",strncmp(s1, s2, n));
}*/
