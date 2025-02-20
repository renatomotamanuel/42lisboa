/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmota-ma <rmota-ma@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 16:52:47 by rmota-ma          #+#    #+#             */
/*   Updated: 2025/02/20 12:11:56 by rmota-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	handle_all(int keycode, t_game *ga)
{
	if ((keycode == XK_d && ga->map.loc[ga->y / 128][ga->x / 128 + 1] != '1')
		|| (keycode == XK_s && ga->map.loc[ga->y / 128 + 1][ga->x / 128] != '1')
		|| (keycode == XK_a && ga->map.loc[ga->y / 128][ga->x / 128 - 1] != '1')
		|| (keycode == XK_w && ga->map.loc[ga->y / 128 - 1][ga->x / 128]
		!= '1'))
	{
		ga->moves += 1;
		ft_printf("Movements: %d\n", ga->moves);
	}
	if (keycode == XK_Escape)
		close_game(ga);
	handle_player(keycode, ga);
	run(ga);
	handle_collect(ga, 0, 0);
	return (0);
}

int	handle_player(int keycode, t_game *ga)
{
	if (keycode == XK_d && ga->map.loc[ga->y / 128][ga->x / 128 + 1] != '1')
	{
		ga->map.loc[(ga->y / 128)][(ga->x / 128)] = '0';
		ga->x += 128;
		ga->map.loc[ga->y / 128][ga->x / 128] = 'P';
	}
	if (keycode == XK_s && ga->map.loc[ga->y / 128 + 1][ga->x / 128] != '1')
	{
		ga->map.loc[(ga->y / 128)][(ga->x / 128)] = '0';
		ga->y += 128;
		ga->map.loc[ga->y / 128][ga->x / 128] = 'P';
	}
	if (keycode == XK_a && ga->map.loc[ga->y / 128][ga->x / 128 - 1] != '1')
	{
		ga->map.loc[(ga->y / 128)][(ga->x / 128)] = '0';
		ga->x -= 128;
		ga->map.loc[ga->y / 128][ga->x / 128] = 'P';
	}
	if (keycode == XK_w && ga->map.loc[ga->y / 128 - 1][ga->x / 128] != '1')
	{
		ga->map.loc[(ga->y / 128)][(ga->x / 128)] = '0';
		ga->y -= 128;
		ga->map.loc[ga->y / 128][ga->x / 128] = 'P';
	}
	return (0);
}

int	handle_exit(t_game *ga)
{
	if (ga->e_x % 2 == 0 && ga->e_y % 2 == 0)
		mlx_put_image_to_window(ga->mlx, ga->win, ga->white_exit.img,
			(ga->e_x * 128), (ga->e_y * 128));
	else if (ga->e_x % 2 != 0 && ga->e_y % 2 == 0)
		mlx_put_image_to_window(ga->mlx, ga->win, ga->black_exit.img,
			(ga->e_x * 128), (ga->e_y * 128));
	else if (ga->e_x % 2 != 0 && ga->e_y % 2 != 0)
		mlx_put_image_to_window(ga->mlx, ga->win, ga->white_exit.img,
			(ga->e_x * 128), (ga->e_y * 128));
	else if (ga->e_x % 2 == 0 && ga->e_y % 2 != 0)
		mlx_put_image_to_window(ga->mlx, ga->win, ga->black_exit.img,
			(ga->e_x * 128), (ga->e_y * 128));
	return (0);
}

int	handle_collect(t_game *ga, int var, int var2)
{
	int	c;

	c = 0;
	var2 = 0;
	while (var2 < ga->map.h)
	{
		var = 0;
		while (var < ga->map.w)
		{
			if (ga->map.loc[var2][var] == 'C')
				c++;
			var++;
		}
		var2++;
	}
	if (c == 0)
	{
		handle_exit(ga);
		if (ga->map.loc[ga->e_y][ga->e_x] == 'P')
		{
			ft_printf("You Won!\n");
			close_game(ga);
		}
	}
	return (0);
}

int	close_game(t_game *ga)
{
	mlx_destroy_image(ga->mlx, ga->black_exit.img);
	mlx_destroy_image(ga->mlx, ga->white_exit.img);
	mlx_destroy_image(ga->mlx, ga->canvas.img);
	mlx_destroy_image(ga->mlx, ga->wall.img);
	mlx_destroy_image(ga->mlx, ga->white.img);
	mlx_destroy_image(ga->mlx, ga->black.img);
	mlx_destroy_image(ga->mlx, ga->white_player.img);
	mlx_destroy_image(ga->mlx, ga->black_player.img);
	mlx_destroy_image(ga->mlx, ga->white_collectable.img);
	mlx_destroy_image(ga->mlx, ga->black_collectable.img);
	mlx_destroy_window(ga->mlx, ga->win);
	mlx_destroy_display(ga->mlx);
	free(ga->mlx);
	ft_free(ga->map.loc);
	exit(0);
}
