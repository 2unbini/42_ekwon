/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekwon <ekwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 21:17:27 by ekwon             #+#    #+#             */
/*   Updated: 2021/05/06 16:46:03 by ekwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*ptr;

	i = 0;
	if (!(ptr = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1))))
		return (NULL);
	while (*(s1 + i))
	{
		ptr[i] = *(s1 + i);
		i++;
	}
	ptr[i] = 0;
	return (ptr);
}
