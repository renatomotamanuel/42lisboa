/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmota-ma <rmota-ma@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 16:21:38 by rmota-ma          #+#    #+#             */
/*   Updated: 2024/11/14 13:30:13 by rmota-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr_fd(char *s, int fd)
{
	int	var;

	var = 0;
	if (fd < 0)
		return (-1);
	if (s == NULL)
		s = "(null)";
	while (s[var] != '\0')
	{
		write(fd, &s[var], 1);
		var++;
	}
	return (var);
}
