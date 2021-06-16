/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putfunc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekwon <ekwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 14:36:14 by ekwon             #+#    #+#             */
/*   Updated: 2021/06/16 18:38:19 by ekwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		++len;
	return (len);
}

int		ft_putstring(char **str, int len)
{
	int	cnt;

	if (*str == 0)
		return (0);
	cnt = write(1, *str, len);
	free(*str);
	*str = 0;
	return (cnt);
}
