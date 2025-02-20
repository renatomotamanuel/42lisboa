/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmota-ma <rmota-ma@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 16:57:35 by rmota-ma          #+#    #+#             */
/*   Updated: 2025/02/20 12:11:45 by rmota-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	map_def(char *addr, int height, int fd)
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
	game()->map.loc = malloc(sizeof(char *) * (height + 1));
	fd = open(addr, O_RDONLY);
	line = get_next_line(fd);
	while (line != NULL)
	{
		game()->map.loc[var] = ft_strdup(line);
		var++;
		free(line);
		line = get_next_line(fd);
	}
	game()->map.loc[var] = NULL;
	free(line);
}

int	p_def(void)
{
	int	var;
	int	var2;

	var2 = 0;
	while (var2 < game()->map.h)
	{
		var = 0;
		while (var < game()->map.w)
		{
			if (game()->map.loc[var2][var] == 'P')
			{
				game()->x = var * 128;
				game()->y = var2 * 128;
			}
			var++;
		}
		var2++;
	}
	return (1);
}

int	e_def(void)
{
	int	var;
	int	var2;

	var2 = 0;
	while (var2 < game()->map.h)
	{
		var = 0;
		while (var < game()->map.w)
		{
			if (game()->map.loc[var2][var] == 'E')
			{
				game()->e_x = var;
				game()->e_y = var2;
			}
			var++;
		}
		var2++;
	}
	return (1);
}

t_data	load_img(char *path)
{
	t_data	img;

	img.img = mlx_xpm_file_to_image(game()->mlx, path, &img.w, &img.h);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,
			&img.line_length, &img.endian);
	return (img);
}

void	*ft_free(char **strs)
{
	int	var;

	var = 0;
	while (strs[var] != NULL)
	{
		free(strs[var]);
		var++;
	}
	free(strs);
	return (NULL);
}
