/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekwon <ekwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 21:39:10 by ekwon             #+#    #+#             */
/*   Updated: 2021/06/07 22:55:03 by ekwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int		print_var(const char **s, va_list ap)
{
	if ('c' == **s)
		return (get_char(s, ap));
	if ('s' == **s)
		return (get_string(s, ap));
	if ('d' == **s || 'i' == **s)
		return (get_int(s, ap));
	if ('u' == **s)
		return (get_usint(s, ap));
	if ('p' == **s)
		return (get_pointer(s, ap));
	if ('x' == **s)
		return (get_shex(s, ap));
	if ('X' == **s)
		return (get_lhex(s, ap));
	return (-1);
}

void	check_flag(const char **s, t_format f)
{
	while ('-' == **s || '0' == **s)
	{
		if ('-' == **s)
			f.minus_align = 1;
		if ('0' == **s && 0 == f.minus_align)
			f.zero_space = 1;
		++s;
	}
}

void	check_opt(const char **s, t_format f, va_list ap)
{
	char **ptr;

	ptr = s;
	while (!ft_isalpha(**s))
	{
		if ('.' == **s)
		{
			f.precision = 1;
			f.width = ft_atoi(*ptr);
			f.precision = ft_atoi(*(++s));
		}
		++s;
	}
}

int		ft_printf(const char *s, ...)
{
	va_list		ap;
	t_format	f;
	char		*ret;
	static int	cnt;

	cnt = 0;
	ft_memset(&f, 0, sizeof(t_format));
	va_start(ap, s);
	while (*s != '\0')
	{
		/*
		check_string(s, f);
		check_flag(s, f);
		check_opt(s, f);
		check_type(s, f);
		ret = make_string(s, f, ap); // ft_strdup + va_list(and the va_funcs)
		ft_putstr(ret);
		s++; // check another format specifier
		*/
		if (*s != '%')
		{
			cnt += write(1, s++, 1);
			continue;
		}
		s++;
		check_flag(&s, f);
		check_opt(&s, f, ap);
		cnt += print_var(&s, ap);
		++s;
	}
	return (cnt);
}
