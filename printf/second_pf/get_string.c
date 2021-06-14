/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_string.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekwon <ekwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 13:00:13 by ekwon             #+#    #+#             */
/*   Updated: 2021/06/14 21:12:47 by ekwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static int	max_len(t_format *f, char *arg)
{
	int result;

	result = 0;
	while (arg[f->len])
		f->len += 1;
	if (f->width >= f->precision && f->width >= f->len)
		result = f->width;
	else if (f->precision >= f->width && f->precision >= f->len)
		result = f->precision;
	else
		result = f->len;
	return (result);
}

static int	alloc_ret(char **ret, int len, t_format *f)
{
	char	c;

	if (f->precision == 0 && f->width == 0)
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

static void	set_string(char **ret, char *arg, t_format *f, int len)
{

}

int			get_string(t_format *f, va_list ap)
{
	char	*ret;
	char	*arg;
	int		len;
	int		status;

	arg = va_arg(ap, char *);
	if (arg == 0)
		f->zero = 1;
	len = max_len(f, arg);
	if (!(status = alloc_ret(&ret, len, f)))
		return (-1);
	if (status != 2)
		set_string(&ret, arg, f, len);
	return (ft_putstr(&ret));
}
