/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekwon <ekwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 14:23:08 by ekwon             #+#    #+#             */
/*   Updated: 2021/07/06 13:50:23 by ekwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	front;
	size_t	rear;
	char	*result;

	if (!s1 || !set)
		return (NULL);
	front = 0;
	rear = ft_strlen(s1);
	while (front < rear && ft_strchr(set, *(s1 + front)))
		front++;
	while (rear > 0 && ft_strchr(set, *(s1 + rear - 1)))
		rear--;
	if (front > rear)
		return (ft_strdup(""));
	result = (char *)malloc(sizeof(char) * (rear - front + 1));
	if (!result)
		return (NULL);
	ft_strlcpy(result, (s1 + front), (rear - front + 1));
	return (result);
}
