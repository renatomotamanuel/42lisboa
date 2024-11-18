/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmota-ma <rmota-ma@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 14:27:45 by rmota-ma          #+#    #+#             */
/*   Updated: 2024/09/05 20:27:00 by rmota-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (*str)
	{
		len++;
		str++;
	}
	return (len);
}

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int	return_length(int size, char **strs, int size_sep)
{
	int	a;
	int	len;

	a = 0;
	len = size_sep * -1;
	while (a < size)
	{
		len += size_sep + ft_strlen(strs[a]);
		a++;
	}
	return (len);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*res;
	int		a;
	int		len;

	if (size == 0)
	{
		res = malloc(sizeof(char));
		if (res)
			res[0] = '\0';
		return (res);
	}
	len = return_length(size, strs, ft_strlen(sep));
	res = malloc(sizeof(char) * (len + 1));
	if (res == NULL)
		return (NULL);
	res[0] = '\0';
	a = 0;
	while (a < size)
	{
		ft_strcpy(res + ft_strlen(res), strs[a]);
		if (a + 1 < size)
			ft_strcpy(res + ft_strlen(res), sep);
		a++;
	}
	return (res);
}

/*int	main(void)
{
	char	*tab[4];
	tab[0] = "ya";
	tab[1] = "ye";
	tab[2] = "yo";
	tab[3] = "yi";
	printf("%s", ft_strjoin(4, tab, "joe"));
	return (0);
}*/