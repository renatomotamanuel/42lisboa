/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmota-ma <rmota-ma@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 15:11:43 by rmota-ma          #+#    #+#             */
/*   Updated: 2024/08/28 21:36:52 by rmota-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <stdio.h>
#include <string.h>*/

char	*ft_strstr(char *str, char *to_find);

char	*ft_strstr(char *str, char *to_find)
{
	int	a;
	int	b;

	b = 0;
	if (to_find[0] == '\0')
	{
		return (str);
	}
	while (str[b])
	{
		a = 0;
		if (str[b] == to_find[0])
		{
			while (str [b + a] == to_find[a] && to_find[a] != '\0')
			{
				a++;
			}
			if (to_find[a] == '\0')
			{
				return (&str[b]);
			}
		}
		b++;
	}
	return (0);
}

/*int main() 
{
    char *texto = "Hello, world!";
    char subtexto[] = "\t";

    char *resultado = ft_strstr(texto, subtexto);
    printf("ft_strstr: %s \n", resultado);
	printf("strstr:    %s \n", strstr(texto, subtexto));
    return 0;
}*/
