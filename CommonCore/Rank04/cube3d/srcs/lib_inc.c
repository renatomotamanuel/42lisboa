/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_inc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmota-ma <rmota-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 18:14:43 by rmota-ma          #+#    #+#             */
/*   Updated: 2025/08/28 19:12:12 by rmota-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*temp;
	size_t			len;

	temp = malloc(nmemb * size);
	len = nmemb * size;
	if (size && (len / size) != nmemb)
		return (NULL);
	if (temp == NULL)
		return (NULL);
	if (nmemb == 0 || size == 0)
		return (temp);
	ft_bzero(temp, nmemb * size);
	return (temp);
}

char	*ft_strdup(const char *s)
{
	char	*mal;
	int		a;

	a = 0;
	mal = ft_calloc((ft_strlen(s) + 1), sizeof(char));
	if (!mal)
		return (NULL);
	while (s[a] != '\0')
	{
		mal[a] = s[a];
		a++;
	}
	mal[a] = '\0';
	return (mal);
}

char	*ft_strdupnonl(const char *s)
{
	char	*mal;
	int		a;

	a = 0;
	mal = ft_calloc((ft_strlen(s) + 1), sizeof(char));
	if (!mal)
		return (NULL);
	while (s[a] != '\0' && s[a] != '\n')
	{
		mal[a] = s[a];
		a++;
	}
	mal[a] = '\0';
	return (mal);
}

int	ft_strlen(const char *str)
{
	int	a;

	a = 0;
	while (str[a] != '\0')
	{
		a++;
	}
	return (a);
}

void	*ft_free(char **strs)
{
	int	var;

	var = 0;
	while (strs[var])
	{
		free(strs[var]);
		var++;
	}
	if(strs)
		free(strs);
	return (NULL);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	a;

	a = 0;
	while ((a < n) && (s1[a]) && (s2[a]))
	{
		if (s1[a] != s2[a])
		{
			return ((unsigned char)s1[a] - (unsigned char)s2[a]);
		}
		a++;
	}
	if (a < n)
	{
		return ((unsigned char)s1[a] - (unsigned char)s2[a]);
	}
	return (0);
}
