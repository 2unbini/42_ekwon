/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekwon <ekwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 14:44:18 by ekwon             #+#    #+#             */
/*   Updated: 2021/05/17 23:07:00 by ekwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#define MAX_FILE 256
#define EOF -1

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

int			get_next_line(int fd, char **line)
{
	static char	*tmp[MAX_FILE];
	char		buf[BUFFER_SIZE + 1];
	int			idx;
	int			i;
	int			len;

	i = 0;
	idx = 0;
	len = 0;
	buf[BUFFER_SIZE + 1] = 0;
	if (read(fd, buf, BUFFER_SIZE) == -1)
		return (-1);
	// tmp[fd] 가 존재하면 -> 버프 사이즈만큼 중간에 개행이 들어가면,
	if (tmp[fd])
	{
		// 널 문자를 만날 때ㅐ까지 len을 구하기
		while (tmp[fd][len])
			len++;
	}
	if (!(*line = (char *)ft_calloc(sizeof(char) * (BUFFER_SIZE + len + 1))))
		return (-1);
	if (tmp[fd])
	{
		while (tmp[fd][i])
		{
			(*line)[idx] = tmp[fd][i];
			idx++;
			i++;
		}
	}
	while (buf[idx] != '\n' && buf[idx] != EOF)
	{
		(*line)[idx] = buf[idx];
		idx++;
	}
	(*line)[idx] = 0;
	if (idx < BUFFER_SIZE && buf[idx] != EOF)
	{
		if (!(tmp[fd] = (char *)malloc(sizeof(char) * (BUFFER_SIZE - idx + 1))))
			return (-1);
		BUFFER_SIZE -= idx;
		while (i < BUFFER_SIZE + 1)
		{
			tmp[fd][i] = buf[idx];
			i++;
			idx++;
		}
	}
}
