/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmota-ma <rmota-ma@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 15:42:31 by rmota-ma          #+#    #+#             */
/*   Updated: 2024/08/29 19:43:13 by rmota-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

char	*ft_strcpy(char *dest, char *src)
{
	int	a;

	a = 0;
	while (src[a] != '\0')
	{
		dest[a] = src[a];
		a++;
	}
	dest[a] = '\0';
	return (dest);
}

int main()
{
	char src[]= "Helloasdf56s7fs,///, World";
	char dest[50];

	
	printf("ft_strcpy: %s\n", ft_strcpy(dest, src));
	printf("strcpy:    %s\n", strcpy(dest, src));
	return(0);
}