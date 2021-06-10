/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekwon <ekwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 14:23:11 by ekwon             #+#    #+#             */
/*   Updated: 2021/06/10 21:50:36 by ekwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <string.h>
# include <stdarg.h>

int		ft_isdigit(int c);
int		ft_isalpha(int c);
int		ft_putstr(char **str);
int		ft_strlen(char *str);
void	*ft_memset(void *b, int c, size_t len);
void	*my_alloc(size_t count, size_t size, char c);
int		ft_atoi(const char *str, va_list ap);
void	*ft_calloc(size_t count, size_t size);

#endif
