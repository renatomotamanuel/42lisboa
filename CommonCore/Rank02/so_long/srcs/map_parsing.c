/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmota-ma <rmota-ma@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 21:19:57 by rmota-ma          #+#    #+#             */
/*   Updated: 2025/02/20 12:12:06 by rmota-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	map_check(char *map)
{
	game()->c = 0;
	game()->e = 0;
	game()->p = 0;
	if (map_exist(map) == 0)
		return (0);
	else if (map_is_rect(map, 0, 0, 0) == 0)
		return (0);
	else if (map_is_valid(map, 0) == 0)
		return (0);
	else if (map_walls(map, 0) == 0)
		return (0);
	else if (map_type(map) == 0)
		return (0);
	else if (flood_fill(map) == 0)
		return (0);
	return (1);
}

int	map_is_rect(char *map, int fd, int var, int check)
{
	char	*line;

	fd = open(map, O_RDONLY);
	line = get_next_line(fd);
	while (line[check] != '\0' && line[check] != '\n')
		check++;
	free(line);
	line = get_next_line(fd);
	while (line != 0)
	{
		var = 0;
		if (line[var] != '\0' && line[var] != '\n')
		{
			while (line[var] != '\0' && line[var] != '\n')
				var++;
			if (var != check)
				return (free(line), 0);
		}
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	game()->map.w = check;
	return (1);
}

int	map_is_valid(char *map, int var)
{
	int		fd;
	char	*line;

	fd = open(map, O_RDONLY);
	line = get_next_line(fd);
	while (line != 0)
	{
		var = 0;
		while (line[var] != '\0' && line[var] != '\n')
		{
			if (line[var] == 'C')
				game()->c++;
			if (line[var] == 'E')
				game()->e++;
			if (line[var] == 'P')
				game()->p++;
			var++;
		}
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	if (game()->p != 1 || game()->e != 1 || game()->c < 1)
		return (0);
	return (1);
}

int	map_walls(char *map, int var)
{
	int		fd;
	char	*line;

	fd = open(map, O_RDONLY);
	line = get_next_line(fd);
	while (line != 0)
	{
		if (line[0] != '\0' && line[0] != '\n')
		{
			var = 0;
			while (line[var] != '\0' && line[var] != '\n')
			{
				if (line[var] != 'P' && line[var] != '1' && line[var] != '0'
					&& line[var] != 'E' && line[var] != 'C')
					return (free(line), 0);
				var++;
			}
			if (line[0] != '1' || line[var - 1] != '1' || top(map, 0, 0) == 0)
				return (free(line), 0);
		}
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	return (1);
}

int	top(char *map, int var, int var2)
{
	int		fd;
	char	*line;

	fd = open(map, O_RDONLY);
	line = get_next_line(fd);
	while (line != 0)
	{
		var2++;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	fd = open(map, O_RDONLY);
	line = get_next_line(fd);
	var = 0;
	while (line[var] != '\0' && line[var] != '\n')
	{
		if (line[var] != '1')
			return (free(line), 0);
		var++;
	}
	free(line);
	if (bottom(map, var2) == 0)
		return (0);
	return (1);
}
