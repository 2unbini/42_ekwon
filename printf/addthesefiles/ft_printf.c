/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekwon <ekwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 21:39:10 by ekwon             #+#    #+#             */
/*   Updated: 2021/06/06 23:57:09 by ekwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// t_format : true = 1, false = 0
// functions : normal flow = 1, return = 0, continue = -1
// type[9] = {c, s, d, i, u, p, x, X, %}
typedef struct	s_format
{
	int is_format;
	int zero_flag;
	int minus_flag;
	int aster_flag;
	int pre_flag;
	int width_opt;
	int pre_opt;
	int type[9];
}				t_format
static int		cnt;

#include <stdlib.h>
#include <unistd.h>

// check strings before first % discovered
// if % discovered, returns 1
// if not, returns 0
int		check_string(const char **ptr, t_format f)
{
	while (*ptr != '%' && *ptr != '\0')
	{
		write(1, ptr, 1);
		(*ptr)++;
		cnt++;
	}
	if (*ptr == '%')
	{
		f.is_format = 1;
		(*ptr)++;
		return (1);
	}
	return (0);
}

int		ft_isdigit(int c)
{
	if (c >= '1' && c <= '9')
		return (1);
	else if (c == '0')
		return (-1);
	else
		return (0);
}

void	ft_putstr(char *str, char c)
{
	while (*str != c)
	{
		write(1, str, 1);
		str++;
	}
}

int		check_flag(const char **ptr, t_format f)
{
	char **pptr;

	pptr = *ptr;
	while (ft_isdigit(*ptr) != 1 && f.is_format == 1)
	{
		if (*ptr == '-')
			f.minus_flag = 1;
		else if (*ptr == '0' && f.minus_flag == 0 && f.pre_flag == 0)
			f.zero_flag = 1;
		else if (*ptr == '*')
			f.aster_flag = 1;
		else if (*ptr == '.')
			f.pre_flag = 1;
		else if (*ptr == '%')
		{
			f.is_format = 0;
			ft_putstr(pptr, '%');
			(*ptr)++;
			return (-1);
		}
		else
			;
		(*ptr)++;
	}
	return (1);
}

int		check_opt(const char **ptr, t_format f)
{
	char 
}

int		ft_printf(const char *s, ...)
{
	va_list		ap;
	t_format	f;
	char		*ret;

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
		if (check_string(&s, f) == 0)
			return (cnt);
		if (check_flag(&s, f) == -1)
			continue ;
		if (check_opt(&s, f)
	}
	
}
