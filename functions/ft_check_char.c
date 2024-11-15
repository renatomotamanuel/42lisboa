/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmota-ma <rmota-ma@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 15:03:34 by rmota-ma          #+#    #+#             */
/*   Updated: 2024/11/15 22:51:03 by rmota-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_check_char(const char *s, va_list args)
{
	int	cnt;

	cnt = 0;
	if (*s == 'c')
		cnt += ft_putchar_fd(va_arg(args, int), 1);
	else if (*s == 's')
		cnt += ft_putstr_fd(va_arg(args, char *), 1);
	else if (*s == 'p')
		cnt += ft_putptr_fd(va_arg(args, void *), 1, LC_HEX, 16);
	else if (*s == 'd' || *s == 'i')
		cnt += ft_putnbr_base_fd(va_arg(args, int), 1, DEC, 10);
	else if (*s == 'u')
		cnt += ft_putunbr_base_fd(va_arg(args, unsigned), 1, DEC, 10);
	else if (*s == 'x')
		cnt += ft_putunbr_base_fd(va_arg(args, unsigned), 1, LC_HEX, 16);
	else if (*s == 'X')
		cnt += ft_putunbr_base_fd(va_arg(args, unsigned), 1, UP_HEX, 16);
	else if (*s == '%')
		cnt += ft_putchar_fd('%', 1);
	else
	{
		cnt += ft_putchar_fd('%', 1);
		cnt += ft_putchar_fd(*s, 1);
	}
	return (cnt);
}
