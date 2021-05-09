/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekwon <ekwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 16:26:45 by ekwon             #+#    #+#             */
/*   Updated: 2021/05/09 16:34:26 by ekwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int		i;
	char	*result;

	i = 0;
	result = itoa(n);
	if (!result)
		return ;
	while (result[i])
	{
		write(fd, &result[i], 1);
		i++;
	}
	free(result);
}
