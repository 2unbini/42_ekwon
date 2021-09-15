/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekwon <ekwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 12:37:51 by ekwon             #+#    #+#             */
/*   Updated: 2021/09/15 18:50:08 by ekwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	print_error(char *message)
{
	write(1, message, ft_strlen(message));
	write(1, "\n", 1);
}

void	init_data(t_data *data, char **argv, char **envp)
{
	data->envp = envp;
	data->c.file_in = argv[1];
	data->p.file_out = argv[4];
	if (parse_path(data) == -1)
	{
		print_error("Error: Cannot Find Any Path");
		exit(-1);
	}
	data->c.cmd_one = ft_split(argv[2], ' ');
	data->p.cmd_two = ft_split(argv[3], ' ');
	if (data->c.cmd_one == NULL || data->p.cmd_two == NULL)
	{
		print_error("Error: Malloc Error");
		exit(-1);
	}
	data->c.exe_path = check_access(*data, data->c.cmd_one[0]);
	data->p.exe_path = check_access(*data, data->p.cmd_two[0]);
	if (data->c.exe_path == NULL || data->p.exe_path == NULL)
	{
		print_error("Error: Cannot Access");
		exit(-1);
	}
}

int	find_line(char *target, char **envp)
{
	int	index;
	int	compare;
	size_t	n;

	index = 0;
	n = ft_strlen(target);
	while (envp[index] != 0)
	{
		compare = ft_strncmp(target, envp[index], n);
		if (compare == 0)
			return (index);
		index++;
	}
	return (-1);
}

int	parse_path(t_data *data)
{
	int 	index;
	
	index = find_line("PATH=", data->envp);
	data->path = ft_split_slash(&data->envp[index][5], ':');
	index = find_line("PWD=", data->envp);
	data->pwd = ft_strdup(&data->envp[index][4]);
	if (data->path == NULL && data->pwd == NULL)
		return (-1);
	return (1);
}

char	*check_access(t_data data, char *cmd)
{
	int		i;
	char	*fullname;

	i = -1;
	while (data.path[++i] != 0)
	{
		fullname = ft_strjoin(data.path[i], cmd);
		if (fullname == NULL)
			return (NULL);
		if (access(fullname, F_OK) == 0 && access(fullname, X_OK) == 0)
			return (fullname);
		free(fullname);
	}
	fullname = ft_strjoin(data.pwd, cmd);
	if (fullname == NULL)
		return (NULL);
	if (access(fullname, F_OK) == 0 && access(fullname, X_OK) == 0)
		return (fullname);
	free(fullname);
	return (NULL);
}