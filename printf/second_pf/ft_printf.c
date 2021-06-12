/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekwon <ekwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 21:39:10 by ekwon             #+#    #+#             */
/*   Updated: 2021/06/12 17:40:44 by ekwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "getfunc.h"
#include "libft.h"

int		print_var(const char **s, t_format *f, va_list ap)
{
	/*
	if ('c' == **s)
		return (get_char(f, ap));
	if ('s' == **s)
		return (get_string(f, ap));
	*/
	if ('d' == **s || 'i' == **s)
		return (get_int(f, ap));
	/*
	if ('u' == **s)
		return (get_usint(f, ap));
	if ('p' == **s)
		return (get_pointer(f, ap));
	if ('x' == **s)
		return (get_shex(f, ap));
	if ('X' == **s)
		return (get_lhex(f, ap));
	*/
	return (-1);
}

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
			f->zero_space = 1;
		++(*s);
	}
}

void	check_width(const char **s, t_format *f, va_list ap)
{
	int		tmp;

	tmp = 0;
	while ('.' != **s && !ft_isalpha(**s))
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
	if (ft_isalpha(**s) && f->dot)
	{
		f->precision = 0;
		f->zero_space = 0;
	}
}

void	check_precision(const char **s, t_format *f, va_list ap, int tmp)
{
	check_precision_dot(s, f);
	f->precision = 0;
	while (!ft_isalpha(**s))
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
	f->minus_align = 0;
	f->dot = 0;
	f->precision = -1;
	f->width = 0;
	f->negative = 0;
	f->digit = 0;
	f->zero = 0;
}

int		ft_printf(const char *s, ...)
{
	va_list		ap;
	t_format	f;
	int			cnt;
	int			print_num;

	cnt = 0;
	va_start(ap, s);
	while (*s != '\0')
	{
		if (*s != '%')
		{
			cnt += write(1, s++, 1);
			continue;
		}
		init_flags(&f);
		check_flag(&s, &f);
		check_width(&s, &f, ap);
		if (f.dot)
			check_precision(&s, &f, ap, 0);
		if ((print_num = print_var(&s, &f, ap)) == -1)
			return (-1);
		cnt += print_num;
		++s;
	}
	return (cnt);
}
