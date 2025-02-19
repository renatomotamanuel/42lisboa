/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmota-ma <rmota-ma@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 19:34:31 by rmota-ma          #+#    #+#             */
/*   Updated: 2024/10/22 21:16:02 by rmota-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

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

char	*ft_strdup(char *src)
{
	char	*mal;

	mal = malloc (ft_strlen(src) * sizeof(char) + 1);
	return (ft_strcpy(mal, src));
}

/*int main(void)
{
    char    *src = "asdfh";
	char	*s1;
	char	*s2;
	s1 = ft_strdup(src);
	s2 = strdup(src);
    printf("originalstr %s\n", src);
    printf("Mydup       %s\n", s1);
    printf("officialdup %s\n", s2);
	free(s1);
	free(s2);
}*/
