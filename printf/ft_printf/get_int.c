/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_int.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekwon <ekwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 13:00:13 by ekwon             #+#    #+#             */
/*   Updated: 2021/06/15 23:35:19 by ekwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static int	max_len(t_format *f, int arg)
{
	int result;

	f->digit = 1;
	result = 0;
	if (arg < 0)
	{
		f->negative = 1;
		//f->digit += 1;
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

static int	alloc_ret(char **ret, int len, t_format *f)
{
	int		i;
	char	c;

	i = 0;
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
	//*ret = my_alloc(len, sizeof(char), c);
	if (!(*ret = (char *)malloc(sizeof(char) * len)))
		return (-1);
	while (i < len)
		(*ret)[i++] = c;
	return (1);
}

static void	set_istring_cont(char **ret, char **tmp, t_format *f, int *i)
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

static int	set_istring(char **ret, int arg, t_format *f, int len)
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
		return (1);
	}
	tmp = ft_strdup(ft_itoa(arg));
	if (tmp == 0)
		return (-1);
	if (f->precision != -1 && f->precision > f->digit)
		while (num++ < (f->precision - f->digit))
			tmp[i++] = '0';
	set_istring_cont(ret, &tmp, f, &i);
	free(tmp);
	tmp = 0;
	return (1);
}

int			get_int(t_format *f, va_list ap)
{
	char	*ret;
	int		arg;
	int		len;
	int		status;

	arg = va_arg(ap, int);
	if (arg == 0)
		f->zero = 1;
	len = max_len(f, arg);
	if (!(status = alloc_ret(&ret, len, f)))
		return (-1);
	if (status != 2)
		if (set_istring(&ret, arg, f, len) == -1)
		{
			free(ret);
			ret = 0;
			return (-1);
		}
		//putstr2 => fucking tester.. gcc -L. -lftprintf -fsanitize=address main.c do it!!
	return (ft_putstr2(&ret, len));
}
