/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekwon <ekwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 00:23:17 by ekwon             #+#    #+#             */
/*   Updated: 2021/08/20 16:54:12 by ekwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_free(char *s1, char *s2)
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
	result = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (!result)
	{
		free(s1);
		return (0);
	}
	while (++i < s1_len)
		result[i] = s1[i];
	while (i < s1_len + s2_len)
		result[i++] = s2[j++];
	result[i] = '\0';
	free(s1);
	return (result);
}
