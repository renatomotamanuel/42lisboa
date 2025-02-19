/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmota-ma <rmota-ma@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 14:12:04 by rmota-ma          #+#    #+#             */
/*   Updated: 2024/08/28 14:11:19 by rmota-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <stdio.h>
#include <string.h>*/

char	*ft_strncat(char *dest, char *src, unsigned int nb);

int	ft_strlen(char *str)
{
	int	a;

	a = 0;
	while (str[a] != '\0')
	{
		a++;
	}
	return (a);
}

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

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	a;

	a = 0;
	while (a < n && src[a] != '\0')
	{
		dest[a] = src[a];
		a++;
	}
	while (a < n)
	{
		dest[a] = '\0';
		a++;
	}
	return (dest);
}

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned a = ft_strlen (dest);
	unsigned b = ft_strlen (src);
	if (b < nb)
	{
		ft_strcpy (&dest[a], src);
	}
	else
	{
		ft_strncpy (&dest[a], src, nb);
		dest[a + nb] = '\0';
	}
	return (dest);
}
/*int main()
{
	char *src = "He";
	char dest[35] = "dchdfghg";
	unsigned int nb = 5;
	printf("ft_strcat: %s\n", ft_strncat(dest, src, nb));
	printf("strncat: %s\n", strncat(dest, src, nb));
	
}*/