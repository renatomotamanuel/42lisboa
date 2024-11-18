/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmota-ma <rmota-ma@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 21:30:20 by rmota-ma          #+#    #+#             */
/*   Updated: 2024/09/03 00:23:45 by rmota-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strcmp(char *s1, char *s2)
{
	int	a;

	a = 0;
	while ((s1[a] == s2[a]) != '\0')
	{
		a++;
	}
	return (s1[a] - s2[a]);
}

void	ft_putstr(char *str)
{
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
}

int	main(int argc, char **argv)
{
	char	*str;
	int		j;

	j = 1;
	while (j < argc -1)
	{
		if (ft_strcmp(argv[j], argv[j + 1]) > 0)
		{
			str = argv[j];
			argv[j] = argv[j + 1];
			argv[j + 1] = str;
			j = 1;
		}
		else
			j++;
	}
	j = 1;
	while (j < argc)
	{
		ft_putstr(argv[j]);
		write (1, "\n", 1);
		j++;
	}
	return (0);
}
