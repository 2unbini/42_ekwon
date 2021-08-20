/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekwon <ekwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 13:42:27 by ekwon             #+#    #+#             */
/*   Updated: 2021/07/06 14:11:28 by ekwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *h, const char *n, size_t len)
{
	char	*ptr;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!ft_strlen(n))
		return ((char *)h);
	while (i < len && h[i])
	{
		j = 0;
		if (h[i] == n[j])
		{
			ptr = &((char *)h)[i];
			while (i + j < len && n[j] && h[i + j] == n[j])
			{
				j++;
			}
			if (j == ft_strlen(n))
				return (ptr);
		}
		i++;
	}
	return (0);
}
