/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekwon <ekwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 13:42:27 by ekwon             #+#    #+#             */
/*   Updated: 2021/05/07 16:51:22 by ekwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*ptr;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!ft_strlen(needle))
		return ((char *)haystack);
	while (i < len && haystack[i])
	{
		j = 0;
		if (haystack[i] == needle[j])
		{
			ptr = &((char *)haystack)[i];
			while (i + j < len && needle[j] && haystack[i + j] == needle[j])
			{
				j++;
			}
			if (j == ft_strlen(needle))
				return (ptr);
		}
		i++;
	}
	return (0);
}
