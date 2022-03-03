/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svan-ass <svan-ass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 11:49:15 by svan-ass          #+#    #+#             */
/*   Updated: 2022/03/01 14:16:33 by svan-ass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	init_game(t_data *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
		end_game("MLX initialization failed.");
	data->rows = 0;
	data->cols = 0;
	data->map = NULL;
}

static void	create_window(t_data *data)
{
	data->mlx_win = mlx_new_window(data->mlx, data->cols * TILE_SIZE, \
		data->rows * TILE_SIZE, "so_long");
	if (!data->mlx_win)
		end_game("Couldn't create a new window.");
	data->image = mlx_new_image(data->mlx, data->cols * TILE_SIZE, \
		data->rows * TILE_SIZE);
	data->addr = mlx_get_data_addr(data->image, &data->bits_per_pixel, \
		&data->line_length, &data->endian);
}

int	main(int argc, char **argv)
{
	t_data		data;

	if (argc != 2)
		end_game("Incorrect number of arguments.");
	init_game(&data);
	read_map(&data, argv[1]);
	check_map(&data);
	load_sprites(&data);
	create_window(&data);
	render_screen(&data);
	mlx_loop_hook(data.mlx, animation, &data);
	hook_events(&data);
	mlx_loop(data.mlx);
	return (0);
}
