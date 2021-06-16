/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_string.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekwon <ekwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 13:00:13 by ekwon             #+#    #+#             */
/*   Updated: 2021/06/16 18:11:22 by ekwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static int	max_len(t_format *f, char *arg)
{
	int result;

	result = 0;
	if (arg == 0)
		f->len = 6;
	else
		while (arg[f->len])
			f->len += 1;
	if (f->width >= f->precision && f->width >= f->len)
		result = f->width;
	else if (f->precision >= f->width && f->precision >= f->len)
		result = (f->width >= f->len) ? f->width : f->len;
	else
	{
		result = (f->precision != -1 && f->precision < f->len) ?
				f->precision : f->len;
		if (f->width > result)
			result = f->width;
	}
	return (result);
}

static int	alloc_ret(char **ret, int len, t_format *f)
{
	int i;

	i = 0;
	if (f->width == 0 && len == 0)
	{
		*ret = 0;
		return (0);
	}
	if (!(*ret = (char *)malloc(sizeof(char) * (len + 1))))
		return (-1);
	while (i < len)
		(*ret)[i++] = ' ';
	(*ret)[i] = 0;
	return (len);
}

static int	set_string(char **ret, char *arg, t_format *f, int len)
{
	int		i;
	int		j;
	int		word_len;

	word_len = (f->precision != -1 && (f->precision < f->len)) ?
				f->precision : f->len;
	i = (f->minus_align == 1 || (word_len > f->width)) ?
		0 : f->width - word_len;
	j = 0;
	while (j < word_len)
		(*ret)[i++] = arg[j++];
	write(1, *ret, len);
	return (len);
}

int			get_string(t_format *f, va_list ap)
{
	char	*ret;
	char	*arg;
	int		len;
	int		print_num;
	int		status;

	print_num = 0;
	arg = va_arg(ap, char *);
	if (arg == NULL)
		arg = "(null)";
	len = max_len(f, arg);
	if ((status = alloc_ret(&ret, len, f)) == -1)
		return (-1);
	if (status != 0)
		print_num = set_string(&ret, arg, f, len);
	free(ret);
	return (print_num);
}
