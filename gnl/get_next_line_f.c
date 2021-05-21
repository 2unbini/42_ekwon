/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekwon <ekwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 14:44:18 by ekwon             #+#    #+#             */
/*   Updated: 2021/05/20 15:49:44 by ekwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#define MAX_FILE 256
//#define EOF -1

static void	*ft_calloc(size_t count, size_t size)
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

char		*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	char	*result;

	i = 0;
	if (!s1 || !s2)
		return (0);
	if (!(result = (char *)malloc(sizeof(char) *
					(ft_strlen(s1) + ft_strlen(s2)))))
		return (0);
	while (i < ft_strlen(s1))
	{
		result[i] = s1[i];
		i++;
	}
	while (i < ft_strlen(s1) + ft_strlen(s2))
	{
		result[i] = s2[i - ft_strlen(s2)];
		i++;
	}
	result[i] = 0;
	return (result);
}

size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t i;

	i = 0;
	if (!dst || !src || dstsize < 0)
		return (0);
	if (dstsize > 0)
	{
		while (((char *)src)[i] && i + 1 < dstsize)
		{
			dst[i] = ((char *)src)[i];
			i++;
		}
		dst[i] = 0;
	}
	return (ft_strlen(src));
}

#include <stdio.h>

int			get_next_line(int fd, char **line)
{
	static char	tmp[MAX_FILE][BUFFER_SIZE + 1];
	char		buf[BUFFER_SIZE + 1];
	int			i;
	int			j;

	i = 0;
	while (i <= BUFFER_SIZE)
		buf[i++] = 0;
	j = 0;
	while (tmp[fd][j] > 0)
		j++;
	if (read(fd, buf, BUFFER_SIZE) == -1)
		return (-1);
		/*
	i = 0;
	while (i < BUFFER_SIZE && buf[i] != EOF)
	{
		tmp[fd][j] = buf[i];
		i++;
		j++;
		if (buf[i] == EOF)
			tmp[fd][j++] = EOF;
	}
	tmp[fd][j] = '\0';
	*/
	if (!(*line = (char *)ft_calloc(sizeof(char), BUFFER_SIZE + j + 1)))
		return (-1);
	i = 0;
	while (tmp[fd][i] != '\0' && tmp[fd][i] != '\n' && tmp[fd][i] != EOF)
	{
		(*line)[i] = tmp[fd][i];
		i++;
		if (tmp[fd][i] == EOF)
		{
			(*line)[i] = '\0';
			return (0);
		}
	}
	i = 0;
	while (i < BUFFER_SIZE && buf[i] != '\n' && buf[i] != EOF)
	{
		(*line)[i] = buf[i];
		i++;
	}
	if (buf[i] == '\n')
		i++;
	j = 0;
	while (buf[i] != '\0' && buf[i] != EOF)
	{
		tmp[fd][j] = buf[i];
		j++;
		i++;
		if (buf[i] == EOF)
			tmp[fd][i++] = EOF;
	}
	tmp[fd][i] = '\0';
	return (1);
}
