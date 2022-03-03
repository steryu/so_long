/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svan-ass <svan-ass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 11:43:45 by svan-ass          #+#    #+#             */
/*   Updated: 2022/03/02 09:45:00 by svan-ass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <errno.h>

# include "./libft/libft.h"
# include "./ft_printf/ft_printf.h"
# include "./gnl/get_next_line.h"
# include "./mlx/mlx.h"

# define TILE_SIZE 32

typedef enum e_tiletype {
	FLOOR = '0',
	WALL = '1',
	COLLECTIBLE = 'C',
	PLAYER = 'P',
	EXIT = 'E',
}	t_tiletype;

typedef enum e_keycode {
	ESC = 53,
	UP = 13,
	DOWN = 1,
	RIGHT = 2,
	LEFT = 0,
}	t_keycode;

typedef struct s_map {
	char			content;
	int				x;
	int				y;
	struct s_map	*next;
}	t_map;

typedef struct s_player
{
	void	*img1;
	void	*img2;
	void	*img3;
	void	*img4;
	void	*img5;
	void	*img6;
	void	*img7;
	void	*img8;
	void	*current_img;
	int		x;
	int		y;
	int		count;
}	t_player;

typedef struct s_collectible {
	void	*img1;
	void	*img2;
	void	*img3;
	void	*img4;
	void	*img5;
	void	*img6;
	void	*img7;
	void	*img8;
	void	*img9;
	void	*current_img;
	int		count;
}	t_collectible;

typedef struct s_data {
	void			*mlx;
	void			*mlx_win;
	char			*addr;
	void			*image;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
	int				rows;
	int				cols;
	void			*cloudfloor_img;
	void			*cloud_img;
	void			*house_img;
	t_map			*map;
	t_player		player;
	t_collectible	collectible;
	int				move_count;
	int				exit_count;
}	t_data;

/* main */
int				main(int argc, char **argv);

/* map */
int				read_map(t_data *data, char *map_file);
int				check_map(t_data *data);
int				check_file_ext(char *map_file);
int				check_rectangular(char *new_line, int cols);

/* pixels */
void			put_pixel_to_frame(t_data *data, int x, int y, int color);
unsigned int	get_pixel_from_img(void *img, int x, int y);
int				render_screen(t_data *data);

/* sprites */
void			load_sprites(t_data *data);
void			load_player_l(t_data *data);
void			load_player_r(t_data *data);
void			put_images(t_data *data, int keycode);
void			load_player_r(t_data *data);
void			load_player_l(t_data *data);
int				animation(t_data *data);

/* events */
void			hook_events(t_data *data);
int				end_game(char *message);

#endif