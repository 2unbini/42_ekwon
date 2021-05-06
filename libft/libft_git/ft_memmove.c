/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekwon <ekwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 17:34:14 by ekwon             #+#    #+#             */
/*   Updated: 2021/05/06 16:27:48 by ekwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t i;

	if ((unsigned char *)src >= (unsigned char *)dst)
	{
		i = 0;
		while (i < len)
		{
			*((unsigned char *)dst + i) = *((unsigned char *)src + i);
			i++;
		}
	}
	else
	{
		i = len - 1;
		while (i > 0)
		{
			*((unsigned char *)dst + i) = *((unsigned char *)src + i);
			i--;
		}
		*((unsigned char *)dst) = *((unsigned char *)src);
	}
	return (dst);
}
