/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekwon <ekwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 13:19:26 by ekwon             #+#    #+#             */
/*   Updated: 2021/07/07 13:27:31 by ekwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int main(int argc, char *argv[], char **envp)
{
	while (*envp)
	{
		printf("%s\n\n", *envp++);
	}
	return (0);
}
