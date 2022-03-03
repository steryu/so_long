/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_events.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svan-ass <svan-ass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 12:59:18 by svan-ass          #+#    #+#             */
/*   Updated: 2022/03/02 09:47:12 by svan-ass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_action(t_data *data, int r, int c)
{
	t_map	*map;

	map = data->map;
	ft_printf("Moves: %d\n", ++data->move_count);
	while (map)
	{
		if (map->x == r && map->y == c && map->content != WALL)
		{
			if (map->content == COLLECTIBLE)
			{
				data->collectible.count--;
				map->content = FLOOR;
			}
			if (map->content == EXIT)
			{
				if (data->collectible.count == 0)
					end_game(NULL);
			}
			return (1);
		}
		map = map->next;
	}
	return (0);
}

int	key_hook(int keycode, t_data *data)
{
	if (keycode == ESC)
	{
		ft_printf("bye bye:)\n");
		mlx_destroy_window(data->mlx, data->mlx_win);
		end_game(NULL);
	}
	if (keycode == UP)
		if (check_action(data, data->player.x, data->player.y - 1))
			data->player.y -= 1;
	if (keycode == DOWN)
		if (check_action(data, data->player.x, data->player.y + 1))
			data->player.y += 1;
	if (keycode == LEFT)
		if (check_action(data, data->player.x - 1, data->player.y))
			data->player.x -= 1;
	if (keycode == RIGHT)
		if (check_action(data, data->player.x + 1, data->player.y))
			data->player.x += 1;
	put_images(data, keycode);
	return (0);
}

void	hook_events(t_data *data)
{
	mlx_key_hook(data->mlx_win, key_hook, data);
	mlx_hook(data->mlx_win, 17, (1L << 17), end_game, NULL);
}

int	end_game(char *message)
{
	if (message)
	{
		ft_printf("%s\n%s\n", "Error", message);
		exit(EXIT_FAILURE);
	}
	else
	{	
		ft_printf("Good job:)\n");
		exit(EXIT_SUCCESS);
	}
}
