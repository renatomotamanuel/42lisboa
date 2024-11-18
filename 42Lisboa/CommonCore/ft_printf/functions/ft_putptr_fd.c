/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmota-ma <rmota-ma@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 16:21:38 by rmota-ma          #+#    #+#             */
/*   Updated: 2024/11/14 13:30:06 by rmota-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putptr_fd(void *n, int fd, char *base, unsigned int bs)
{
	int				cnt;
	long unsigned	bnb;

	cnt = 0;
	if (fd < 0)
		return (-1);
	if (!n)
		return (ft_putstr_fd("(nil)", 1));
	bnb = (unsigned long)n;
	cnt += ft_putstr_fd("0x", 1);
	cnt += ft_putunbr_base_fd(bnb, fd, base, bs);
	return (cnt);
}
