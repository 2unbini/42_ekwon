/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_slash.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekwon <ekwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 16:34:34 by ekwon             #+#    #+#             */
/*   Updated: 2021/09/16 19:35:50 by ekwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pipex.h"

static int	word_cnt(char const *s, char c)
{
	int	i;
	int	cnt;

	i = 0;
	cnt = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			cnt++;
			while (s[i] && s[i] != c)
				i++;
		}
		while (s[i] && s[i] == c)
			i++;
	}
	return (cnt);
}

static int	word_len(char const *s, char c, int idx)
{
	int	len;

	len = 0;
	while (s[idx] && s[idx] == c)
		idx++;
	while (s[idx] && s[idx] != c)
	{
		idx++;
		len++;
	}
	return (len);
}

static void	word_ptr(char *ptr, char const *s, char c, int *idx)
{
	while (s[*idx] && s[*idx] != c)
	{
		*ptr = ((char *)s)[*idx];
		*idx += 1;
		ptr++;
	}
	*ptr = '/';
	ptr++;
	*ptr = 0;
}

static int	my_malloc(char **result, size_t size, int index)
{
	int	i;

	result[index] = (char *)malloc(sizeof(char) * (size + 1));
	if (!result[index])
	{
		i = 0;
		while (i < index)
			free(result[i++]);
		free(result);
		return (1);
	}
	return (0);
}

char	**add_slash(char const *s, char c)
{
	int		i;
	int		idx;
	char	**result;

	i = 0;
	idx = 0;
	result = (char **)malloc(sizeof(char *) * (word_cnt(s, c) + 1));
	if (!s || !result)
		return (NULL);
	while (s[idx] && i < word_cnt(s, c))
	{
		if (c != s[idx])
		{
			if (my_malloc(result, word_len(s, c, idx) + 2, i))
				return (NULL);
			word_ptr(result[i], s, c, &idx);
			i++;
		}
		if (s[idx])
			idx++;
	}
	result[i] = 0;
	return (result);
}
