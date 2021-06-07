/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkfunc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekwon <ekwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 14:32:21 by ekwon             #+#    #+#             */
/*   Updated: 2021/06/07 16:23:25 by ekwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int		check_flag(const char **ptr, t_format f)
{
	char **pptr;

	pptr = *ptr;
	while (ft_isdigit(*ptr) != 1 && f.is_format == 1)
	{
		if (*ptr == '-')
			f.minus_flag = 1;
		else if (*ptr == '0' && f.minus_flag == 0 && f.pre_flag == 0)
			f.zero_flag = 1;
		else if (*ptr == '*')
			f.aster_flag = 1;
		else if (*ptr == '.')
			f.pre_flag = 1;
		else if (*ptr == '%')
		{
			f.is_format = 0;
			ft_putstr(pptr, '%');
			(*ptr)++;
			return (-1);
		}
		else
			;
		(*ptr)++;
	}
	return (1);
}
