/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekwon <ekwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 14:02:11 by ekwon             #+#    #+#             */
/*   Updated: 2021/06/15 19:13:45 by ekwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

typedef struct	s_format
{
	int	zero_space;
	int	pzero_space;
	int	minus_align;
	int	dot;
	int	precision;
	int	width;
	int	negative;
	int digit;
	int	zero;
	int	len;
}				t_format;

int				ft_printf(const char *s, ...);
void			check_flag(const char **s, t_format *f);
void			check_width(const char **s, t_format *f, va_list ap);
void			chekc_precision_dot(const char **s, t_format *f);
void			check_precision(const char **s, t_format *f, va_list ap,
								int tmp);
void			init_flags(t_format *f);
int				print_var(const char **s, t_format *f, va_list ap);

#endif
