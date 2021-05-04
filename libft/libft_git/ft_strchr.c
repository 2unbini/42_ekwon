/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekwon <ekwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 11:53:04 by ekwon             #+#    #+#             */
/*   Updated: 2021/05/04 12:12:03 by ekwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*strchr(const char *s, int c)
{
	int i;

	i = 0;
	while (i < ft_strlen(s) + 1)
	{
		if (*s == c)
			return (s);
		i++;
		s++;
	}
	return (NULL);
}
