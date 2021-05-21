/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_22222.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekwon <ekwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 16:43:39 by ekwon             #+#    #+#             */
/*   Updated: 2021/05/20 11:44:18 by ekwon            ###   ########.fr       */
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

/*

static char *tmp[OPEN_MAX];

tmp[fd] 할당한 뒤, buffer 를 저장하고,
만약에 중간에 개행이 나온다면, 개행 전까지 line 에 복사해주고,
나머지를 남겨야 되는데, 개행의 인덱스가 i 라면,
tmp[fd][i+1] 부터의 값이 static tmp에 다시 저장돼야 함.
그 부분을 처리해주려면, 우선 tmp[fd]를 가리키는 포인터 ptr을 지정해준 뒤,
tmp[fd] = strdup(&tmp[fd][i+1]); 해서 할당해준 뒤,
기존 tmp였던 부분, 즉 ptr 이 가리키고 있는 애를 free(ptr) 해주면 됨.

*/

