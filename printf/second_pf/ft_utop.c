/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekwon <ekwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 15:17:44 by ekwon             #+#    #+#             */
/*   Updated: 2021/06/14 22:22:16 by ekwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_utop(unsigned long long n, char *base, t_format *f)
{
	int			i;
	int			j;
	static char	temp[20];

	i = 0;
	j = 0;
	while (j < 20)
		temp[j++] = '\0';
	if (n == 0)
	{
		f->zero = 1;
		temp[0] = (f->precision == 0) ? '\0' : '0';
		temp[1] = 'x';
		temp[2] = '0';
		return (temp);
	}
	while (n)
	{
		temp[i] = base[n % 16];
		n /= 16;
		i++;
	}
	temp[i] = 'x';
	temp[++i] = '0';
	return (temp);
}
