/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_22222.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekwon <ekwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 16:43:39 by ekwon             #+#    #+#             */
/*   Updated: 2021/05/19 21:10:06 by ekwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <limits.h>
#include <stdio.h>

void		*ft_calloc(size_t count, size_t size)
{
	void	*ptr;
	size_t	i;

	i = 0;
	if (!(ptr = (void *)malloc(size * count)))
		return (0);
	while (i < size * count)
	{
		*((unsigned char *)ptr + i) = 0;
		i++;
	}
	return (ptr);
}

size_t		ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (*((char *)s) + len)
		len++;
	return (len);
}

int			get_next_line(int fd, char **line)
{
	int			i;
	int			len;
	static char	*tmp[OPEN_MAX];
	char		buf[BUFFER_SIZE + 1];

	i = 0;
	len = 0;
	while (i <= BUFFER_SIZE)
		buf[i++] = 0;
	if (read(fd, buf, BUFFER_SIZE) == -1)
		return (-1);
	if (!(tmp[fd] = (char *)ft_calloc(sizeof(char), BUFFER_SIZE + 1)))
		return (-1);
	i = 0;
	while (i < BUFFER_SIZE && buf[i] != EOF)
	{
		tmp[fd][i] = buf[i];
		i++;
	}
	while (tmp[fd][len] != EOF && tmp[fd][len] != '\n')
		len++;
	if (!(*line = (char *)ft_calloc(sizeof(char), len + 1)))
		return (-1);
	i = 0;
	while (i < len)
	{
		*line[i] = tmp[fd][i];
		i++;
	}
	if (len < BUFFER_SIZE)
	{
		free(tmp[fd]);
		return (0);
	}
	return (1);
}
