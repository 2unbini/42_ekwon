/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekwon <ekwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 20:11:15 by ekwon             #+#    #+#             */
/*   Updated: 2021/06/16 17:26:14 by ekwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strdup(char *s1)
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

static void	ft_strjoin_cont(char **s, char **result, t_format *f, int print_len)
{
	int		i;
	int		j;
	char	c;

	i = f->len - print_len;
	j = 0;
	c = ' ';
	if (f->zero_space)
		c = '0';
	while (j < f->len)
		(*result)[j++] = c;
	j = 0;
	if (f->negative && f->zero_space)
	{
		(*result)[0] = '-';
		++i;
		++j;
	}
	while (i < f->len)
		(*result)[i++] = (*s)[j++];
	(*result)[i] = 0;
}

char		*ft_strjoin(char **s, t_format *f, int print_len)
{
	char	*result;

	if (!(result = (char *)malloc(sizeof(char) * (f->len + 1))))
	{
		free(*s);
		*s = 0;
		return (0);
	}
	ft_strjoin_cont(s, &result, f, print_len);
	free(*s);
	*s = 0;
	return (result);
}
