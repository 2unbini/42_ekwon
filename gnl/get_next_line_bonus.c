/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekwon <ekwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 15:51:01 by ekwon             #+#    #+#             */
/*   Updated: 2021/06/11 14:10:40 by ekwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	get_nl_idx(char **tmp_fd)
{
	int	idx;

	idx = 0;
	while ((*tmp_fd)[idx] != '\0')
	{
		if ((*tmp_fd)[idx] == '\n')
			return (idx);
		idx++;
	}
	return (-1);
}

int	set_newline(char **tmp_fd, char **line, int nl_idx)
{
	char	*ptr;

	(*tmp_fd)[nl_idx] = '\0';
	ptr = *line;
	if ((*line = ft_strdup(*tmp_fd)) == 0)
	{
		free(*tmp_fd);
		*tmp_fd = 0;
		return (-1);
	}
	free(ptr);
	ptr = *tmp_fd;
	if ((*tmp_fd = ft_strdup((*tmp_fd) + nl_idx + 1)) == 0)
	{
		free(*tmp_fd);
		*tmp_fd = 0;
		return (-1);
	}
	free(ptr);
	return (1);
}

int	set_eof(char **tmp_fd, char **line)
{
	char	*ptr;

	ptr = *line;
	if ((*line = ft_strdup(*tmp_fd)) == 0)
	{
		free(*tmp_fd);
		*tmp_fd = 0;
		return (-1);
	}
	free(ptr);
	ptr = 0;
	free(*tmp_fd);
	*tmp_fd = 0;
	return (0);
}

int	free_error(char **tmp_fd, char **line)
{
	free(*tmp_fd);
	*tmp_fd = 0;
	free(*line);
	*line = 0;
	return (-1);
}

int	get_next_line(int fd, char **line)
{
	static char	*tmp[OPEN_MAX];
	char		buf[BUFFER_SIZE + 1];
	int			nl_idx;
	int			read_size;

	if (fd < 0 || fd > OPEN_MAX || BUFFER_SIZE <= 0 || !line)
		return (-1);
	if (!tmp[fd])
		tmp[fd] = ft_strdup("");
	*line = ft_strdup("");
	if (tmp[fd] == 0 || *line == 0)
		return (free_error(&tmp[fd], line));
	while ((read_size = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[read_size] = '\0';
		if ((tmp[fd] = ft_strjoin(tmp[fd], buf)) == 0)
			return (free_func(&tmp[fd]));
		if ((nl_idx = get_nl_idx(&tmp[fd])) != -1)
			return (set_newline(&tmp[fd], line, nl_idx));
	}
	if (read_size < 0)
		return (free_error(&tmp[fd], line));
	if ((nl_idx = get_nl_idx(&tmp[fd])) != -1)
		return (set_newline(&tmp[fd], line, nl_idx));
	return (set_eof(&tmp[fd], line));
}
