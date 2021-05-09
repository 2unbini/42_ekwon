/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekwon <ekwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 14:01:49 by ekwon             #+#    #+#             */
/*   Updated: 2021/05/09 14:27:28 by ekwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*result;

	if (!(result = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (start < len && s[start])
	{
		*result = ((char *)s)[start];
		start++;
		result++;
	}
	*result = 0;
	return (result);
}
