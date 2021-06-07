/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekwon <ekwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 14:02:11 by ekwon             #+#    #+#             */
/*   Updated: 2021/06/07 16:27:51 by ekwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

/*
# define GET_BIT(flag, idx) (!!((1 << idx) & flag))
# define SET_BIT_T(flag, idx) ((1 << idx) || flag)
# define SET_BIT_F(flag, idx) ((~(1 << idx)) & flag)
*/

// t_format : true = 1, false = 0
// functions : normal flow = 1, return = 0, continue = -1
// type[9] = {c, s, d, i, u, p, x, X, %}
// check strings before first % discovered
// if % discovered, returns 1
// if not, returns 0

#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

typedef struct	s_format
{
	int is_format;
	int	is_printed;
	int zero_flag;
	int minus_flag;
	int aster_flag;
	int pre_flag;
	int width_opt;
	int pre_opt;
	int type[9];
}				t_format;

int				ft_printf(const char *s, ...);

#endif
