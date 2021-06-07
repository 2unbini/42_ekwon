/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekwon <ekwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 21:39:10 by ekwon             #+#    #+#             */
/*   Updated: 2021/06/07 16:23:30 by ekwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"


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

int		ft_printf(const char *s, ...)
{
	va_list		ap;
	t_format	f;
	char		*ret;
	static int	cnt;

	cnt = 0;
	ft_memeset(&f, 0, sizeof(t_format));
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
		if (check_flag(&s, f) == -1)
			continue ;
		if (check_opt(&s, f) == 0)
			return (-1);
		if (check_type(&s, f)
	}
	
}
