/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekwon <ekwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 16:58:50 by ekwon             #+#    #+#             */
/*   Updated: 2021/08/20 23:34:06 by ekwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	map_function(char *file, t_game *game)
{
	open_map(file, game);
	count_assets(game);
	alloc_map(game);
	parse_map(game);
}

static void	init_function(t_game *game)
{
	init_window(game);
	init_image(game);
}

static void	hook_function(t_game *game)
{
	mlx_hook(game->win.win_ptr, X_EVENT_PRESS, 0, &key_press, game);
	mlx_hook(game->win.win_ptr, X_EVENT_EXIT, 0, &exit_game, game);
}

int	main(int argc, char **argv)
{
	t_game	game;

	is_valid_input(argc, argv);
	init_struct(&game);
	map_function(argv[1], &game);
	if (argc == 2)
	{
		init_function(&game);
		put_image(&game);
		hook_function(&game);
		mlx_loop(game.mlx_ptr);
	}
}
