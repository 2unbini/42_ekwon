/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekwon <ekwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 15:51:01 by ekwon             #+#    #+#             */
/*   Updated: 2021/05/21 20:45:07 by ekwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int		save_free_tmp(char **tmp_fd, int i)
{
	char	*tmp_ptr;

	tmp_ptr = *tmp_fd;
	*tmp_fd = ft_strdup((tmp_ptr + i));
	free(tmp_ptr);
	return (1);
}

int		tmp_len(char **tmp_fd)
{
	int len;

	len = 0;
	while ((*tmp_fd)[len] != '\n' && (*tmp_fd)[len] != '\0')
		len++;
	return (len);
}

int		save_line(char **tmp_fd, char **line)
{
	int	i;

	i = 0;
	while ((*tmp_fd)[i] != '\n' && (*tmp_fd)[i] != '\0')
	{
		(*line)[i] = (*tmp_fd)[i];
		i++;
	}
	(*line)[i] = '\0';
	if ((*tmp_fd)[i] == '\n')
		return (i);
	//free(*tmp_fd);
	return (0);
}

int		get_next_line_bonus(int fd, char **line)
{
	static char	*tmp[OPEN_MAX];
	char		buf[BUFFER_SIZE + 1];
	int			status;
	int			read_size;
	int			i;

	i = 0;
	status = 0;
	buf[BUFFER_SIZE] = '\0';
	if (!tmp[fd])
		tmp[fd] = ft_strdup("");
	while ((read_size = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		tmp[fd] = ft_strjoin(tmp[fd], buf);
		if (!(*line = (char *)malloc(sizeof(char) * (tmp_len(&tmp[fd]) + 1))))
			return (-1);
		status = save_line(&tmp[fd], line);
		if (status > 0)
			return (save_free_tmp(&tmp[fd], status + 1));
	}
	status = save_line(&tmp[fd], line);
	if (status > 0)
		return (save_free_tmp(&tmp[fd], status + 1));
	return (0);
}
