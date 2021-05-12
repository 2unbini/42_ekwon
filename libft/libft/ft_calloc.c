/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekwon <ekwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 20:23:23 by ekwon             #+#    #+#             */
/*   Updated: 2021/05/07 21:50:55 by ekwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;
	size_t	i;

	i = 0;
	if (!(ptr = (void*)malloc(size * count)))
		return (NULL);
	while (i < size * count)
	{
		((unsigned char *)ptr)[i] = 0;
		i++;
	}
	return (ptr);
}
