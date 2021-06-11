/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekwon <ekwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 15:51:27 by ekwon             #+#    #+#             */
/*   Updated: 2021/06/11 13:39:21 by ekwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>

# define OPEN_MAX 1000

size_t	ft_strlen(char *s);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(char *s);
int		free_func(char **s);
int		set_newline(char **tmp_fd, char **line, int nl_idx);
int		set_eof(char **tmp_fd, char **line);
int		free_error(char **tmp_fd, char **line);
int		get_nl_idx(char **tmp_fd);
int		get_next_line(int fd, char **line);

#endif
