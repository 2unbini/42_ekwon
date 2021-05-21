/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekwon <ekwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 15:51:01 by ekwon             #+#    #+#             */
/*   Updated: 2021/05/22 00:05:50 by ekwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		newline_idx(char **tmp_fd)
{
	int idx;

	idx = 0;
	while ((*tmp_fd)[idx] != '\0')
	{
		idx++;
		if ((*tmp_fd)[idx] == '\n')
			return (idx);
	}
	return (-1);
}

int		set_newline(char **tmp_fd, char **line, int nl_idx)
{
	char	*ptr;

	(*tmp_fd)[nl_idx] = '\0';
	ptr = *line;
	*line = ft_strdup(*tmp_fd);
	free(ptr);
	ptr = *tmp_fd;
	(*tmp_fd) = ft_strdup((*tmp_fd) + nl_idx + 1);
	free(ptr);
	return (1);
}

int		get_next_line(int fd, char **line)
{
	static char	*tmp[OPEN_MAX];
	char		buf[BUFFER_SIZE + 1];
	int			nl_idx;
	int			read_size;
	int			i;

	i = 0;
	if (!tmp[fd])
		tmp[fd] = ft_strdup("");
	*line = ft_strdup("");
	while ((read_size = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[read_size] = '\0';
		tmp[fd] = ft_strjoin(tmp[fd], buf);
		if ((nl_idx = newline_idx(&tmp[fd])) != -1)
			return (set_newline(&tmp[fd], line, nl_idx));
	}
	*line = ft_strdup((tmp[fd] + nl_idx));
	set_newline(&tmp[fd], line, nl_idx);
	return (0);
	// 개행있는지검사
	// 개행있음 =>  handle_nl => 개행전까지 line넣기 + 개행다음부분부터 backup에 update
	// readsize == -1 => handle_fail => free(back) return(-1)
	// 개행없음 => handle_eof => free(back) + *back = 0; return (0);
	// rs == -1
}
