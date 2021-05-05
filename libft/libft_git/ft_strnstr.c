/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekwon <ekwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 13:42:27 by ekwon             #+#    #+#             */
/*   Updated: 2021/05/05 20:18:00 by ekwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	n_len;
	char	*tmp;
	char	*ptr;

	i = 0;
	n_len = 0;
	ptr = (char *)needle;
	while (i < len)
	{
		if (ft_strchr(haystack, *needle))
		{
			tmp = (char *)haystack;
			while (ft_strchr(haystack, *needle))
			{
				needle++;
				n_len++;
			}
			if (ft_strlen(needle) == n_len)
				return (tmp);
		}
		i++;
		haystack++;
	}
	return (NULL);
}
