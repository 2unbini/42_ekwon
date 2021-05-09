/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekwon <ekwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 16:34:34 by ekwon             #+#    #+#             */
/*   Updated: 2021/05/09 17:20:01 by ekwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	word_cnt(char const *s, char c)
{
	int i;
	int cnt;

	i = 0;
	cnt = 0;
	while (s[i])
	{
		if (s[i] == c)
		{
			cnt++;
			if (s[i + 1] == '\0')
				return (cnt);
		}
		i++;
	}
	cnt++;
	return (cnt);
}

static int	word_len(char const *s, char c, int idx)
{
	int len;

	len = 0;
	while (s[idx] && s[idx] != c)
	{
		idx++;
		len++;
	}
	return (len);
}

static char	*word_ptr(char const *s, char c, int *idx)
{
	char	*ptr;

	*len = 0;
	ptr = s[*idx];
	while (s[*idx] && s[*idx] != c)
		*idx += 1;
	return (ptr);
}

char		**ft_split(char const *s, char c)
{
	int		i;
	int		idx;
	int		len;
	char	**result;

	i = 0;
	idx = 0;
	if (!(result = (char **)malloc(sizeof(char *) * (word_cnt(s, c) + 1))))
		return (NULL);
	while (s[idx])
	{
		len = word_len(s, c, idx);
		if (!(result[i] = (char*)malloc(sizeof(char) * (len + 1))))
			return (NULL);
		result[i] = word_ptr(s, c, &idx);
		i++;
		idx++;
	}
	result[i] = 0;
	return (result);
}
