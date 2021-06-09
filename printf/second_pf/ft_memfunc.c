/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memfunc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekwon <ekwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 14:30:20 by ekwon             #+#    #+#             */
/*   Updated: 2021/06/10 00:46:38 by ekwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t i;

	i = 0;
	while (i < len)
	{
		((unsigned char*)b)[i] = (unsigned char)c;
		i++;
	}
	return (b);
}

void	*my_alloc(size_t count, size_t size, char c)
{
	void	*ptr;
	size_t	i;

	i = 0;
	if (!(ptr = (void*)malloc(size * count)))
		return (0);
	while (i < size * count)
	{
		((unsigned char *)ptr)[i] = c;
		i++;
	}
	((unsigned char *)ptr)[i] = 0;
	return (ptr);
}
