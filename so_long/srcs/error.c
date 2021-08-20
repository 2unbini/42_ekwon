/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekwon <ekwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 19:48:12 by ekwon             #+#    #+#             */
/*   Updated: 2021/08/20 20:44:35 by ekwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_exit(void)
{
	perror("Error\n");
	exit(1);
}

void	print_error(char *message)
{
	printf("Error\n%s.", message);
	exit(1);
}

void	print_free_error(char *message, t_game *game)
{
	printf("Error\n%s.", message);
	free(game->map.map_string);
	exit(1);
}

void	print_free_all_error(char *message, t_game *game)
{
	printf("Error\n%s.", message);
	free_all(game, game->map.row);
	exit(1);
}
