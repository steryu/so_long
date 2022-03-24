/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_screen.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svan-ass <svan-ass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 14:09:33 by svan-ass          #+#    #+#             */
/*   Updated: 2022/03/24 13:04:42 by svan-ass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	put_image_to_frame(t_data *data, void *img, int c, int r)
{
	int				x;
	int				y;
	unsigned int	pixel;

	x = 0;
	y = 0;
	while (y < TILE_SIZE)
	{
		x = 0;
		while (x < TILE_SIZE)
		{
			pixel = get_pixel_from_img(img, x, y);
			if (pixel != 0xFF000000)
				put_pixel_to_frame(data, (c * TILE_SIZE) + x, \
					(r * TILE_SIZE) + y, pixel);
			x++;
		}
		y++;
	}
}

void	put_images(t_data *data, int keycode)
{
	if (keycode == RIGHT)
		load_player_r(data);
	if (keycode == LEFT)
		load_player_l(data);
}

int	render_screen(t_data *data)
{
	t_map	*map;

	map = data->map;
	while (map)
	{
		put_image_to_frame(data, data->cloudfloor_img, map->x, map->y);
		if (map->content == WALL)
			put_image_to_frame(data, data->cloud_img, \
			map->x, map->y);
		if (map->content == COLLECTIBLE)
			put_image_to_frame(data, data->collectible.current_img, \
			map->x, map->y);
		if (map->content == EXIT)
			put_image_to_frame(data, data->house_img, \
			map->x, map->y);
		put_image_to_frame(data, data->player.current_img, \
		data->player.x, data->player.y);
		map = map->next;
	}
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->image, 0, 0);
	return (0);
}
