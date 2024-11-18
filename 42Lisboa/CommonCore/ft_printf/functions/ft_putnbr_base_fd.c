/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmota-ma <rmota-ma@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 19:26:48 by rmota-ma          #+#    #+#             */
/*   Updated: 2024/11/14 13:29:51 by rmota-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_base_fd(int n, int fd, char *base, int bs)
{
	int		cnt;
	int		mod;
	long	bnb;

	cnt = 0;
	bnb = n;
	if (fd < 0)
		return (-1);
	if (bnb < 0)
	{
		cnt += ft_putchar_fd('-', fd);
		bnb = -bnb;
	}
	if (bnb >= bs)
		cnt += ft_putnbr_base_fd(bnb / bs, fd, base, bs);
	mod = bnb % bs;
	cnt += ft_putchar_fd(base[mod], fd);
	return (cnt);
}
