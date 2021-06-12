/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ritoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekwon <ekwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 15:17:44 by ekwon             #+#    #+#             */
/*   Updated: 2021/06/12 16:10:40 by ekwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_sign(int n)
{
	if (n >= 0)
		return (1);
	else
		return (-1);
}

char		*ft_ritoa(int n)
{
	int			i;
	int			j;
	int			sign;
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
	sign = get_sign(n);
	n *= sign;
	while (n)
	{
		temp[i] = n % 10 + '0';
		n /= 10;
		i++;
	}
	return (temp);
}
