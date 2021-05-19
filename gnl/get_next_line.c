/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekwon <ekwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 14:44:18 by ekwon             #+#    #+#             */
/*   Updated: 2021/05/19 21:49:37 by ekwon            ###   ########.fr       */
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

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (*((char *)s) + len)
		len++;
	return (len);
}

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*s2;
	char	*ptr;

	i = 0;
	s2 = (char *)s1;
	if (!(ptr = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1))))
		return (NULL);
	while (s2[i])
	{
		ptr[i] = s2[i];
		i++;
	}
	ptr[i] = 0;
	return (ptr);
}

#include <stdio.h>

int			get_next_line(int fd, char **line)
{
	static char	*tmp[MAX_FILE];
	char		buf[BUFFER_SIZE + 1];
	int			idx;
	int			i;
	int			j;
	int			len;
	int			buf_size;

	i = 0;
	j = 0;
	idx = 0;
	len = 0;
	buf_size = 0;
	// buf 배열 0으로 초기화
	while (i <= BUFFER_SIZE)
		buf[i++] = 0;

	// buf 에 BUFFER_SIZE 만큼 read
	if (read(fd, buf, BUFFER_SIZE) == -1)
		return (-1);

	// tmp[fd]가 존재하면(BUFFER_SIZE 중간에 개행이 있어서 뒷부분 저장된 상태) -> 그 길이 구하기
	if (tmp[fd])
	{
		while (tmp[fd][len])
			len++;
	}

	// line 할당하기 -> BUFFER_SIZE + len + 1
	if (!(*line = (char *)ft_calloc(sizeof(char), (BUFFER_SIZE + len + 1))))
		return (-1);

	// tmp[fd]가 존재하면, tmp[fd][i]가 문장의 끝이 아닐 때까지 line 에 tmp 저장.
	i = 0;
	if (tmp[fd])
	{
		while (tmp[fd][i] != '\0')
		{
			(*line)[idx] = tmp[fd][i];
			idx++;
			i++;
		}
	}

	// buf[i]가 개행 혹은 파일의 끝이 아닐 때까지 line 에 buf 저장 + line 의 맨 끝에 널문자
	i = 0;
	while (buf[i] != '\n' && buf[i] != EOF)
	{
		(*line)[idx] = buf[i];
		idx++;
		i++;
		if (buf[i] == EOF)
		{
			free(tmp[fd]);
			return (0);
		}
	}
	(*line)[idx] = 0;

	// buf의 인덱스가 BUFFER_SIZE 보다 작고, buf[i] 가 파일의 끝이 아닐 때, tmp 에 나머지 저장.
	if (i < BUFFER_SIZE && buf[i] != EOF)
	{
		buf_size = BUFFER_SIZE - (i + 1);
		if (!(tmp[fd] = (char *)ft_calloc(sizeof(char), (buf_size + 1))))
			return (-1);
		while (j < buf_size && buf[i] != EOF)
		{
			tmp[fd][j] = buf[i];
			i++;
			j++;
		}
		tmp[fd][j] = 0;
	}
	if (buf[i] == EOF)
	{
		free(tmp[fd]);
		return (0);
	}
	return (1);
}
