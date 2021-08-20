/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekwon <ekwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 16:55:40 by ekwon             #+#    #+#             */
/*   Updated: 2021/08/20 20:42:14 by ekwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	open_map(char *file, t_game *game)
{
	int		fd;
	char	*path;
	char	buff[BUFF_SIZE + 1];
	int		read_num;

	path = ft_strjoin("./map/", file);
	fd = open(path, O_RDONLY);
	free(path);
	if (fd == -1)
		error_exit();
	read_num = 1;
	game->map.map_string = ft_calloc(1, sizeof(char));
	if (!game->map.map_string)
		error_exit();
	while (read_num > 0)
	{
		read_num = read(fd, buff, BUFF_SIZE);
		buff[read_num] = 0;
		game->map.map_string = ft_strjoin_free(game->map.map_string, buff);
		if (!game->map.map_string)
			error_exit();
	}
	close(fd);
}

static void	count_map_row_col(t_game *game)
{
	int	i;
	int	col;
	int	row;

	i = 0;
	col = 0;
	row = 0;
	while (game->map.map_string[i])
	{
		++i;
		if (game->map.map_string[i] == '\n')
		{
			if (row == 0)
				col = i;
			++row;
			if (col != (i / row))
				print_free_error("Invalid map: different column number", game);
		}
	}
	game->map.col = col;
	game->map.row = row + 1;
}

void	count_assets(t_game *game)
{
	int	i;

	i = -1;
	while (game->map.map_string[++i])
	{
		if (game->map.map_string[i] == '1')
			++game->assets[WALL];
		else if (game->map.map_string[i] == 'E')
			++game->assets[EXIT];
		else if (game->map.map_string[i] == 'C')
			++game->assets[COLLECTIVE];
		else if (game->map.map_string[i] == 'P')
			++game->assets[PLAYER];
		else if (game->map.map_string[i] == '\n'
			|| game->map.map_string[i] == '0')
			continue ;
		else
			print_free_error("Invalid map: invalid asset found", game);
	}
	i = 0;
	game->assets[0] = 1;
	while (i < 5)
		if (game->assets[i++] == 0)
			print_free_error("Invalid map: More asset needed", game);
}

void	alloc_map(t_game *game)
{
	int	i;

	count_map_row_col(game);
	game->map.map = (char **)malloc(sizeof(char *) * (game->map.row + 1));
	if (!game->map.map)
	{
		perror("Error\n");
		free(game->map.map_string);
		exit(1);
	}
	i = 0;
	while (i < game->map.row + 1)
	{
		game->map.map[i] = (char *)malloc(sizeof(char *) * (game->map.col + 1));
		if (!game->map.map[i])
		{
			perror("Error\n");
			free_all(game, i);
			exit(1);
		}
		++i;
	}
}

void	parse_map(t_game *game)
{
	int		i;
	int		j;
	int		k;
	char	tmp;

	i = 0;
	k = 0;
	while (i < game->map.row)
	{
		j = 0;
		while (j < game->map.col)
		{
			tmp = game->map.map_string[k];
			if (tmp != '1' && (i == 0 || i == game->map.row - 1
					|| j == 0 || j == game->map.col - 1))
				print_free_all_error("Invalid map: Missing wall", game);
			game->map.map[i][j] = tmp;
			++j;
			++k;
		}
		++k;
		++i;
	}
}
