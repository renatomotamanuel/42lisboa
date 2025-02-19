/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmota-ma <rmota-ma@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 12:32:58 by rmota-ma          #+#    #+#             */
/*   Updated: 2024/08/29 19:54:13 by rmota-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int	ft_atoi(char	*str);

int	verify(char *str)
{
	int	a;
	int	count;

	a = 0;
	count = 0;
	while (str[a] != '\0')
	{
		if (str[a] < '0' || str[a] > '9')
		{
			if (str[a] == '-')
			{
				count++;
			}
		}
		count = count % 2;
		a++;
	}
	return (count);
}

int	ft_atoi(char *str)
{
	int	a;
	int	count;
	int	res;

	a = 0;
	count = verify(str);
	res = 0;
	if (count == 1)
		count = -1;
	else
		count = 1;
	while (str[a] == ' ' || (str[a] > 8 && str[a] < 14))
	{
		a++;
	}
	while ((str[a] == '-' || str[a] == '+'))
	{
		a++;
	}
	while (str[a] >= '0' && str[a] <= '9')
	{
		res = res * 10 + (str[a] - '0');
		a++;
	}
	return (count * res);
}

/*int    main(void)
{
    char    *nbr1 = " -+++-\v1837ei821";
    char    *nbr2 = " \t--+--+0092823d8";
    char    *nbr3 = "923- -34s";
    char    *nbr4 = "18  42f";
    char    *nbr5 = "";
    char    *nbr6 = "-2147483648";
    char    *nbr7 = "123";
    char    *nbr8 = "-456";
    char    *nbr9 = "   789";
    char    *nbr10 = "  -0123   ";
    char    *nbr11 = "2147483648";
    char    *nbr12 = "+321";
    char    *nbr13 = "123abc";
    char    *nbr14 = "abc123";    
    printf("atoi    (%s): %d\n", nbr1, atoi(nbr1));
    printf("ft_atoi (%s): %d\n\n", nbr1, ft_atoi(nbr1));
    printf("atoi    (%s): %d\n", nbr2, atoi(nbr2));
    printf("ft_atoi (%s): %d\n\n", nbr2, ft_atoi(nbr2));
    printf("atoi    (%s): %d\n", nbr3, atoi(nbr3));
    printf("ft_atoi (%s): %d\n\n", nbr3, ft_atoi(nbr3));
    printf("atoi    (%s): %d\n", nbr4, atoi(nbr4));
    printf("ft_atoi (%s): %d\n\n", nbr4, ft_atoi(nbr4));
    printf("atoi    (%s): %d\n", nbr5, atoi(nbr5));
    printf("ft_atoi (%s): %d\n\n", nbr5, ft_atoi(nbr5));
    printf("atoi    (%s): %d\n", nbr6, atoi(nbr6));
    printf("ft_atoi (%s): %d\n\n", nbr6, ft_atoi(nbr6));
    printf("atoi    (%s): %d\n", nbr7, atoi(nbr7));
    printf("ft_atoi (%s): %d\n\n", nbr7, ft_atoi(nbr7));
    printf("atoi    (%s): %d\n", nbr8, atoi(nbr8));
    printf("ft_atoi (%s): %d\n\n", nbr8, ft_atoi(nbr8));
    printf("atoi    (%s): %d\n", nbr9, atoi(nbr9));
    printf("ft_atoi (%s): %d\n\n", nbr9, ft_atoi(nbr9));
    printf("atoi    (%s): %d\n", nbr10, atoi(nbr10));
    printf("ft_atoi (%s): %d\n\n", nbr10, ft_atoi(nbr10));
    printf("atoi    (%s): %d\n", nbr11, atoi(nbr11));
    printf("ft_atoi (%s): %d\n\n", nbr11, ft_atoi(nbr11));
    printf("atoi    (%s): %d\n", nbr12, atoi(nbr12));
    printf("ft_atoi (%s): %d\n\n", nbr12, ft_atoi(nbr12));
    printf("atoi    (%s): %d\n", nbr13, atoi(nbr13));
    printf("ft_atoi (%s): %d\n\n", nbr13, ft_atoi(nbr13));
    printf("atoi    (%s): %d\n", nbr14, atoi(nbr14));
    printf("ft_atoi (%s): %d\n\n", nbr14, ft_atoi(nbr14));
    return (0);
}*/
