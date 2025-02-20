/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmota-ma <rmota-ma@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 17:28:14 by rmota-ma          #+#    #+#             */
/*   Updated: 2025/02/20 12:12:09 by rmota-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	flood_fill(char *addr)
{
	int	var;
	int	var2;

	temp_map_def(addr, 0, 0);
	temp_p_def();
	fill(game()->x, game()->y);
	var2 = 0;
	while (var2 < game()->map.h)
	{
		var = 0;
		while (var < game()->map.w)
		{
			if (game()->temp.loc[var2][var] == 'E'
				|| game()->temp.loc[var2][var] == 'P'
					|| game()->temp.loc[var2][var] == 'C'
						|| game()->temp.loc[var2][var] == '0')
				return (ft_free(game()->temp.loc), 0);
			var++;
		}
		var2++;
	}
	ft_free(game()->temp.loc);
	return (1);
}

void	fill(int x, int y)
{
	if ((game()->temp.loc[y][x] == 'o') || (game()->temp.loc[y][x] == '1')
		|| (game()->temp.loc[y][x] == 'e') || (game()->temp.loc[y][x] == 'c'))
		return ;
	if (game()->temp.loc[y][x] == '0')
		game()->temp.loc[y][x] = 'o';
	if (game()->temp.loc[y][x] == 'E')
		game()->temp.loc[y][x] = 'e';
	if (game()->temp.loc[y][x] == 'P')
		game()->temp.loc[y][x] = 'p';
	if (game()->temp.loc[y][x] == 'C')
		game()->temp.loc[y][x] = 'c';
	fill((x - 1), y);
	fill((x + 1), y);
	fill(x, (y - 1));
	fill(x, (y + 1));
}

void	temp_map_def(char *addr, int height, int fd)
{
	char	*line;
	int		var;

	fd = open(addr, O_RDONLY);
	var = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		height++;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	game()->temp.loc = malloc(sizeof(char *) * (height + 1));
	fd = open(addr, O_RDONLY);
	line = get_next_line(fd);
	while (line != NULL)
	{
		game()->temp.loc[var] = ft_strdup(line);
		var++;
		free(line);
		line = get_next_line(fd);
	}
	game()->temp.loc[var] = NULL;
	free(line);
}
