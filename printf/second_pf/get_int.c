/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_int.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekwon <ekwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 13:00:13 by ekwon             #+#    #+#             */
/*   Updated: 2021/06/08 19:55:01 by ekwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int		max_len(t_format f, int arg)
{
	int result;

	f.digit = 1;
	result = 0;
	while (arg /= 10)
		++(f.digit);
	if (f.width >= f.precision && f.width >= f.digit)
		result = f.width;
	else if (f.precision >= f.width && f.precision >= f.digit)
		result = f.precision;
	else
		result = f.digit;
	return (result);
}

int		is_zero_space_valid(t_format f)
{
	if (f.zero_space == 0)
		return (0);
	else
	{
		if (f.minus_align || f.precision)
			return (0);
	}
	return (1);
}

int		alloc_ret(char **ret, int len, t_format f)
{
	if (is_zero_space_valid(f))
		*ret = my_alloc(len, sizeof(char), '0');
	*ret = my_alloc(len, sizeof(char), ' ');
	if (!(*ret))
		return (0);
	return (1);
}

void	set_istring(char **ret, int arg, t_format f)
{
	int		idx;

	idx = 0;
	if (f.precision && f.precision >= f.digit)
	{
		if (f.minus_align)
			while (idx < f.precision - f.digit)
				(*ret)[idx++] = '0';
		else
		{
			idx = f.width - f.precision;
			while (idx < f.precision)
				(*ret)[idx++] = '0';
		}
		while (arg)
		{
			(*ret)[idx++] = arg % 10 + '0';
			arg /= 10;
		}
	}
}

int		get_int(t_format f, va_list ap)
{
	char	*ret;
	int		arg;
	int		len;

	arg = va_arg(ap, int);
	len = max_len(f, arg);
	if (!(alloc_ret(&ret, len, f)))
		return (0);
	set_istring(&ret, arg, f);
	return (ft_putstr(ret));
}
