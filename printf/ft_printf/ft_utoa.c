/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekwon <ekwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 15:17:44 by ekwon             #+#    #+#             */
/*   Updated: 2021/06/16 18:38:53 by ekwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_utoa(unsigned int n, int len)
{
	int			i;
	int			j;
	static char	temp[10];

	i = 0;
	j = 0;
	while (j < 10)
		temp[j++] = '\0';
	if (n == 0)
	{
		temp[0] = '0';
		return (temp);
	}
	while (n)
	{
		temp[len - (i + 1)] = n % 10 + '0';
		n /= 10;
		i++;
	}
	return (temp);
}
