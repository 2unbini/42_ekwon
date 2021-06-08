/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putfunc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekwon <ekwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 14:36:14 by ekwon             #+#    #+#             */
/*   Updated: 2021/06/08 16:19:47 by ekwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

int		ft_putstr(char *str)
{
	char	*ptr;
	int		cnt;

	ptr = str;
	cnt = 0;
	while (*str != 0)
	{
		write(1, str, 1);
		++str;
		++cnt;
	}
	free(ptr);
	str = 0;
	return (cnt);
}
