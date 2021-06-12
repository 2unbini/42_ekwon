/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_shex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekwon <ekwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 13:00:13 by ekwon             #+#    #+#             */
/*   Updated: 2021/06/12 23:04:14 by ekwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static int	max_len(t_format *f, unsigned int arg)
{
	int result;

	f->digit = 1;
	result = 0;
	while (arg /= 16)
		f->digit += 1;
	if (f->width >= f->precision && f->width >= f->digit)
		result = f->width;
	else if (f->precision >= f->width && f->precision >= f->digit)
		result = f->precision;
	else
		result = f->digit;
	return (result);
}

static int	alloc_ret(char **ret, int len, t_format *f)
{
	char	c;

	if (f->zero == 1 && !f->precision && !f->width)
	{
		if (!(*ret = ft_strdup("")))
			return (-1);
		return (2);
	}
	if (!(f->zero_space))
		c = ' ';
	if (f->minus_align || f->precision)
		c = ' ';
	if (f->zero_space)
		c = '0';
	*ret = my_alloc(len, sizeof(char), c);
	if (!(*ret))
		return (-1);
	return (1);
}

static void	set_string_cont(char **ret, char **tmp, t_format *f, int *i)
{
	int	j;
	int	num;
	int	idx;

	j = 0;
	num = 0;
	idx = 0;
	if (f->zero_space && f->width > (*i + 1))
	{
		j = f->width - (*i + 1);
		while (num++ < j)
			(*tmp)[(*i)++] = '0';
	}
	if (f->negative)
		(*tmp)[(*i)++] = '-';
	if (!(f->minus_align) && f->width > *i)
		idx = f->width - *i;
	while (--(*i) >= 0)
		(*ret)[idx++] = (*tmp)[*i];

}

static void	set_string(char **ret, int arg, t_format *f, int len)
{
	int		i;
	int		num;
	char	*tmp;

	i = f->digit;
	num = 0;
	if (arg == 0 && f->precision == 0)
	{
		while (i < len)
			(*ret)[i++] = ' ';
		return ;
	}
	tmp = ft_utoh(arg, "0123456789abcdef");
	if (f->precision != -1 && f->precision > f->digit)
		while (num++ < (f->precision - f->digit))
			tmp[i++] = '0';
	set_string_cont(ret, &tmp, f, &i);
}

int		get_shex(t_format *f, va_list ap)
{
	char			*ret;
	unsigned int	arg;
	int				len;
	int				status;

	arg = va_arg(ap, unsigned int);
	if (arg == 0)
		f->zero = 1;
	len = max_len(f, arg);
	if (!(status = alloc_ret(&ret, len, f)))
		return (-1);
	if (status != 2)
		set_string(&ret, arg, f, len);
	return (ft_putstr(&ret));
}
