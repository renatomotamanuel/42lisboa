/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmota-ma <rmota-ma@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 16:55:53 by rmota-ma          #+#    #+#             */
/*   Updated: 2025/02/20 12:11:49 by rmota-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	my_mlx_pixel_get(t_data *data, int x, int y)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	return (*(unsigned int *)dst);
}

void	draw_img(t_data *src, t_data *dst, int x, int y)
{
	int	sx;
	int	sy;

	sy = 0;
	while (sy < 128)
	{
		sx = 0;
		while (sx < 128)
		{
			my_mlx_pixel_put(dst, sx + x, sy + y,
				my_mlx_pixel_get(src, sx, sy));
			sx++;
		}
		sy++;
	}
}

void	ins_map(t_game *ga)
{
	int	var2;
	int	var;

	var2 = 0;
	while (var2 < ga->map.h)
	{
		var = 0;
		while (var < ga->map.w)
		{
			if (var % 2 == 0 && ga->map.loc[var2][var] != '1' && var2 % 2 == 0)
				draw_img(&ga->white, &ga->canvas, (var * 128), (var2 * 128));
			if (var % 2 != 0 && ga->map.loc[var2][var] != '1' && var2 % 2 == 0)
				draw_img(&ga->black, &ga->canvas, (var * 128), (var2 * 128));
			if (var % 2 != 0 && ga->map.loc[var2][var] != '1' && var2 % 2 != 0)
				draw_img(&ga->white, &ga->canvas, (var * 128), (var2 * 128));
			if (var % 2 == 0 && ga->map.loc[var2][var] != '1' && var2 % 2 != 0)
				draw_img(&ga->black, &ga->canvas, (var * 128), (var2 * 128));
			if (ga->map.loc[var2][var] == '1')
				draw_img(&ga->wall, &ga->canvas, (var * 128), (var2 * 128));
			var++;
		}
		var2++;
	}
}

t_game	*game(void)
{
	static t_game	g;

	return (&g);
}
