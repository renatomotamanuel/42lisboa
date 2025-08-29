/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmota-ma <rmota-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 15:05:05 by rmota-ma          #+#    #+#             */
/*   Updated: 2025/08/29 19:05:17 by rmota-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_H
# define CUBE3D_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <errno.h>
# include <sys/time.h>
# include <string.h>
# include <fcntl.h>
# include "../minilibx-linux/mlx.h"

typedef struct s_game
{
	char **map;
	char **info;
	int		max_y;
}				t_game;

//GNL

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*get_next_line(int fd);
int		ft_linelen(char *str);
char	*ft_strjoin_gnl(char *s1, char *s2);
void	ft_free_bfr(char *str);
void	ft_bzero(void *s, size_t n);
char	*ft_strdup(const char *s);

//lib_inc.c

void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_strdup(const char *s);
char	*ft_strdupnonl(const char *s);
int	ft_strlen(const char *str);
void	*ft_free(char **strs);
int	ft_strncmp(const char *s1, const char *s2, size_t n);

#endif