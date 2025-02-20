/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmota-ma <rmota-ma@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 15:03:34 by rmota-ma          #+#    #+#             */
/*   Updated: 2025/02/20 12:11:26 by rmota-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int	ft_putchar_fd(int c, int fd)
{
	if (fd < 0)
		return (-1);
	write(fd, &c, 1);
	return (1);
}

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

int	ft_putunbr_base_fd(unsigned long bnb, int fd, char *b, unsigned int bs)
{
	int				cnt;
	unsigned int	mod;

	cnt = 0;
	if (fd < 0)
		return (-1);
	if (bnb >= bs)
		cnt += ft_putunbr_base_fd(bnb / bs, fd, b, bs);
	mod = bnb % bs;
	cnt += ft_putchar_fd(b[mod], fd);
	return (cnt);
}
