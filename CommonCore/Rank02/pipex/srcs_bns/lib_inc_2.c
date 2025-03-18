/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_inc_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmota-ma <rmota-ma@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 19:37:22 by scorpot           #+#    #+#             */
/*   Updated: 2025/03/18 17:22:46 by rmota-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

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
