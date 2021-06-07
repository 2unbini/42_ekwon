/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekwon <ekwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 21:39:10 by ekwon             #+#    #+#             */
/*   Updated: 2021/06/07 20:56:47 by ekwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

/*
int		check_opt(const char **ptr, t_format f)
{
   while (ft_isalpha(*ptr) != 0)
   {
	   if (f.pre_flag == 1)
	   {
		   f.pre_opt *= 10;
		   f.pre_opt += *ptr - '0';
	   }
	   else if (f.pre_flag == 1 && *ptr == '.')
		   return (0);
	   else if (f.pre_flag == 0 && *ptr == '.')
		   f.pre_flag = 1;
	   else
	   {
		   f.width_opt *= 10;
		   f.width_opt += *ptr - '0';
	   }
	   ++ptr;
   }
   return (1);
}

int		check_type(const char **ptr, t_format f)
{
	unsigned long long		ret;
	char					*str;

	ret = 0;
	if (*ptr == 'd' || *ptr == 'i' || *ptr == 'u' ||
		|| *ptr == 'x' || *ptr == 'X')
}
*/

int		put_num(unsigned int num, char *base, int base_num)
{
	int	len;

	len = 0;
	if (num / base_num)
		len += put_num(num / base_num, base, base_num);
	len += write(1, base + (num % base_num), 1);
	return (len);
}

int		print_int(va_list ap)
{
	int	num;
	int	print_len;

	print_len = 0;
	num = va_arg(ap, int);
	if (num < 0)
	{
		print_len += write(1, "-", 1);
		num *= -1;
	}
	return (print_len + put_num(num, "0123456789", 10));
}

#include <stdio.h>
int		print_var(const char **s, va_list ap)
{
	++(*s);
	if ('c' == **s)
		return (printf("[char]"));
	if ('s' == **s)
		return (printf("[string]"));
	if ('d' == **s || 'i' == **s)
		return (print_int(ap));
	if ('u' == **s)
		return (printf("[unsigned int]"));
	if ('p' == **s)
		return (printf("[pointer]"));
	if ('x' == **s)
		return (printf("[small hex]"));
	if ('X' == **s)
		return (printf("[large hex]"));
	if ('%' == **s)
		return (printf("[percentage]"));
	return (-1);
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
		/*
		if (check_flag(&s, f) == -1)
			continue ;
		if (check_opt(&s, f) == 0)
			return (-1);
		if (check_type(&s, f)
		*/
		if (*s != '%')
		{
			cnt += write(1, s++, 1);
			continue;
		}
		cnt += print_var(&s, ap);
		++s;
	}
	return (cnt);
}
