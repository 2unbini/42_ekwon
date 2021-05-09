/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekwon <ekwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 15:17:44 by ekwon             #+#    #+#             */
/*   Updated: 2021/05/09 16:03:56 by ekwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_sign(int n)
{
	if (n >= 0)
		return (1);
	else if (n == -2147483648)
		return (0);
	else
		return (-1);
}

static char	*min_output(void)
{
	int		i;
	int		num;
	char	*result;

	i = 1;
	num = 463847412;
	result = (char *)malloc(sizeof(char) * 12);
	result[0] = '-';
	result[10] = '8';
	result[11] = 0;
	while (num)
	{
		result[i] = num % 10;
		num /= 10;
		i++;
	}
	return (result);
}

static char	*make_string(char tmp[], int sign, int i)
{
	int		idx;
	char	*result;

	idx = -1;
	if(!(result = (char *)malloc(sizeof(char) * i)))
		return (NULL);
	if (sign == -1)
		result[++idx] = '-';
	while (++idx < i)
		result[idx] = tmp[i - idx - 1];
	result[idx] = 0;
	return (result);
}

char		*ft_itoa(int n)
{
	int		i;
	int		sign;
	char	temp[11];

	if(!(sign = get_sign(n)))
		return (min_output());
	i = 0;
	n *= sign;
	while (n)
	{
		temp[i] = n % 10;
		n /= 10;
		i++;
	}
	if (sign > 0)
		return (make_string(temp, sign, i));
	else
		return (make_string(temp, sign, i + 1));
}
