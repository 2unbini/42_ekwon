/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekwon <ekwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 15:51:01 by ekwon             #+#    #+#             */
/*   Updated: 2021/05/23 17:01:46 by ekwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_nl_idx(char **tmp_fd)
{
	int idx;

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
	char *ptr;

	(*tmp_fd)[nl_idx] = '\0';
	ptr = *line;
	if (!(*line = ft_strdup(*tmp_fd)))
		return (-1);
	free(ptr);
	ptr = *tmp_fd;
	if (!((*tmp_fd) = ft_strdup((*tmp_fd) + nl_idx + 1)))
		return (-1);
	free(ptr);
	return (1);
}

int	set_eof(char **tmp_fd, char **line)
{
	char *ptr;

	ptr = *line;
	if (!(*line = ft_strdup(*tmp_fd)))
		return (-1);
	free(ptr);
	*tmp_fd = 0;
	free(*tmp_fd);
	return (0);
}

int	get_next_line(int fd, char **line)
{
	static char *tmp[OPEN_MAX];
	char	    buf[BUFFER_SIZE + 1];
	int	    nl_idx;
	int	    read_size;

	if (!tmp[fd])
		tmp[fd] = ft_strdup("");
	*line = ft_strdup("");
	while ((read_size = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[read_size] = '\0';
		tmp[fd] = ft_strjoin(tmp[fd], buf);
		if ((nl_idx = get_nl_idx(&tmp[fd])) != -1)
			return (set_newline(&tmp[fd], line, nl_idx));
	}
	if (read_size < 0)
	{
		free(tmp[fd]);
		return (-1);
	}
	if ((nl_idx = get_nl_idx(&tmp[fd])) != -1)
		return (set_newline(&tmp[fd], line, nl_idx));
	set_eof(&tmp[fd], line);
	return (0);
}
