/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekwon <ekwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 22:40:10 by ekwon             #+#    #+#             */
/*   Updated: 2021/06/11 23:10:25 by ekwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strcpy(char **dest, char *src, int *i)
{
	int len;
	int count;

	len = ft_strlen(src);
	count = 0;
	while (count < len)
	{
		(*dest)[(*i)] = src[count];
		count++;
		++(*i);
	}
}
