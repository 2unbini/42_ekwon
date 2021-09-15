/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekwon <ekwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 14:17:55 by ekwon             #+#    #+#             */
/*   Updated: 2021/09/15 18:12:23 by ekwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	run_child_process(t_data data, int pipe_fd[]);
void	run_parent_process(t_data data, int pipe_fd[]);

int	main(int argc, char **argv, char **envp)
{
	int		pid;
	int		pipe_fd[2];
	t_data	data;

	if (argc != 5)
	{
		print_error("Error: Invalid number of Input");
		exit(-1);
	}
	init_data(&data, argv, envp);
	pipe(pipe_fd);
	pid = fork();
	if (pid < 0)
	{
		print_error("Error: Cannot make child Process");
		exit(-1);
	}
	else if (pid == 0)
		run_child_process(data, pipe_fd);
	else
	{
		wait(&pid);
		run_parent_process(data, pipe_fd);
	}
	return (0);
}

void	run_child_process(t_data data, int pipe_fd[])
{
	int		fd_in;

	fd_in = open(data.c.file_in, O_RDONLY);
	dup2(fd_in, 0);
	dup2(pipe_fd[1], 1);
	close(pipe_fd[0]);
	if (execve(data.c.exe_path, data.c.cmd_one, data.envp) == -1)
	{
		print_error("Error: Cannot Execute");
		exit(-1);
	}
}

void	run_parent_process(t_data data, int pipe_fd[])
{
	int	fd_out;

	fd_out = open(data.p.file_out, O_WRONLY | O_CREAT);
	dup2(pipe_fd[0], 0);
	close(pipe_fd[1]);
	dup2(fd_out, 1);
	if (execve(data.p.exe_path, data.p.cmd_two, data.envp) == -1)
	{
		print_error("Error: Cannot Execute");
		exit(-1);
	}
}
