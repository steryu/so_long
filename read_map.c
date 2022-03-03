/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svan-ass <svan-ass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 11:52:17 by svan-ass          #+#    #+#             */
/*   Updated: 2022/03/01 13:51:19 by svan-ass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_map	*add_new_point(char content, int x, int y)
{
	t_map	*point;

	point = (t_map *)malloc(sizeof(t_map));
	if (!point)
		end_game("oh oh malloc");
	point->content = content;
	point->x = x;
	point->y = y;
	point->next = NULL;
	return (point);
}

void	map_add_back(t_map **map, t_map *new)
{
	t_map	*temp;

	temp = *map;
	if (*map)
	{
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new;
	}
	else
		*map = new;
}

void	add_point_to_map(t_map **map, char *new_line, int y)
{
	t_map	*point;
	int		x;

	x = 0;
	while (new_line[x] && new_line[x] != '\n')
	{
		point = add_new_point(new_line[x], x, y);
		map_add_back(map, point);
		x++;
	}
}

int	read_map(t_data *data, char *map_file)
{
	int		fd;
	char	*new_line;

	check_file_ext(map_file);
	fd = open(map_file, O_RDONLY);
	if (fd < 0)
		end_game("Couldn't open file.");
	new_line = get_next_line(fd);
	if (!new_line)
		end_game("Couldn't read new line");
	data->cols = ft_strlen(new_line) - 1;
	while (new_line)
	{
		if (check_rectangular(new_line, data->cols) != 0)
			end_game("Map is not rectangular.");
		add_point_to_map(&data->map, new_line, data->rows);
		free(new_line);
		new_line = get_next_line(fd);
		data->rows++;
	}
	free(new_line);
	close(fd);
	return (0);
}
