/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekwon <ekwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 16:55:51 by ekwon             #+#    #+#             */
/*   Updated: 2021/08/20 23:10:18 by ekwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <../mlx/mlx.h>
# include <../libft/libft.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdbool.h>

# define BUFF_SIZE 50
# define TILE_SIZE 48

# define X_EVENT_EXIT 17
# define X_EVENT_PRESS 2

# define WALL 1
# define EXIT 2
# define COLLECTIVE	3
# define PLAYER	4
# define ESC 53
# define W 13
# define A 0
# define S 1
# define D 2

typedef struct s_img
{
	void	*img_ptr;
	void	*data;
	int		width;
	int		height;
	int		bpp;
	int		size_l;
	int		endian;
}				t_img;

typedef struct s_pos
{
	int	x;
	int	y;
	int	p_x;
	int	p_y;
}				t_pos;

typedef struct s_map
{
	int		row;
	int		col;
	char	*map_string;
	char	**map;
}				t_map;

typedef struct s_game
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	img;
	t_img	play;
	t_pos	pos;
	t_map	map;
	int		win_width;
	int		win_height;
	int		assets[5];
	int		step_cnt;
	bool	player_fetched;
}				t_game;

void	init_window(t_game *game);
void	init_struct(t_game *game);
void	init_image(t_game *game);
void	put_image(t_game *game);
int		exit_game(t_game *game);
void	is_valid_input(int argc, char **argv);
void	free_all(t_game *game, int i);
int		key_press(int keycode, t_game *game);
void	count_assets(t_game *game);
void	open_map(char *file, t_game *game);
void	alloc_map(t_game *game);
void	parse_map(t_game *game);
void	error_exit(void);
void	print_error(char *message);
void	print_free_error(char *message, t_game *game);
void	print_free_all_error(char *message, t_game *game);

#endif
