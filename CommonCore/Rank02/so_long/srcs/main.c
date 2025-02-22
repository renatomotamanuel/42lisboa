/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmota-ma <rmota-ma@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 17:46:07 by rmota-ma          #+#    #+#             */
/*   Updated: 2025/02/20 14:40:26 by rmota-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	main(int argc, char **argv)
{
	int	check;

	if (argc == 2 && argv[1][0])
		check = map_check(argv[1]);
	else
		return (ft_printf("Error\n"), 1);
	if (check == 0 || game()->map.w > 15 || game()->map.h > 8)
		return (ft_printf("Error\n"), 1);
	map_def(argv[1], 0, 0);
	e_def();
	p_def();
	init_window(game());
	return (0);
}

void	init_window(t_game *ga)
{
	ga->mlx = mlx_init();
	ga->win = mlx_new_window(ga->mlx, (ga->map.w * 128),
			(ga->map.h * 128), "so_long");
	ga->canvas.img = mlx_new_image(ga->mlx, (ga->map.w * 128),
			(ga->map.h * 128));
	ga->wall = load_img("textures/Wall.xpm");
	ga->white_player = load_img("textures/White_Queen.xpm");
	ga->black_player = load_img("textures/Black_Queen.xpm");
	ga->white_collectable = load_img("textures/White_Pawn.xpm");
	ga->black_collectable = load_img("textures/Black_Pawn.xpm");
	ga->white = load_img("textures/White.xpm");
	ga->black = load_img("textures/Black.xpm");
	ga->white_exit = load_img("textures/White_King.xpm");
	ga->black_exit = load_img("textures/Black_King.xpm");
	ga->canvas.addr = mlx_get_data_addr(ga->canvas.img,
			&ga->canvas.bits_per_pixel, &ga->canvas.line_length,
			&ga->canvas.endian);
	ga->moves = 0;
	ins_map(ga);
	mlx_key_hook(ga->win, handle_all, ga);
	mlx_hook(ga->win, 17, 0, close_game, ga);
	mlx_loop(ga->mlx);
}

int	run(t_game *ga)
{
	int	var2;
	int	var;

	var2 = 0;
	mlx_clear_window(ga->mlx, ga->win);
	mlx_put_image_to_window(ga->mlx, ga->win, ga->canvas.img, 0, 0);
	while (var2 < ga->map.h)
	{
		var = 0;
		while (var < ga->map.w)
		{
			if (var % 2 == 0 && ga->map.loc[var2][var] == 'P' && var2 % 2 == 0)
				put_img(ga->win, ga->white_player.img, ga->x, ga->y);
			if (var % 2 != 0 && ga->map.loc[var2][var] == 'P' && var2 % 2 == 0)
				put_img(ga->win, ga->black_player.img, ga->x, ga->y);
			if (var % 2 != 0 && ga->map.loc[var2][var] == 'P' && var2 % 2 != 0)
				put_img(ga->win, ga->white_player.img, ga->x, ga->y);
			if (var % 2 == 0 && ga->map.loc[var2][var] == 'P' && var2 % 2 != 0)
				put_img(ga->win, ga->black_player.img, ga->x, ga->y);
			var++;
		}
		var2++;
	}
	run2(ga, 0, 0);
	return (0);
}

int	run2(t_game *ga, int var, int var2)
{
	var2 = 0;
	while (var2 < ga->map.h)
	{
		var = 0;
		while (var < ga->map.w)
		{
			if (var % 2 == 0 && ga->map.loc[var2][var] == 'C' && var2 % 2 == 0)
				put_img(ga->win, ga->white_collectable.img,
					(var * 128), (var2 * 128));
			if (var % 2 != 0 && ga->map.loc[var2][var] == 'C' && var2 % 2 == 0)
				put_img(ga->win, ga->black_collectable.img,
					(var * 128), (var2 * 128));
			if (var % 2 != 0 && ga->map.loc[var2][var] == 'C' && var2 % 2 != 0)
				put_img(ga->win, ga->white_collectable.img,
					(var * 128), (var2 * 128));
			if (var % 2 == 0 && ga->map.loc[var2][var] == 'C' && var2 % 2 != 0)
				put_img(ga->win, ga->black_collectable.img,
					(var * 128), (var2 * 128));
			var++;
		}
		var2++;
	}
	return (0);
}

void	put_img(void *win_ptr, void *img_ptr, int x, int y)
{
	mlx_put_image_to_window(game()->mlx, win_ptr, img_ptr, x, y);
}
