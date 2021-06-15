/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_char.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekwon <ekwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 13:00:13 by ekwon             #+#    #+#             */
/*   Updated: 2021/06/15 20:31:24 by ekwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static int	max_len(t_format *f)
{
	int result;

	result = 0;
	f->len = 1;
	if (f->width >= f->len)
		result = f->width;
	else
		result = f->len;
	return (result);
}

static int	alloc_ret(char **ret, int len, t_format *f)
{
	if (f->width == 0 && len == 0)
	{
		if (!(*ret = ft_strdup("")))
			return (-1);
		return (0);
	}
	*ret = my_alloc(len, sizeof(char), ' ');
	if (!(*ret))
		return (-1);
	return (len);
}

static int	set_string(char **ret, char arg, t_format *f, int len)
{
	int		i;

	if (f->minus_align == 1 || (f->len > f->width))
		i = 0;
	else
		i = f->width - f->len;
	(*ret)[i] = arg;
	write(1, *ret, len);
	return (len);
}

int			get_char(t_format *f, va_list ap)
{
	char	*ret;
	char	arg;
	int		len;
	int		print_num;
	int		status;

	print_num = 0;
	arg = va_arg(ap, int);
	len = max_len(f);
	if ((status = alloc_ret(&ret, len, f)) == -1)
		return (-1);
	if (status != 0)
		print_num = set_string(&ret, arg, f, len);
	return (print_num);
}
