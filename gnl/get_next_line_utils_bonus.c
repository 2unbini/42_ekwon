/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekwon <ekwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 17:11:37 by ekwon             #+#    #+#             */
/*   Updated: 2021/06/11 14:11:18 by ekwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		++len;
	return (len);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	size_t	s1_len;
	size_t	s2_len;
	char	*result;

	i = -1;
	j = 0;
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	if (!(result = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1))))
		return (0);
	while (++i < s1_len)
		result[i] = s1[i];
	while (i < s1_len + s2_len)
	{
		result[i] = s2[j];
		++i;
		++j;
	}
	result[i] = '\0';
	free(s1);
	s1 = 0;
	return (result);
}

char	*ft_strdup(char *s)
{
	int		i;
	char	*ptr;
	size_t	len;

	i = 0;
	len = ft_strlen(s);
	if (!(ptr = (char *)malloc(sizeof(char) * (len + 1))))
		return (0);
	while (s[i])
	{
		ptr[i] = s[i];
		++i;
	}
	ptr[i] = 0;
	return (ptr);
}

int		free_func(char **s)
{
	free(*s);
	*s = 0;
	return (-1);
}
