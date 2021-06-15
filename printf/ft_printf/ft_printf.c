/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekwon <ekwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 21:39:10 by ekwon             #+#    #+#             */
/*   Updated: 2021/06/15 21:55:53 by ekwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "getfunc.h"
#include "libft.h"

int		print_var(const char **s, t_format *f, va_list ap)
{
	int	ret;

	ret = -1;
	if ('c' == **s)
		ret = get_char(f, ap);
	if ('s' == **s)
		ret = get_string(f, ap);
	if ('d' == **s || 'i' == **s)
		ret = get_int(f, ap);
	if ('u' == **s)
		ret = get_usint(f, ap);
	if ('p' == **s)
		ret = get_pointer(f, ap);
	if ('x' == **s)
		ret = get_shex(f, ap);
	if ('X' == **s)
		ret = get_lhex(f, ap);
	if ('%' == **s)
		ret = get_percent(f);
	++(*s);
	return (ret);
}

static void	flag_funcs(const char **s, t_format *f, va_list ap)
{
	init_flags(f);
	check_flag(s, f);
	check_width(s, f, ap);
	if ('.' == **s)
	{
		++(*s);
		f->dot = 1;
	}
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
		flag_funcs(&s, &f, ap);
		if (f.dot)
			check_precision(&s, &f, ap, 0);
		if ((print_num = print_var(&s, &f, ap)) == -1)
			return (-1);
		cnt += print_num;
	}
	va_end(ap);
	return (cnt);
}
