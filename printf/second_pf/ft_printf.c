/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekwon <ekwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 21:39:10 by ekwon             #+#    #+#             */
/*   Updated: 2021/06/10 22:16:33 by ekwon            ###   ########.fr       */
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
	return (1);
}

void	check_flag(const char **s, t_format *f)
{
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
		{
			tmp = va_arg(ap, int);
			f->asterisk += 1;
		}
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
		++(*s);
}

void	check_precision(const char **s, t_format *f, va_list ap)
{
	int		tmp;

	tmp = 0;
	while (!ft_isalpha(**s))
	{
		if ('*' == **s)
		{
			tmp = va_arg(ap, int);
			f->asterisk += 2;
		}
		else
			tmp = **s - '0';
		if (tmp <= 0)
		{
			++(*s);
			continue;
		}
		if (tmp < 0 && f->asterisk == 1)
		{
			f->width = 0;
			tmp *= -1;
		}
		f->precision = (f->precision * 10) + tmp;
		++(*s);
		if (f->asterisk == 2)
			f->zero_space = 1;
	}
}

int		ft_printf(const char *s, ...)
{
	va_list		ap;
	t_format	f;
	int			cnt;
	int			check;

	cnt = 0;
	check = 0;
	ft_memset(&f, 0, sizeof(t_format));
	va_start(ap, s);
	while (*s != '\0')
	{
		if (*s != '%')
		{
			cnt += write(1, s++, 1);
			continue;
		}
		s++;
		check_flag(&s, &f);
		check_width(&s, &f, ap);
		check_precision(&s, &f, ap);
		if ((check = print_var(&s, &f, ap)) == 0)
			return (-1);
		cnt += check;
		++s;
	}
	return (cnt);
}
