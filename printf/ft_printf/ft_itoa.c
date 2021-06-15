/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekwon <ekwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 15:17:44 by ekwon             #+#    #+#             */
/*   Updated: 2021/06/15 21:35:26 by ekwon            ###   ########.fr       */
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

static char	*min_int(char *temp)
{
	int n;
	int i;

	n = 214748364;
	i = 0;
	temp[0] = '8';
	while (n)
	{
		temp[++i] = n % 10 + '0';
		n /= 10;
	}
	return (temp);
}

char		*ft_itoa(int n)
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
	if (n == -2147483648)
		return (min_int(temp));
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
