/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekwon <ekwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 12:02:05 by ekwon             #+#    #+#             */
/*   Updated: 2021/05/06 18:49:22 by ekwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	size_t	len;
	int		check;
	char	*tmp;

	i = 0;
	check = 0;
	len = ft_strlen(s);
	while (i < len + 1)
	{
		if (*(s + i) == (char)c)
		{
			tmp = ((char *)s + i);
			check = 1;
		}
		i++;
	}
	if (check == 1)
		return (tmp);
	else
		return (NULL);
}
