/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekwon <ekwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 21:39:10 by ekwon             #+#    #+#             */
/*   Updated: 2021/06/12 17:46:06 by ekwon            ###   ########.fr       */
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
