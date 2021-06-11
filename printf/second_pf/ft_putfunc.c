/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putfunc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekwon <ekwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 14:36:14 by ekwon             #+#    #+#             */
/*   Updated: 2021/06/10 22:12:50 by ekwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <unistd.h>

int		ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		++len;
	return (len);
}

int		ft_putstr(char **str)
{
	int		cnt;
	int		i;
	int		len;

	i = 0;
	cnt = 0;
	len = ft_strlen(*str);
	while (i < len)
	{
		write(1, &((*str)[i]), 1);
		++i;
		++cnt;
	}
	free(*str);
	*str = 0;
	return (cnt);
}

/*
int		ft_putstr(char **str)
{
	int		cnt;
	int		i;

	cnt = 0;
	i = ft_strlen(*str);
	while (--i >= 0)
	{
		write(1, &((*str)[i]), 1);
		(*str)[i] = 0;
		++cnt;
	}
	free(*str);
	*str = 0;
	return (cnt);
}
*/