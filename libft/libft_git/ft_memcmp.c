/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekwon <ekwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 17:42:15 by ekwon             #+#    #+#             */
/*   Updated: 2021/05/05 20:18:11 by ekwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*uc_s1;
	unsigned char	*uc_s2;

	i = 0;
	uc_s1 = (unsigned char *)s1;
	uc_s2 = (unsigned char *)s2;
	while (i < n && *(uc_s1 + i) && *(uc_s2 + i))
	{
		if (*(uc_s1 + i) != *(uc_s2 + i))
			return (*(uc_s1 + i) - *(uc_s2 + i));
	}
	if (i == n)
		return (0);
	i--;
	return (*(uc_s1 + i) - *(uc_s2 + i));
}
