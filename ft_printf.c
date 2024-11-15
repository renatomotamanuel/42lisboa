/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmota-ma <rmota-ma@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 19:22:37 by rmota-ma          #+#    #+#             */
/*   Updated: 2024/11/14 13:47:39 by rmota-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
		else
		{
			var++;
			cnt += ft_check_char(&s[var], args);
		}
		var++;
	}
	va_end(args);
	return (cnt);
}

/*int main()
{
	ft_printf("%d\n", ft_printf(NULL));
	printf("%d\n", printf(NULL));
	//printf("%u", -1);
}*/