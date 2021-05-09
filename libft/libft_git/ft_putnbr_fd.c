/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekwon <ekwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 16:26:45 by ekwon             #+#    #+#             */
/*   Updated: 2021/05/09 23:12:46 by ekwon            ###   ########.fr       */
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

static void	make_put_string(int n, int fd, int sign)
{
	int		i;
	char	result[11];

	i = 0;
	while (n)
	{
		result[i] = n % 10 + '0';
		n /= 10;
		i++;
	}
	if (sign == -1)
		result[i] = '-';
	else
		i--;
	while (i >= 0)
	{
		write(fd, &result[i], 1);
		i--;
	}
}

void		ft_putnbr_fd(int n, int fd)
{
	int		i;
	int		sign;

	i = 0;
	sign = get_sign(n);
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (n == 0)
	{
		write(fd, "0", 1);
		return ;
	}
	n *= sign;
	make_put_string(n, fd, sign);
}
