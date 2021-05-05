/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekwon <ekwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 17:34:14 by ekwon             #+#    #+#             */
/*   Updated: 2021/05/05 17:39:19 by ekwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*tmp;

	i = 0;
	tmp = (unsigned char *)src;
	while (i < len)
	{
		*((unsigned char *)dst + i) = *(tmp + i);
		i++;
	}
	return (dst);
}
