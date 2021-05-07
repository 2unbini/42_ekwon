/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekwon <ekwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 17:34:14 by ekwon             #+#    #+#             */
/*   Updated: 2021/05/07 22:31:51 by ekwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*dst_cp;
	unsigned char	*src_cp;

	dst_cp = (unsigned char *)dst;
	src_cp = (unsigned char *)src;
	if (!dst_cp && !src_cp)
		return (NULL);
	if (src_cp > dst_cp)
		while (len)
		{
			*dst_cp++ = *src_cp++;
			len--;
		}
	else
	{
		dst_cp += len - 1;
		src_cp += len - 1;
		while (len)
		{
			*dst_cp-- = *src_cp--;
			len--;
		}
	}
	return (dst);
}
