/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekwon <ekwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 11:40:51 by ekwon             #+#    #+#             */
/*   Updated: 2021/05/05 20:18:04 by ekwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t i;
	size_t dst_len;

	i = 0;
	dst_len = ft_strlen(dst);
	if (dstsize > 0 && dstsize > ft_strlen(dst))
	{
		while (dst[i])
			i++;
		while (i < dstsize - strlen(dst) - 1)
		{
			dst[i] = *(char *)src;
			i++;
			src++;
		}
		dst[i] = 0;
	}
	return (dst_len + ft_strlen(src));
}
