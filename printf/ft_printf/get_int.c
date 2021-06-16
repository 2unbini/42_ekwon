/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_int.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekwon <ekwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 13:00:13 by ekwon             #+#    #+#             */
/*   Updated: 2021/06/16 18:37:05 by ekwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static int	max_len(t_format *f, int arg)
{
	int result;

	result = 0;
	f->digit = 1;
	if (arg < 0)
	{
		if (arg == -2147483648)
			arg = -2147483647;
		arg *= -1;
		f->digit += 1;
	}
	while (arg /= 10)
		f->digit += 1;
	if (f->width > f->precision && f->width > f->digit)
		result = f->width;
	else if (f->precision >= f->width && f->precision >= f->digit)
	{
		result = f->precision;
		if (f->negative)
			++result;
	}
	else
		result = f->digit;
	return (result);
}

static int	alloc_ret(char **ret, int len, t_format *f)
{
	int		i;
	char	c;

	i = 0;
	if (f->zero == 1 && f->precision == 0 && !f->width)
	{
		*ret = 0;
		return (2);
	}
	c = ' ';
	if (f->zero_space)
		c = '0';
	if (!(*ret = (char *)malloc(sizeof(char) * (len + 1))))
		return (-1);
	while (i < len)
		(*ret)[i++] = c;
	(*ret)[i] = 0;
	return (1);
}

static int	set_string_cont(char **ret, char *tmp, t_format *f, int i)
{
	int	j;
	int num;

	j = 0;
	num = 0;
	if (f->precision != -1 && f->precision > f->digit)
		while (num++ < f->precision - f->digit)
			(*ret)[i++] = '0';
	num = 0;
	while (num++ < f->digit)
		(*ret)[i++] = tmp[j++];
	if (f->minus_align || f->len <= i)
		(*ret)[f->len] = 0;
	else
	{
		if (!(*ret = ft_strjoin(ret, f, i)))
			return (-1);
	}
	return (1);
}

static int	set_string(char **ret, int arg, t_format *f, int len)
{
	int		i;
	char	*tmp;

	i = 0;
	if (arg == 0 && f->precision == 0)
	{
		while (i < len)
			(*ret)[i++] = ' ';
		return (1);
	}
	tmp = ft_itoa(arg, f->digit);
	if (f->negative)
	{
		(*ret)[i++] = '-';
		f->digit -= 1;
	}
	if (set_string_cont(ret, tmp, f, i) == -1)
		return (-1);
	return (1);
}

int			get_int(t_format *f, va_list ap)
{
	char	*ret;
	int		arg;
	int		status;

	arg = va_arg(ap, int);
	if (arg == 0)
		f->zero = 1;
	if (arg < 0)
		f->negative = 1;
	f->len = max_len(f, arg);
	if (!(status = alloc_ret(&ret, f->len, f)))
		return (-1);
	if (status != 2)
		if (set_string(&ret, arg, f, f->len) == -1)
		{
			free(ret);
			ret = 0;
			return (-1);
		}
	return (ft_putstring(&ret, f->len));
}
