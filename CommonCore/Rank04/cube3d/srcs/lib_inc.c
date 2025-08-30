/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_inc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmota-ma <rmota-ma@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 18:14:43 by rmota-ma          #+#    #+#             */
/*   Updated: 2025/08/30 16:27:38 by rmota-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

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
