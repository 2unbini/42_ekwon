/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getfunc.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekwon <ekwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 15:26:10 by ekwon             #+#    #+#             */
/*   Updated: 2021/06/14 13:46:16 by ekwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GETFUNC_H
# define GETFUNC_H

# include "ft_printf.h"

int		get_int(t_format *f, va_list ap);
int		get_usint(t_format *f, va_list ap);
int		get_shex(t_format *f, va_list ap);
int		get_lhex(t_format *f, va_list ap);
int		get_char(t_format *f, va_list ap);
int		get_string(t_format *f, va_list ap);
int		get_pointer(t_format *f, va_list ap);

#endif
