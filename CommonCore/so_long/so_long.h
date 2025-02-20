/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmota-ma <rmota-ma@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 17:46:18 by rmota-ma          #+#    #+#             */
/*   Updated: 2025/02/19 12:44:03 by rmota-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <fcntl.h>
# include "./minilibx-linux/mlx.h"
# include "./minilibx-linux/mlx_int.h"
# define LC_HEX "0123456789abcdef"
# define UP_HEX "0123456789ABCDEF"
# define DEC "0123456789"
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		w;
	int		h;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		x;
	int		y;
}			t_data;

typedef struct s_map
{
	char	**loc;
	int		w;
	int		h;
}			t_map;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	int			w;
	int			h;
	int			x;
	int			y;
	int			e_x;
	int			e_y;
	int			c;
	int			e;
	int			p;
	int			moves;
	t_data		canvas;
	t_data		wall;
	t_data		white;
	t_data		black;
	t_data		black_player;
	t_data		white_player;
	t_map		map;
	t_map		temp;
	t_data		white_collectable;
	t_data		black_collectable;
	t_data		white_exit;
	t_data		black_exit;
}				t_game;

t_game	*game(void);
char	*get_next_line(int fd);
void	*ft_calloc(size_t nmemb, size_t size);
int		ft_linelen(char *str);
char	*ft_strjoin(char *s1, char *s2);
void	ft_free_buffer(char *str);
void	ft_bzero(void *s, size_t n);
int		ft_printf(const char *s, ...);
int		ft_putchar_fd(int c, int fd);
int		ft_putstr_fd(char *s, int fd);
int		ft_putunbr_base_fd(unsigned long bnb,
			int fd, char *base, unsigned int bs);
int		ft_putperc_fd(int fd);
int		ft_check_char(const char *s, va_list args);
int		ft_putnbr_base_fd(int n, int fd, char *base, int bs);
int		ft_putptr_fd(void *n, int fd, char *base, unsigned int bs);
void	map_def(char *addr, int height, int fd);
int		map_check(char *map);
int		map_is_rect(char *map, int fd, int var, int check);
int		map_is_valid(char *map, int var);
int		map_walls(char *map, int var);
int		top(char *map, int var, int var2);
int		bottom(char *map, int var2);
int		map_type(char *map);
int		map_exist(char *map);
void	init_window(t_game *mlx);
void	ins_map(t_game *ga);
void	list_declare(t_data *mlx);
int		animation(t_data *mlx);
t_data	load_img(char *path);
void	draw_img(t_data *src, t_data *dst, int x, int y);
int		run(t_game *ga);
int		handle_all(int keycode, t_game *ga);
int		handle_player(int keycode, t_game *ga);
int		handle_collect(t_game *ga, int var, int var2);
int		e_def(void);
int		run2(t_game *ga, int var, int var2);
void	*ft_free(char **strs);
int		close_game(t_game *ga);
void	temp_map_def(char *addr, int height, int fd);
int		flood_fill(char *addr);
void	fill(int x, int y);
size_t	ft_strlen(const char *str);
char	*ft_strdup(const char *s);
void	put_img(void *win_ptr,
			void *img_ptr, int x, int y);
int		p_def(void);
int		temp_p_def(void);

#endif