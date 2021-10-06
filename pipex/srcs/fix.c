/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fix.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekwon <ekwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 13:34:35 by ekwon             #+#    #+#             */
/*   Updated: 2021/10/06 14:03:07 by ekwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	pass_suffix(char const *s, int *idx)
{
	while (s[*idx] == '\'' || s[*idx] == '\"')
		*idx += 1;
}

void	pass_prefix(char const *s, int *idx)
{
	while (s[*idx] == '\'' || s[*idx] == '\"')
		*idx += 1;
}
