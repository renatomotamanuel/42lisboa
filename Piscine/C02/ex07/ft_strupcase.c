/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmota-ma <rmota-ma@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 23:44:25 by rmota-ma          #+#    #+#             */
/*   Updated: 2024/08/26 18:58:23 by rmota-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

char	*ft_strupcase(char *str);

char	*ft_strupcase(char *str)
{
	int	a;

	a = 0;
	while (str[a])
	{
		if (str[a] >= 'a' && str[a] <= 'z')
		{
			str[a] -= 32;
		}
		a++;
	}
	return (str);
}

/*int	main()
{
	char str[] = "asfasfADhjBADBAbfJHSBF0JH";
	char *str2;
	str2 = ft_strupcase(str);
	printf("%s\n", str2);
}*/