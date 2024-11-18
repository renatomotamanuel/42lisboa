/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmota-ma <rmota-ma@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 22:32:10 by rmota-ma          #+#    #+#             */
/*   Updated: 2024/08/27 12:04:58 by rmota-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

int	ft_strcmp(char *s1, char *s2);

int	ft_strcmp(char *s1, char *s2)
{
	int	a;
	int	b;

	a = 0;
	b = 0;
	while (s1[a] && s2[b])
	{
		if (s1[a] != s2[b])
		{
			return (s1[a] - s2[b]);
		}
		a++;
		b++;
	}
	return (s1[a] - s2[b]);
}

/*int	main()
{
	char s1[50] = "bbb";
	char s2[50] = "bba";
	printf("%d\n",ft_strcmp(s1, s2));
}*/