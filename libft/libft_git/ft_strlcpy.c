/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekwon <ekwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 11:20:11 by ekwon             #+#    #+#             */
/*   Updated: 2021/05/04 11:27:05 by ekwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	int i;

	i = 0;
	if (dstsize > 0)
	{
		while (src && (i < dstsize - 1))
		{
			dst[i] = src;
			i++;
			src++;
		}
		dst[i] = 0;
	}
	return (ft_strlen(src));
}
