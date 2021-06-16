/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pointer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekwon <ekwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 13:00:13 by ekwon             #+#    #+#             */
/*   Updated: 2021/06/16 18:05:57 by ekwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static int	max_len(t_format *f, unsigned long long arg)
{
	int result;

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

static int	alloc_ret(char **ret, int len)
{
	int i;

	i = 0;
	*ret = (char *)malloc(sizeof(char) * (len + 1));
	if (!(*ret))
		return (-1);
	while (i < len)
		(*ret)[i++] = ' ';
	(*ret)[i] = 0;
	return (1);
}

static int	set_string(char **ret, unsigned long long arg, t_format *f)
{
	int		i;
	int		idx;
	char	*tmp;

	i = 0;
	idx = 0;
	tmp = ft_utop(arg, "0123456789abcdef", f);
	if (!(f->minus_align) && f->width >= f->digit)
		idx = f->width - f->digit;
	while (i < f->digit)
		(*ret)[idx++] = tmp[i++];
	return (1);
}

int			get_pointer(t_format *f, va_list ap)
{
	char				*ret;
	unsigned long long	arg;
	int					status;

	arg = va_arg(ap, unsigned long long);
	f->digit = 3;
	if (arg == 0)
	{
		f->zero = 1;
		if (f->precision == 0)
			f->digit = 2;
	}
	f->len = max_len(f, arg);
	if (!(status = alloc_ret(&ret, f->len)))
		return (-1);
	if (status != 2)
		if (set_string(&ret, arg, f) == -1)
		{
			free(ret);
			ret = 0;
			return (-1);
		}
	return (ft_putstring(&ret, f->len));
}
