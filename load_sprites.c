/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svan-ass <svan-ass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 09:27:43 by svan-ass          #+#    #+#             */
/*   Updated: 2022/03/02 09:20:23 by svan-ass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_player_l(t_data *data)
{
	int		width;
	int		height;

	data->player.img1 = mlx_xpm_file_to_image(data->mlx, \
		"./sprites/wolkje/wolkjeL1.xpm", &width, &height);
	data->player.img2 = mlx_xpm_file_to_image(data->mlx, \
		"./sprites/wolkje/wolkjeL2.xpm", &width, &height);
	data->player.img3 = mlx_xpm_file_to_image(data->mlx, \
		"./sprites/wolkje/wolkjeL3.xpm", &width, &height);
	data->player.img4 = mlx_xpm_file_to_image(data->mlx, \
		"./sprites/wolkje/wolkjeL4.xpm", &width, &height);
	data->player.img5 = mlx_xpm_file_to_image(data->mlx, \
		"./sprites/wolkje/wolkjeL5.xpm", &width, &height);
	data->player.img6 = mlx_xpm_file_to_image(data->mlx, \
		"./sprites/wolkje/wolkjeL6.xpm", &width, &height);
	data->player.img7 = mlx_xpm_file_to_image(data->mlx, \
		"./sprites/wolkje/wolkjeL7.xpm", &width, &height);
	data->player.img8 = mlx_xpm_file_to_image(data->mlx, \
		"./sprites/wolkje/wolkjeL8.xpm", &width, &height);
	data->player.current_img = data->player.img1;
}

void	load_player_r(t_data *data)
{
	int		width;
	int		height;

	data->player.img1 = mlx_xpm_file_to_image(data->mlx, \
		"./sprites/wolkje/wolkje1.xpm", &width, &height);
	data->player.img2 = mlx_xpm_file_to_image(data->mlx, \
		"./sprites/wolkje/wolkje2.xpm", &width, &height);
	data->player.img3 = mlx_xpm_file_to_image(data->mlx, \
		"./sprites/wolkje/wolkje3.xpm", &width, &height);
	data->player.img4 = mlx_xpm_file_to_image(data->mlx, \
		"./sprites/wolkje/wolkje4.xpm", &width, &height);
	data->player.img5 = mlx_xpm_file_to_image(data->mlx, \
		"./sprites/wolkje/wolkje5.xpm", &width, &height);
	data->player.img6 = mlx_xpm_file_to_image(data->mlx, \
		"./sprites/wolkje/wolkje6.xpm", &width, &height);
	data->player.img7 = mlx_xpm_file_to_image(data->mlx, \
		"./sprites/wolkje/wolkje7.xpm", &width, &height);
	data->player.img8 = mlx_xpm_file_to_image(data->mlx, \
		"./sprites/wolkje/wolkje8.xpm", &width, &height);
	data->player.current_img = data->player.img1;
}

void	load_collectable(t_data *data)
{
	int		width;
	int		height;

	data->collectible.img1 = mlx_xpm_file_to_image(data->mlx, \
		"./sprites/star/star1.xpm", &width, &height);
	data->collectible.img2 = mlx_xpm_file_to_image(data->mlx, \
		"./sprites/star/star2.xpm", &width, &height);
	data->collectible.img3 = mlx_xpm_file_to_image(data->mlx, \
		"./sprites/star/star3.xpm", &width, &height);
	data->collectible.img4 = mlx_xpm_file_to_image(data->mlx, \
		"./sprites/star/star4.xpm", &width, &height);
	data->collectible.img5 = mlx_xpm_file_to_image(data->mlx, \
		"./sprites/star/star5.xpm", &width, &height);
	data->collectible.img6 = mlx_xpm_file_to_image(data->mlx, \
		"./sprites/star/star6.xpm", &width, &height);
	data->collectible.img7 = mlx_xpm_file_to_image(data->mlx, \
		"./sprites/star/star7.xpm", &width, &height);
	data->collectible.img8 = mlx_xpm_file_to_image(data->mlx, \
		"./sprites/star/star8.xpm", &width, &height);
	data->collectible.img9 = mlx_xpm_file_to_image(data->mlx, \
		"./sprites/star/star9.xpm", &width, &height);
	data->collectible.current_img = data->collectible.img1;
}

void	load_sprites(t_data *data)
{
	int		width;
	int		height;

	data->cloudfloor_img = mlx_xpm_file_to_image(data->mlx, \
		"./sprites/cloudfloor.xpm", &width, &height);
	data->cloud_img = mlx_xpm_file_to_image(data->mlx, \
		"./sprites/cloud2.xpm", &width, &height);
	load_player_r(data);
	load_collectable(data);
	data->house_img = mlx_xpm_file_to_image(data->mlx, \
		"./sprites/house.xpm", &width, &height);
}
