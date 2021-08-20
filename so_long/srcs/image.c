/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekwon <ekwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 17:01:23 by ekwon             #+#    #+#             */
/*   Updated: 2021/08/20 23:19:19 by ekwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_window(t_game *game)
{
	game->win.win_width = game->map.col * TILE_SIZE;
	game->win.win_height = game->map.row * TILE_SIZE;
	game->mlx_ptr = mlx_init();
	if (game->mlx_ptr == 0)
		print_error("Mlx init failed");
	game->win.win_ptr = mlx_new_window(game->mlx_ptr, game->win.win_width,
			game->win.win_height, "so_long");
	if (game->win.win_ptr == 0)
		print_error("Window init failed");
}

void	init_image(t_game *game)
{
	game->img.img_ptr = mlx_png_file_to_image(game->mlx_ptr,
			"./textures/assets_.png", &game->img.width, &game->img.height);
	game->play.img_ptr = mlx_png_file_to_image(game->mlx_ptr,
			"./textures/imgs.png", &game->play.width, &game->play.height);
	if (game->img.img_ptr == NULL || game->play.img_ptr == NULL)
		print_error("Png file to image failed");
}

static void	put_image_to_win(t_game *game, int col, int row)
{
	mlx_put_image_to_window_scale(game->mlx_ptr, game->win.win_ptr,
		game->img.img_ptr, 64, 0, 64, 64, col * TILE_SIZE,
		row * TILE_SIZE, TILE_SIZE, TILE_SIZE, 0xFFFFFFFF);
	if (game->map.map[row][col] == '1')
		mlx_put_image_to_window_scale(game->mlx_ptr, game->win.win_ptr,
			game->img.img_ptr, 0, 0, 64, 64, col * TILE_SIZE,
			row * TILE_SIZE, TILE_SIZE, TILE_SIZE, 0xFFFFFFFF);
	if (game->map.map[row][col] == 'E')
		mlx_put_image_to_window_scale(game->mlx_ptr, game->win.win_ptr,
			game->img.img_ptr, 128, 0, 64, 64, col * TILE_SIZE,
			row * TILE_SIZE, TILE_SIZE, TILE_SIZE, 0xFFFFFFFF);
	if (game->map.map[row][col] == 'C')
		mlx_put_image_to_window_scale(game->mlx_ptr, game->win.win_ptr,
			game->play.img_ptr, 128, 0, 64, 64, col * TILE_SIZE,
			row * TILE_SIZE, TILE_SIZE, TILE_SIZE, 0xFFFFFFFF);
	if (game->map.map[row][col] == 'P' && game->player_fetched == false)
	{
		game->pos.x = col;
		game->pos.y = row;
		game->map.map[row][col] = '0';
		game->player_fetched = true;
	}
}

void	put_image(t_game *game)
{
	int	col;
	int	row;

	col = 0;
	row = 0;
	while (row < game->map.row)
	{
		col = 0;
		while (col < game->map.col)
		{
			put_image_to_win(game, col, row);
			++col;
		}
		++row;
	}
	mlx_put_image_to_window_scale(game->mlx_ptr, game->win.win_ptr,
		game->play.img_ptr, 0, 0, 64, 64, game->pos.x * TILE_SIZE,
		game->pos.y * TILE_SIZE, TILE_SIZE, TILE_SIZE, 0xFFFFFFFF);
}
