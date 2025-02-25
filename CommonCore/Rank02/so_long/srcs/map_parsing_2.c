/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmota-ma <rmota-ma@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 21:42:11 by rmota-ma          #+#    #+#             */
/*   Updated: 2025/02/20 12:12:03 by rmota-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	bottom(char *map, int var2)
{
	int		var;
	int		fd;
	char	*line;

	fd = open(map, O_RDONLY);
	game()->map.h = var2;
	while (var2 > 1)
	{
		line = get_next_line(fd);
		free(line);
		var2--;
	}
	line = get_next_line(fd);
	var = 0;
	if (line[0] == '\n')
		return (free(line), 0);
	while (line[var] != '\0' && line[var] != '\n')
	{
		if (line[var] != '1')
			return (free(line), 0);
		var++;
	}
	free(line);
	return (1);
}

int	map_type(char *map)
{
	int	var;

	var = 0;
	while (map[var] != '\0')
	{
		if (map[var] == '.')
		{
			if (map[var + 1] == 'b' && map[var + 2] == 'e'
				&& map[var + 3] == 'r' && map[var + 4] == '\0')
				return (1);
			else
				return (0);
		}
		var++;
	}
	return (0);
}

int	map_exist(char *map)
{
	int		fd;
	char	*line;

	fd = open(map, O_RDONLY);
	line = get_next_line(fd);
	if (line == NULL)
		return (free(line), 0);
	return (free(line), 1);
}

size_t	ft_strlen(const char *str)
{
	int	a;

	a = 0;
	while (str[a] != '\0')
	{
		a++;
	}
	return (a);
}

char	*ft_strdup(const char *s)
{
	char	*mal;
	int		a;

	a = 0;
	mal = ft_calloc((ft_strlen(s) + 1), sizeof(char));
	if (!mal)
		return (NULL);
	while (s[a] != '\0')
	{
		mal[a] = s[a];
		a++;
	}
	return (mal);
}
