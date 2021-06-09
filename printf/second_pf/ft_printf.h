/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekwon <ekwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 14:02:11 by ekwon             #+#    #+#             */
/*   Updated: 2021/06/09 21:52:35 by ekwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

typedef struct	s_format
{
	int	zero_space;
	int	minus_align;
	int	asterisk;
	int	precision;
	int	width;
	int	negative;
	int digit;
}				t_format;

int			ft_printf(const char *s, ...);
void		check_flag(const char **s, t_format *f);
void		check_opt(const char **s, t_format *f, va_list ap);
int			print_var(const char **s, t_format *f, va_list ap);

#endif
