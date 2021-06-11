/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_int.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekwon <ekwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 13:00:13 by ekwon             #+#    #+#             */
/*   Updated: 2021/06/11 23:35:29 by ekwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int		max_len(t_format *f, int arg)
{
	int result;

	f->digit = 1;
	result = 0;
	if (arg < 0)
	{
		f->negative = 1;
		if (arg == -2147483648)
			arg = -2147483647;
		arg *= -1;
	}
	while (arg /= 10)
		f->digit += 1;
	if (f->width >= f->precision && f->width >= f->digit)
		result = f->width;
	else if (f->precision >= f->width && f->precision >= f->digit)
		result = f->precision;
	else
		result = f->digit;
	return (result);
}

int		alloc_ret(char **ret, int len, t_format *f)
{
	char c;

	if (!f->zero_space)
		c = ' ';
	else if (f->minus_align || f->precision || f->asterisk >= 2)
		c = ' ';
	else
		c = '0';
	*ret = my_alloc(len, sizeof(char), c);
	if (!(*ret))
		return (0);
	return (1);
}

#include <stdio.h>
int		set_istring(char **ret, int arg, t_format *f, int len)
{
	int		i;
	int		idx;
	int		num;
	char	*tmp;

	i = f->digit;
	idx = 0;
	num = 0;
	if (arg == 0)
	{
		while (i < len)
			(*ret)[i++] = ' ';
		return (1);
	}
	tmp = ft_ritoa(arg);
	//printf("tmp after itoa: %s\n", tmp);
	if (f->precision && f->precision > f->digit)
		while (num++ < (f->precision - f->digit))
			ft_strcpy(&tmp, "0", &i);
	//printf("tmp after precision: %s\n", tmp);
	num = 0;
	if (f->negative)
	{
		if (f->zero_space && !(f->precision) && f->width > i + 1)
			while (num++ < f->width - (i + 1))
				ft_strcpy(&tmp, "0", &i);
		tmp[i] = '-';
	}
	//printf("tmp after negative space: %s\n", tmp);
	if (!(f->minus_align) && f->width > i + 1)
		idx = f->width - (i + 1);
	while (i >= 0)
		(*ret)[idx++] = tmp[i--];
	//printf("ret: %s\n", *ret);
	tmp = 0;
	return (1);
}


/*
void	set_istring(char **ret, int arg, t_format *f)
{
	char	tmp[20];
	int		i;
	int		num;
	int		idx;

	i = 0;
	num = 0;
	idx = 0;
	if (f->negative)
		arg *= -1;
	while (arg)
	{
		tmp[i++] = (arg % 10) + '0';
		arg /= 10;
	}
	if (f->precision && (f->precision > f->digit))
		while (num++ < (f->precision - f->digit))
			tmp[i++] = '0';
	num = 0;
	if (f->negative)
	{
		if (f->asterisk >= 2 && f->minus_align && f->width > i + 1)
			while (num++ < f->width - (i + 1))
				tmp[i++] = '0';
		tmp[i] = '-';
	}
	if (!(f->minus_align) && f->width >= i + 1)
		idx = f->width - (i + 1);
	while (i >= 0)
		(*ret)[idx++] = tmp[i--];
}
*/

/*
void	set_istring(char **ret, int arg, t_format *f)
{
	int		pre_num;
	int		width_num;
	int		i;
	int		idx;
	char	tmp[20];

	i = 0;
	idx = 0;
	pre_num = 0;
	width_num = 0;
	if (f->negative)
		arg *= -1;
	while (arg)
	{
		tmp[i++] = (arg % 10) + '0';
		arg /= 10;
	}
	if (f->precision && f->precision >= f->digit)
		while (pre_num++ < (f->precision - f->digit))
			tmp[i++] = '0';
	if (f->negative)
		tmp[i] = '-';
	if (!(f->minus_align) && f->width >= i + 1)
		idx = f->width - (i + 1);
	while (i >= 0)
	{
		(*ret)[idx] = tmp[i];
		++idx;
		--i;
	}
}
*/

/*
void	set_istring(char **ret, int arg, t_format *f, int len)
{
	int		pre_num;
	int		idx;

	idx = 0;
	pre_num = 0;
	if (f->negative)
	{
		arg *= -1;
		f->digit += 1;
	}
	if (f->minus_align && f->width && f->width >= len)
	{
		if (len != f->digit)
			len = f->digit;
		idx = f->width - len;
	}
	while (arg)
	{
		(*ret)[idx] = (arg % 10) + '0';
		idx++;
		arg /= 10;
	}
	if (f->negative)
		f->digit -= 1;
	if (f->precision && f->precision >= f->digit)
		while (pre_num++ < (f->precision - f->digit))
			(*ret)[idx++] = '0';
	if (f->negative)
		(*ret)[idx] = '-';
}
*/

int		get_int(t_format *f, va_list ap)
{
	char	*ret;
	int		arg;
	int		len;

	arg = va_arg(ap, int);
	len = max_len(f, arg);
	if (!(alloc_ret(&ret, len, f)))
		return (0);
	if (!set_istring(&ret, arg, f, len))
		return (0);
	return (ft_putstr(&ret));
}
