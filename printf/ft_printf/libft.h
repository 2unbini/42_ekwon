/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekwon <ekwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 14:23:11 by ekwon             #+#    #+#             */
/*   Updated: 2021/06/15 23:26:53 by ekwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include "ft_printf.h"
# include <stdlib.h>
# include <stdarg.h>

int		ft_isdigit(int c);
int		ft_isalpha(int c);
int		ft_putstr(char **str);
int		ft_putstr2(char **str, int len);
int		ft_putstr_r(char **str, int len);
int		ft_strlen(char *str);
void	ft_strcpy(char **dest, char *src, int *i);
char	*ft_strdup(char *s1);
void	*my_alloc(size_t count, size_t size, char c);
char	*ft_itoa(int n);
char	*ft_utoa(unsigned int n);
char	*ft_utoh(unsigned int n, char *base);
char	*ft_utop(unsigned long long n, char *base, t_format *f);
void	*ft_calloc(size_t count, size_t size);

#endif
