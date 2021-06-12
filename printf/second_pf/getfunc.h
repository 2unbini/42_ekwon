/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getfunc.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekwon <ekwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 15:26:10 by ekwon             #+#    #+#             */
/*   Updated: 2021/06/12 18:03:42 by ekwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GETFUNC_H
# define GETFUNC_H

# include "ft_printf.h"

int		max_len(t_format *f, int arg);
int		is_zero_space_valid(t_format *f);
int		alloc_ret(char **ret, int len, t_format *f);
void	set_istring_cont(char **ret, char **tmp, t_format *f, int *i);
void	set_istring(char **ret, int arg, t_format *f, int len);
int		get_int(t_format *f, va_list ap);

#endif
