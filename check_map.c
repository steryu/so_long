/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svan-ass <svan-ass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 12:22:46 by svan-ass          #+#    #+#             */
/*   Updated: 2022/03/02 10:21:32 by svan-ass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_rectangular(char *new_line, int cols)
{
	int	line_length;

	line_length = ft_strlen(new_line);
	if (ft_strchr(new_line, '\n'))
		line_length -= 1;
	return (line_length - cols);
}

int	check_file_ext(char *map_file)
{
	size_t	file_length;
	char	*ber;

	file_length = ft_strlen(map_file);
	ber = ft_strnstr(map_file, ".ber", file_length);
	if (ber)
	{
		if (ft_strlen(ber) != 4)
			end_game("Invalid map file, must end in .ber");
	}
	else if (!ber)
		end_game("Invalid map file, must end in .ber");
	return (0);
}

static int	check_map_contents(t_data *data)
{
	t_map	*map;

	map = data->map;
	while (map)
	{
		if (map->content == PLAYER)
		{
			data->player.x = map->x;
			data->player.y = map->y;
			data->player.count++;
		}
		if (map->content == COLLECTIBLE)
			data->collectible.count++;
		if (map->content == EXIT)
			data->exit_count++;
		map = map->next;
	}
	if (data->player.count >= 1 && data->collectible.count >= 1 \
	&& data->exit_count >= 1)
		return (1);
	return (0);
}

static void	check_map_characters(t_map *map, int c, int r)
{
	if (ft_strchr("01CEP", map->content) == 0)
		end_game("Invalid characters in map.");
	if (map->x == 0 || map->y == 0 || map->x == c - 1 || map->y == r - 1)
		if (map->content != WALL)
			end_game("Map is not surounded by walls.");
}

int	check_map(t_data *data)
{
	t_map	*map;
	int		c;
	int		r;

	map = data->map;
	c = data->cols;
	r = data->rows;
	data->player.count = 0;
	data->collectible.count = 0;
	data->exit_count = 0;
	while (map)
	{
		check_map_characters(map, c, r);
		map = map->next;
	}
	if (check_map_contents(data) == 0)
		end_game("Map does not contain at least 1 exit, 1 star and 1 player.");
	return (0);
}
