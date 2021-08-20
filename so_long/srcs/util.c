/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekwon <ekwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 17:04:47 by ekwon             #+#    #+#             */
/*   Updated: 2021/08/20 23:17:46 by ekwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_struct(t_game *game)
{
	int	i;

	i = 0;
	while (i < 5)
		game->assets[i++] = 0;
	game->step_cnt = 0;
	game->pos.x = 0;
	game->pos.y = 0;
	game->pos.p_x = 0;
	game->pos.p_y = 0;
	game->player_fetched = false;
}

int	exit_game(t_game *game)
{
	mlx_destroy_image(game->mlx_ptr, game->img.img_ptr);
	mlx_destroy_image(game->mlx_ptr, game->play.img_ptr);
	mlx_destroy_window(game->mlx_ptr, game->win.win_ptr);
	exit(0);
}

void	is_valid_input(int argc, char **argv)
{
	if (argc != 2)
		print_error("Invalid number of arguments");
	if (ft_strncmp(argv[1] + ft_strlen(argv[1]) - 4, ".ber", 4) != 0)
		print_error("Invalid file");
}

void	free_all(t_game *game, int i)
{
	while (i >= 0)
	{
		free(game->map.map[i]);
		--i;
	}
	free(game->map.map);
	free(game->map.map_string);
}
