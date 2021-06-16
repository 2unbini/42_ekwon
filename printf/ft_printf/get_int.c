/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_int.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekwon <ekwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 13:00:13 by ekwon             #+#    #+#             */
/*   Updated: 2021/06/16 15:59:06 by ekwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"





#include <stdio.h>
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
//	printf("max_len: %d\n", result);
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
	//*ret = my_alloc(len, sizeof(char), c);
	if (!(*ret = (char *)malloc(sizeof(char) * (len + 1))))
		return (-1);
	while (i < len)
		(*ret)[i++] = c;
	(*ret)[i] = 0;
	return (1);
}


/*
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
	(*ret)[idx] = 0;
}
*/

static int	set_string(char **ret, int arg, t_format *f, int len)
{
	int		i;
	int		j;
	int		num;
	char	*tmp;

	i = 0;
	j = 0;
	num = 0;
	if (arg == 0 && f->precision == 0)
	{
		while (i < len)
			(*ret)[i++] = ' ';
		return (1);
	}
	tmp = ft_itoa(arg, f->digit);
//	printf("arg: %d\n", arg);
//	printf("tmp: %s\n", tmp);
	if (f->negative)
	{
		(*ret)[i++] = '-';
//		printf("ret[%d]: %c\n", i-1, (*ret)[i-1]);
		f->digit -= 1;
//		printf("f->negative = 1\n");
	}
	if (f->precision != -1 && f->precision > f->digit)
		while (num++ < f->precision - f->digit)
		{
//			printf("precision = %d\n", f->precision);
//			printf("digit = %d\n", f->digit);
			(*ret)[i++] = '0';
//			printf("ret[%d]: %c\n", i-1, (*ret)[i-1]);
		}
	num = 0;
	while (num++ < f->digit)
	{
		(*ret)[i] = tmp[j];
//		printf("ret[%d]: %c\n", i, (*ret)[i]);
		++i;
		++j;
	}
	if (f->minus_align || len <= i)
	{
		(*ret)[f->len] = 0;
//		printf("ret in m_a: %s\n", *ret);
	}
	else
	{
		*ret = ft_strjoin(ret, f, i);
//		printf("ret in strjoin: %s\n", *ret);
	}
	return (1);
}

/*
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
*/

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
	return (ft_putstr2(&ret, f->len));
	//return (ft_putstr(&ret));
}
