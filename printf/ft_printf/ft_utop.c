/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekwon <ekwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 15:17:44 by ekwon             #+#    #+#             */
/*   Updated: 2021/06/16 17:58:32 by ekwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_utop(unsigned long long n, char *base, t_format *f)
{
	int			i;
	static char	temp[20];

	i = 0;
	while (i < 20)
		temp[i++] = '\0';
	temp[0] = '0';
	temp[1] = 'x';
	if (n == 0)
	{
		f->zero = 1;
		if (f->precision != 0)
			temp[2] = '0';
		return (temp);
	}
	i = 0;
	while (n)
	{
		temp[f->digit - (i + 1)] = base[n % 16];
		n /= 16;
		i++;
	}
	return (temp);
}
