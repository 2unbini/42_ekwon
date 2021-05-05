/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekwon <ekwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 12:31:57 by ekwon             #+#    #+#             */
/*   Updated: 2021/05/05 13:03:20 by ekwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	check_first(char c, int *i)
{
	if (c == '+' || ft_isdigit(c))
	{
		if (c == '+')
			*i += 1;
		return (1);
	}
	else if (c == '-')
	{
		*i += 1;
		return (-1);
	}
	else
		return (0);
}

int			ft_atoi(const char *str)
{
	int i;
	int sign;
	int result;

	i = 0;
	result = 0;
	sign = check_first(str[i], &i);
	if (sign == 0)
		return (0);
	else
	{
		while (str && ft_isdigit(str[i]))
		{
			result = (result * 10) + (str[i] - '0');
			i++;
		}
		return (sign * result);
	}
}
