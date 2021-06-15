/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_util.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekwon <ekwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 21:39:10 by ekwon             #+#    #+#             */
/*   Updated: 2021/06/15 17:06:07 by ekwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "getfunc.h"
#include "libft.h"

void	check_flag(const char **s, t_format *f)
{
	++(*s);
	while ('-' == **s || '0' == **s)
	{
		if ('-' == **s)
		{
			f->minus_align = 1;
			f->zero_space = 0;
		}
		if ('0' == **s && 0 == f->minus_align)
		{
			f->zero_space = 1;
			f->pzero_space = 1;
		}
		++(*s);
	}
}

void	check_width(const char **s, t_format *f, va_list ap)
{
	int		tmp;

	tmp = 0;
	while ('.' != **s && !ft_isalpha(**s) && '%' != **s)
	{
		if ('*' == **s)
			tmp = va_arg(ap, int);
		else
			tmp = **s - '0';
		if (tmp < 0)
		{
			tmp *= -1;
			f->minus_align = 1;
			f->zero_space = 0;
		}
		f->width = (f->width * 10) + tmp;
		++(*s);
	}
	if ('.' == **s)
	{
		++(*s);
		f->dot = 1;
	}
}

void	check_precision_dot(const char **s, t_format *f)
{
	if ((ft_isalpha(**s) || '%' == **s) && f->dot)
	{
		f->precision = 0;
		f->zero_space = 0;
	}
}

void	check_precision(const char **s, t_format *f, va_list ap, int tmp)
{
	check_precision_dot(s, f);
	f->precision = 0;
	while (!ft_isalpha(**s) && '%' != **s)
	{
		if ('-' == **s)
		{
			f->precision = -1;
			while (!ft_isalpha(**s))
				++(*s);
			return ;
		}
		tmp = ('*' == **s) ? va_arg(ap, int) : **s - '0';
		if (tmp < 0)
		{
			++(*s);
			f->precision = -1;
			continue;
		}
		f->precision = (f->precision * 10) + tmp;
		if (f->precision != -1)
			f->zero_space = 0;
		++(*s);
	}
}

void	init_flags(t_format *f)
{
	f->zero_space = 0;
	f->pzero_space = 0;
	f->minus_align = 0;
	f->dot = 0;
	f->precision = -1;
	f->width = 0;
	f->negative = 0;
	f->digit = 0;
	f->zero = 0;
	f->len = 0;
}
