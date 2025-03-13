/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_inc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmota-ma <rmota-ma@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 19:37:22 by scorpot           #+#    #+#             */
/*   Updated: 2025/03/07 11:22:13 by rmota-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	int		a;
	size_t	b;

	b = 0;
	if (little[0] == '\0')
		return ((char *)big);
	while (big[b] && b < len)
	{
		a = 0;
		if (big[b] == little[0])
		{
			while (big [b + a] == little[a] && little[a] && (b + a) < len)
				a++;
			if (little[a] == '\0')
				return ((char *)big + b);
		}
		b++;
	}
	return (NULL);
}

size_t	ft_strlen(const char *str)
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

char	*ft_strcat(char *dest, char *src)
{
	ft_strcpy(dest + ft_strlen(dest), src);
	return (dest);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*mal;

	mal = ft_calloc((ft_strlen(s1) + ft_strlen(s2) + 1), 1);
	if (!mal)
		return (NULL);
	if (mal)
	{
		ft_strcpy(mal, (char *)s1);
		ft_strcat(mal, (char *)s2);
	}
	return (mal);
}
