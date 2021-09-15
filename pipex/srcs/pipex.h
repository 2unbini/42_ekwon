/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekwon <ekwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 12:33:58 by ekwon             #+#    #+#             */
/*   Updated: 2021/09/15 18:52:00 by ekwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/wait.h>

# include "../libft/libft.h"

typedef struct	s_child
{
	char	*file_in;
	char	**cmd_one;
	char	*exe_path;
}	t_child;

typedef struct	s_parent
{
	char	*file_out;
	char	**cmd_two;
	char	*exe_path;
}	t_parent;

typedef struct	s_data
{
	t_child		c;
	t_parent	p;
	char		**envp;
	char		**path;
	char		*pwd;
}	t_data;

void	print_error(char *message);
void	init_data(t_data *data, char **argv, char **envp);
int	find_line(char *target, char **envp);
int	parse_path(t_data *data);
char	*check_access(t_data data, char *cmd);
char	**ft_split_slash(char const *s, char c);

#endif