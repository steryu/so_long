# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: svan-ass <svan-ass@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/28 11:40:17 by svan-ass          #+#    #+#              #
#    Updated: 2022/03/02 09:45:22 by svan-ass         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= so_long

CC			= gcc
CFLAGS		= -Wall -Werror -Wextra
MLXFLAGS 	= -framework OpenGL -framework AppKit

LIBFT 		= ./libft/libft.a
FT_PRINTF 	= ./ft_printf/libftprintf.a
MLX			= ./mlx/libmlx.a

all:		$(NAME)

$(LIBFT):
	$(MAKE) -C ./libft
$(FT_PRINTF):
	$(MAKE) -C ./ft_printf
$(MLX):
	$(MAKE) -C ./mlx

SRCS 		= main.c \
			read_map.c \
			render_screen.c \
			pixels.c \
			load_sprites.c \
			check_map.c \
			hook_events.c \
			animations.c \
			./gnl/get_next_line.c \
			./gnl/get_next_line_utils.c

OBJS		= $(SRCS:.c=.o)

$(NAME): 	$(OBJS) $(LIBFT) $(FT_PRINTF) $(MLX)
	$(CC) $(CFLAGS) $(MLXFLAGS) $(OBJS) $(LIBFT) $(FT_PRINTF) $(MLX) -o $(NAME)
	@echo "\033[0;32mDone!"

clean: 
	rm -f $(OBJS) $(LIBFT) $(FT_PRINTF) $(MLX)
	$(MAKE) -C libft/ clean
	$(MAKE) -C ft_printf/ clean
	$(MAKE) -C mlx/ clean

fclean: 	clean 
	rm -f $(NAME)
	$(MAKE) -C libft/ fclean
	$(MAKE) -C ft_printf/ fclean
	@echo "\033[0;32mClean!"

re:			fclean all

.PHONY: 	all clean fclean re

