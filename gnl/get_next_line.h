/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekwon <ekwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 15:51:27 by ekwon             #+#    #+#             */
/*   Updated: 2021/05/24 01:00:49 by ekwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#include <unistd.h>
#include <stdlib.h>

#define OPEN_MAX (1000)

size_t ft_strlen(char const *s);
char *ft_strjoin(char const *s1, char const *s2);
char *ft_strdup(const char *s);
int set_newline(char **tmp_fd, char **line, int nl_idx);
int set_eof(char **tmp_fd, char **line);
int free_error(char **tmp_fd, char **line);
int get_nl_idx(char **tmp_fd);
int get_next_line(int fd, char **line);

#endif
