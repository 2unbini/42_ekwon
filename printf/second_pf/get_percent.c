/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_percent.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekwon <ekwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 13:00:13 by ekwon             #+#    #+#             */
/*   Updated: 2021/06/15 20:32:36 by ekwon            ###   ########.fr       */
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
	char c;

	c = ' ';
	if (f->pzero_space == 1 && f->minus_align == 0)
		c = '0';
	*ret = my_alloc(len, sizeof(char), c);
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

int			get_percent(t_format *f)
{
	char	*ret;
	char	arg;
	int		len;
	int		print_num;
	int		status;

	print_num = 0;
	arg = '%';
	len = max_len(f);
	if ((status = alloc_ret(&ret, len, f)) == -1)
		return (-1);
	if (status != 0)
		print_num = set_string(&ret, arg, f, len);
	return (print_num);
}
