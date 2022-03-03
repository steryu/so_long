/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svan-ass <svan-ass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 09:46:40 by svan-ass          #+#    #+#             */
/*   Updated: 2022/03/01 13:31:17 by svan-ass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	player_animation(t_player *img)
{
	static int	i;

	if (i == 0)
		img->current_img = img->img1;
	if (i == 10)
		img->current_img = img->img2;
	if (i == 20)
		img->current_img = img->img3;
	if (i == 30)
		img->current_img = img->img4;
	if (i == 40)
		img->current_img = img->img5;
	if (i == 50)
		img->current_img = img->img6;
	if (i == 60)
		img->current_img = img->img7;
	if (i == 70)
	{
		img->current_img = img->img8;
		i = 0;
	}
	i++;
}

void	collectible_animation(t_collectible *img)
{
	static int	i;

	if (i == 0)
		img->current_img = img->img1;
	if (i == 10)
		img->current_img = img->img2;
	if (i == 20)
		img->current_img = img->img3;
	if (i == 30)
		img->current_img = img->img4;
	if (i == 40)
		img->current_img = img->img5;
	if (i == 50)
		img->current_img = img->img6;
	if (i == 60)
		img->current_img = img->img7;
	if (i == 70)
		img->current_img = img->img8;
	if (i == 80)
	{
		img->current_img = img->img9;
		i = 0;
	}
	i++;
}

int	animation(t_data *data)
{
	collectible_animation(&data->collectible);
	player_animation(&data->player);
	render_screen(data);
	return (0);
}
