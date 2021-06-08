/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekwon <ekwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 14:23:11 by ekwon             #+#    #+#             */
/*   Updated: 2021/06/08 17:24:59 by ekwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <stdarg.h>

int		ft_isdigit(int c);
int		ft_isalpha(int c);
int		ft_putstr(char *str);
void	*ft_memset(void *b, int c, size_t len);
void	*my_alloc(size_t count, size_t size, char c);
int		ft_atoi(const char *str, va_list ap);

#endif
