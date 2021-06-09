/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_int.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekwon <ekwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 13:00:13 by ekwon             #+#    #+#             */
/*   Updated: 2021/06/10 00:48:30 by ekwon            ###   ########.fr       */
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

int		is_zero_space_valid(t_format *f)
{
	if (f->zero_space == 0)
		return (0);
	else
	{
		if (f->minus_align || f->precision)
			return (0);
	}
	return (1);
}

int		alloc_ret(char **ret, int len, t_format *f)
{
	if (is_zero_space_valid(f))
		*ret = my_alloc(len, sizeof(char), '0');
	*ret = my_alloc(len, sizeof(char), ' ');
	if (!(*ret))
		return (0);
	return (1);
}

void	set_istring(char **ret, int arg, t_format *f)
{
	int		pre_num;
	int		i;
	int		idx;
	char	tmp[20];

	i = 0;
	idx = 0;
	pre_num = 0;
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
	set_istring(&ret, arg, f);
	return (ft_putstr(&ret));
}
