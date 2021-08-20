/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekwon <ekwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 17:02:31 by ekwon             #+#    #+#             */
/*   Updated: 2021/08/20 22:59:20 by ekwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	move_key_continue(int keycode, t_game *game)
{
	if (keycode == A && game->pos.x > 0
		&& game->map.map[game->pos.y][game->pos.x - 1] != '1')
	{
		game->pos.x -= 1;
		game->step_cnt += 1;
		printf("step: %d\n", game->step_cnt);
	}
	else if (keycode == D && game->pos.x < game->map.col - 1
		&& game->map.map[game->pos.y][game->pos.x + 1] != '1')
	{
		game->pos.x += 1;
		game->step_cnt += 1;
		printf("step: %d\n", game->step_cnt);
	}
}

static void	move_key(int keycode, t_game *game)
{
	if (keycode == W && game->pos.y > 0
		&& game->map.map[game->pos.y - 1][game->pos.x] != '1')
	{
		game->pos.y -= 1;
		game->step_cnt += 1;
		printf("step: %d\n", game->step_cnt);
	}
	else if (keycode == S && game->pos.y < game->map.row - 1
		&& game->map.map[game->pos.y + 1][game->pos.x] != '1')
	{
		game->pos.y += 1;
		game->step_cnt += 1;
		printf("step: %d\n", game->step_cnt);
	}
	else
	{
		move_key_continue(keycode, game);
	}
}

static void	put_player_image(t_game *game)
{
	mlx_put_image_to_window_scale(game->mlx_ptr, game->win_ptr,
		game->img.img_ptr, 64, 0, 64, 64, game->pos.x * TILE_SIZE,
		game->pos.y * TILE_SIZE, TILE_SIZE, TILE_SIZE, 0xFFFFFFFF);
	mlx_put_image_to_window_scale(game->mlx_ptr, game->win_ptr,
	game->play.img_ptr, 0, 0, 64, 64, game->pos.x * TILE_SIZE,
		game->pos.y * TILE_SIZE, TILE_SIZE, TILE_SIZE, 0xFFFFFFFF);
}

static void	remove_afterimage(t_game *game)
{
	mlx_put_image_to_window_scale(game->mlx_ptr, game->win_ptr,
		game->img.img_ptr, 64, 0, 64, 64, game->pos.p_x * TILE_SIZE,
		game->pos.p_y * TILE_SIZE, TILE_SIZE, TILE_SIZE, 0xFFFFFFFF);
}

int	key_press(int keycode, t_game *game)
{
	if (keycode == ESC)
		exit_game(game);
	game->pos.p_x = game->pos.x;
	game->pos.p_y = game->pos.y;
	move_key(keycode, game);
	if (game->map.map[game->pos.y][game->pos.x] == 'E'
		&& game->assets[COLLECTIVE] == 0)
		exit_game(game);
	if (game->map.map[game->pos.y][game->pos.x] == 'C')
	{
		--game->assets[COLLECTIVE];
		game->map.map[game->pos.y][game->pos.x] = 0;
	}
	remove_afterimage(game);
	put_player_image(game);
	return (0);
}
