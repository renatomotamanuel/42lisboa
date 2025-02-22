/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmota-ma <rmota-ma@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 19:22:37 by rmota-ma          #+#    #+#             */
/*   Updated: 2025/01/16 14:30:40 by rmota-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		var;
	int		cnt;

	if (!s)
		return (-1);
	va_start(args, s);
	var = 0;
	cnt = 0;
	while (s[var] != '\0')
	{
		if (s[var] != '%' && s[var] != '\0')
			cnt += ft_putchar_fd(s[var], 1);
		else if (s[var + 1] != '\0')
		{
			var++;
			cnt += ft_check_char(&s[var], args);
		}
		else
			cnt += ft_putchar_fd('%', 1);
		var++;
	}
	va_end(args);
	return (cnt);
}

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

void	sort(int **a, int **b, int len)
{
	if (stack_sorted(a, len) == 1)
		return ;
	if (len <= 5)
		sort_small(a, b, len);
	else
		sort_big(a, b, len);
}

long	ft_atoi_check(char *str)
{
	int			a;
	long int	res;
	long int	count;

	a = 0;
	res = 0;
	count = 1;
	while (str[a] == ' ' || (str[a] > 8 && str[a] < 14))
	{
		a++;
	}
	if ((str[a] == '-' || str[a] == '+'))
	{
		if (str[a] == '-')
			count *= -1;
		a++;
	}
	while (str[a] >= '0' && str[a] <= '9')
	{
		res = res * 10 + (str[a] - '0');
		if (res > INT_MAX || res < INT_MIN)
			return (2147483648);
		a++;
	}
	return (count * res);
}
