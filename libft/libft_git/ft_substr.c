/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekwon <ekwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 14:01:49 by ekwon             #+#    #+#             */
/*   Updated: 2021/05/11 15:54:12 by ekwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*result;

	i = 0;
	if (!s)
		return (NULL);
	if (len > ft_strlen(s))
	{
		len = ft_strlen(s);
		if (len > start)
			len -= start;
	}
	if (!(result = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (i < len && start < ft_strlen(s) && s[start])
	{
		result[i] = ((char *)s)[start];
		start++;
		i++;
	}
	result[i] = 0;
	return (result);
}
