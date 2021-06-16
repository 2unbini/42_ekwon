/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekwon <ekwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 14:23:11 by ekwon             #+#    #+#             */
/*   Updated: 2021/06/16 18:05:28 by ekwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include "ft_printf.h"
# include <stdlib.h>
# include <stdarg.h>

int		ft_isdigit(int c);
int		ft_isalpha(int c);
int		ft_putstring(char **str, int len);
int		ft_strlen(char *str);
char	*ft_strdup(char *s1);
char	*ft_strjoin(char **s, t_format *f, int print_len);
char	*ft_itoa(int n, int len);
char	*ft_utoa(unsigned int n, int len);
char	*ft_utoh(unsigned int n, char *base, int len);
char	*ft_utop(unsigned long long n, char *base, t_format *f);

#endif
