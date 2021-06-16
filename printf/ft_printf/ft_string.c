/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekwon <ekwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 20:11:15 by ekwon             #+#    #+#             */
/*   Updated: 2021/06/16 15:54:33 by ekwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char *s1)
{
	int		i;
	char	*ptr;

	i = 0;
	if (!(ptr = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1))))
		return (0);
	while (s1[i])
	{
		ptr[i] = s1[i];
		i++;
	}
	ptr[i] = 0;
	return (ptr);
}

void	ft_strcpy(char **dest, char *src, int *i)
{
	int len;
	int count;

	len = ft_strlen(src);
	count = 0;
	while (count < len)
	{
		(*dest)[(*i)] = src[count];
		count++;
		++(*i);
	}
}

char	*ft_strjoin(char **s, t_format *f, int print_len)
{
	int		i;
	int		j;
	char	c;
	char 	*result;

	i = f->len - print_len;
	j = 0;
	c = ' ';
	if (f->zero_space)
		c = '0';
	if (!(result = (char *)malloc(sizeof(char) * (f->len + 1))))
		return (0);
	while (j < f->len)
		result[j++] = c;
	j = 0;
	if (f->negative && f->zero_space)
	{
		result[0] = '-';
		++i;
		++j;
	}
	while (i < f->len)
		result[i++] = (*s)[j++];
	result[i] = 0;
	free(*s);
	*s = 0;
	return (result);
}
