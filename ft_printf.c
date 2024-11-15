/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmota-ma <rmota-ma@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 19:22:37 by rmota-ma          #+#    #+#             */
/*   Updated: 2024/11/15 23:03:10 by rmota-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

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

/*int main()
{
	ft_printf("  %s%y %", "asa", "sas");
	printf("\n  %s%y %", "asa", "sas");
	//printf("%u", -1);
}*/