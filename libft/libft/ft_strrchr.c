/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekwon <ekwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 12:02:05 by ekwon             #+#    #+#             */
/*   Updated: 2021/05/11 14:25:34 by ekwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	int		check;
	char	*tmp;

	i = 0;
	check = 0;
	while (i < ft_strlen(s) + 1)
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
