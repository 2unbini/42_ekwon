/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekwon <ekwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 12:31:57 by ekwon             #+#    #+#             */
/*   Updated: 2021/06/07 22:54:10 by ekwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_wspace(char c)
{
	if (c == ' ' || c == '\t' || c == '\n'
			|| c == '\v' || c == '\f' || c == '\r')
		return (1);
	else
		return (0);
}

static int	check_first(char c, int *i)
{
	if ('+' == c || ft_isdigit(c))
	{
		if ('+' == c)
			*i += 1;
		return (1);
	}
	else if ('-' == c)
	{
		*i += 1;
		return (-1);
	}
	else if ('*' == c)
		return (2);
	else
		return (0);
}

int			ft_atoi(const char *str, va_list ap)
{
	long long	i;
	long long	sign;
	long long	result;

	i = 0;
	result = 0;
	sign = check_first(str[i], &i);
	if (sign == 0)
		return (0);
	else
	{
		if (sign == 2)
			return (va_arg(ap, int));
		while ('.' != str[i] && !ft_isalpha(str[i]) && ft_isdigit(str[i]))
		{
			result = (result * 10) + (str[i] - '0');
			i++;
		}
		return (sign * result);
	}
}
