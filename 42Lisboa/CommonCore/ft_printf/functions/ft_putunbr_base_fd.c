/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr_base_fd.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmota-ma <rmota-ma@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 16:30:56 by rmota-ma          #+#    #+#             */
/*   Updated: 2024/11/14 13:30:26 by rmota-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putunbr_base_fd(unsigned long bnb, int fd, char *base, unsigned int bs)
{
	int				cnt;
	unsigned int	mod;

	cnt = 0;
	if (fd < 0)
		return (-1);
	if (bnb >= bs)
		cnt += ft_putunbr_base_fd(bnb / bs, fd, base, bs);
	mod = bnb % bs;
	cnt += ft_putchar_fd(base[mod], fd);
	return (cnt);
}
