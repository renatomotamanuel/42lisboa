/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmota-ma <rmota-ma@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 17:47:04 by rmota-ma          #+#    #+#             */
/*   Updated: 2025/08/30 16:26:12 by rmota-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

t_game *game(void)
{
	static t_game g;
	
	return (&g);
}

int texture_name(char *av)
{
    int var;

    var = 0;
    while(av[var])
        var++;
    var--;
    if(av[var] != 'm')
        return (1);
    var--;
    if(av[var] != 'p')
        return (1);
    var--;
    if(av[var] != 'x')
        return (1);
    var--;
    if(av[var] != '.')
        return (1);
    return (0);
}

int map_name(char *av)
{
    int var;

    var = 0;
    while(av[var])
        var++;
    var--;
    if(av[var] != 'b')
        return (1);
    var--;
    if(av[var] != 'u')
        return (1);
    var--;
    if(av[var] != 'c')
        return (1);
    var--;
    if(av[var] != '.')
        return (1);
    return (0);
}

int map_exists(char *av)
{
    int fd;

    fd = open(av, O_RDONLY);
	if (fd < 0)
		return (1);
	close(fd);
    return (0);
}

int	fill(int x, int y)
{
	if (x < 0 || y < 0 || y > game()->max_y || !game()->map[y][x] || game()->map[y][x] == '\n'|| game()->map[y][x] == ' ')
		return (printf("The map isn't closed.\n"),ft_free(game()->map), exit(1), 1);
	if ((game()->map[y][x] == 'o') || (game()->map[y][x] == '1') || (game()->map[y][x] == 'e') || (game()->map[y][x] == 'w') || (game()->map[y][x] == 'n') || (game()->map[y][x] == 's'))
		return (0);
	if (game()->map[y][x] == '0')
		game()->map[y][x] = 'o';
	else if (game()->map[y][x] == 'N')
		game()->map[y][x] = 'n';
	else if (game()->map[y][x] == 'E')
		game()->map[y][x] = 'e';
	else if (game()->map[y][x] == 'W')
		game()->map[y][x] = 'w';
	else if (game()->map[y][x] == 'S')
		game()->map[y][x] = 's';
	fill((x - 1), y);
	fill((x + 1), y);
	fill(x, (y - 1));
	fill(x, (y + 1));
	return (0);
}

int map_walls(char *av)
{
    int     fd;
    char    *line;
    int     var;
	int		var2;
    var = 0;
    fd = open(av, O_RDONLY);
    if (fd < 0)
        return (1);
    line = get_next_line(fd);
	while(var < 6)
	{
		if (line[0] == '\n')
		{
			free(line);
			line = get_next_line(fd);
			continue;
		}
		free(line);
		line = get_next_line(fd);
		var++;
	}
	while(line[0] == '\n')
	{
		free(line);
		line = get_next_line(fd);
	}
    while(line)
    {
		if(line[0] == '\n')
		{
			free(line);
			line = get_next_line(fd);
			continue;
		}
		var++;
        free(line);
        line = get_next_line(fd);
    }
	game()->map = ft_calloc(var + 1, sizeof(char *));
	close(fd);
	fd = open(av, O_RDONLY);
	if (fd < 0)
		return (1);
	var = 0;
	line = get_next_line(fd);
	while(var < 6)
	{
		if (line[0] == '\n')
		{
			free(line);
			line = get_next_line(fd);
			continue;
		}
		free(line);
		line = get_next_line(fd);
		var++;
	}
	while(line[0] == '\n')
	{
		free(line);
		line = get_next_line(fd);
	}
	var = 0;
    while(line)
    {
		if(line[0] == '\n')
		{
			free(line);
			line = get_next_line(fd);
			continue;
		}
		game()->map[var] = ft_strdup(line);
		var++;
        free(line);
        line = get_next_line(fd);
    }
	game()->max_y = var - 1;
	close(fd);
	var = 0;
	var2 = 0;
	while(game()->map[var2])
	{
		var = 0;
		while(game()->map[var2][var])
		{
			if ((game()->map[var2][var] == '0') || (game()->map[var2][var] == 'E') || (game()->map[var2][var] == 'W') || (game()->map[var2][var] == 'N') || (game()->map[var2][var] == 'S'))
				fill(var, var2);
			var++;
		}
		var2++;
	}
	return (0);
}

int	map_chars(char *av)
{
	int	var;
	int	fd;
	char *line;

	var = 0;
	fd = open(av, O_RDONLY);
	if (fd < 0)
		return (1);
	line = get_next_line(fd);
	if(!line)
		return (close(fd), printf("The map is missing.\n"), 1);
	int check = 0;
	while(var < 6)
	{
		if(line[0] == '\n')
		{
			free(line);
			line = get_next_line(fd);
			continue;
		}
		var++;
		free(line);
		line = get_next_line(fd);
	}
	while(line[0] == '\n')
	{
		free(line);
		line = get_next_line(fd);
	}
	while(line)
	{
		var = 0;
		if(line[0] == '\n')
		{
			while(line)
			{
				if(line[0] != '\n')
					return (close(fd), free(line), printf("Newline found inside the map.\n"), 1);
				free(line);
				line = get_next_line(fd);
			}
			break ;
		}
		while(line[var] && line[var] != '\n')
		{
			if(line[var] != '0' && line[var] != 'N' && line[var] != '1' && line[var] != 'E' && line[var] != 'S' && line[var] != 'W' && line[var] != ' ')
				return (close(fd), printf("Invalid character '%c' inside the map.\n%s %d", line[var], line, var), free(line),  1);
			if (line[var] == 'N' || line[var] == 'E' || line[var] == 'S' || line[var] == 'W')
				check++;
			var++;
		}
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	if (!check)
		return (printf("Player not found in the map.\n"), 1);
	else if (check != 1)
		return (printf("Too many players found in the map.\n"), 1);
	return (0);
}

void	freeandcopy(int pos, char *line)
{
	free(game()->info[pos]);
	game()->info[pos] = ft_strdupnonl(line);
}

void	set_gameinfo(char *line)
{
	if(!ft_strncmp(line, "NO ", 3))
		freeandcopy(0, line + 3);
	else if(!ft_strncmp(line, "SO ", 3))
		freeandcopy(1, line + 3);
	else if(!ft_strncmp(line, "WE ", 3))
		freeandcopy(2, line + 3);
	else if(!ft_strncmp(line, "EA ", 3))
		freeandcopy(3, line + 3);
	else if(!ft_strncmp(line, "F ", 2))
		freeandcopy(4, line + 2);
	else if(!ft_strncmp(line, "C ", 2))
		freeandcopy(5, line + 2);
}

void	init_gameinfo(void)
{
	int	var;

	var = 0;
	game()->info = ft_calloc(7, sizeof(char *));
	while(var < 6)
	{
		game()->info[var] = ft_strdup("init");
		var++;
	}
}

int	map_validate(char *av)
{
	char	*line;
	int		var;
	int		fd;
	char **check;
	fd = open(av, O_RDONLY);
	if (fd < 0)
		return (1);
	check = ft_calloc(7, sizeof(char *));
	init_gameinfo();
	check[0] = ft_strdup("NO ");
	check[1] = ft_strdup("SO ");
	check[2] = ft_strdup("WE ");
	check[3] = ft_strdup("EA ");
	check[4] = ft_strdup("F ");
	check[5] = ft_strdup("C ");
	line = get_next_line(fd);
	int var2;
	while(line && check[0])
	{
		var = 0;
		if(line[0] == '\n')
		{
			free(line);
			line = get_next_line(fd);
			continue ;
		}
		while(check[var])
		{
			if(!ft_strncmp(line, check[var], ft_strlen(check[var])))
			{
				var2 = 0;
				set_gameinfo(line);
				if (check[var + 1])
				{
					free(check[var]);
					while (check[var + var2])
						var2++;
					var2--;
					check[var] = ft_strdup(check[var + var2]);
					free(check[var + var2]);
					check[var + var2] = NULL;
				}
				else
				{
					free(check[var]);
					check[var] = NULL;
				}
				var = -1;
				break ;
			}
			var++;
		}
		if (var != -1)
			break ;
		free(line);
		line = get_next_line(fd);
		var++;
	}
	close(fd);
	if (check[0] || !line)
		return (ft_free(game()->info), ft_free(check), printf("The map file information is missing.\n"), 1);
	while(line)
	{
		free(line);
		line = get_next_line(fd);
	}
	free(check);
	return (0);
}

int	map_textures(void)
{
	int	var;
	int fd;

	var = 0;
	while (var < 4)
	{
		fd = open(game()->info[var], O_RDONLY);
		if (fd < 0)
			return (printf("Invalid texture \"%s\".\n", game()->info[var]), ft_free(game()->info), 1);
		close(fd);
		if (texture_name(game()->info[var]))
			return (printf("Invalid texture extension \"%s\". It should be a \".xpm\".\n", game()->info[var]), ft_free(game()->info), 1);
		var++;
	}
	return (0);
}

int	map_colors(void)
{
	int	var;
	int	check;

	var = 0;
	check = 0;
	while (game()->info[4][var])
	{
		if ((game()->info[4][var] > '9' || game()->info[4][var] < '0') && game()->info[4][var] != ',')
			return(1);
		if (game()->info[4][var] == ',')
			check++;
		var++;
	}
	if (check != 2 || var > 11 || var < 5)
		return(1);
	var = 0;
	check = 0;
	while (game()->info[5][var])
	{
		if ((game()->info[5][var] > '9' || game()->info[5][var] < '0') && game()->info[5][var] != ',')
			return(1);
		if (game()->info[5][var] == ',')
			check++;
		var++;
	}
	if (check != 2 || var > 11 || var < 5)
		return(1);
	return (0);
}

int parse_map(char **av)
{
	if (map_exists(av[1]))
		return (printf("The map doesn't exist.\n"), 1);
	if (map_name(av[1]))
		return (printf("The map extension isn't valid. It should be a \".cub\".\n"), 1);
	if (map_validate(av[1]))
		return (1);
	if (map_textures())
		return(1);
	if (map_colors())
		return (1);
	if (map_chars(av[1]))
		return (1);
	if (map_walls(av[1]))
        return(1);
	/*int var = 0;
	while(game()->map[var])
	{
		printf("map %s", game()->map[var]);
		var++;
	}
	ft_free(game()->map);*/
    return(0);
}

int main(int ac, char **av)
{
	if (ac < 2)
		return (printf("Insert a map name.\n"), 1);
	if (ac > 2)
		return (printf("Too many arguments.\n"), 1);
	if(parse_map(av))
		return (1);
    return (0);
}
