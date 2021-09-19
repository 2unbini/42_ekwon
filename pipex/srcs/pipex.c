/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekwon <ekwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 14:17:55 by ekwon             #+#    #+#             */
/*   Updated: 2021/09/19 17:44:07 by ekwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	pid_t	pid;
	int		status;
	t_data	data;

	if (argc != 5)
	{
		perror("Error: Invalid number of Input");
		exit(1);
	}
	init_data(&data, argv, envp);
	pid = fork();
	if (pid < 0)
	{
		perror("Error: Cannot make child Process");
		exit(1);
	}
	if (pid == 0)
		run_child_process(data, data.pipe_fd);
	else
	{
		waitpid(pid, &status, WNOHANG);
		run_parent_process(data, data.pipe_fd);
	}
	return (0);
}

void	run_child_process(t_data data, int pipe_fd[])
{
	int	fd_in;

	fd_in = open(data.c.file_in, O_RDONLY);
	if (fd_in < 0)
	{
		perror("Error: No such file");
		exit(1);
	}
	dup2(fd_in, 0);
	dup2(pipe_fd[1], 1);
	close(pipe_fd[0]);
	if (execve(data.c.exe_path, data.c.cmd_one, data.envp) == -1)
	{
		perror("Error: Cannot Execute");
		exit(1);
	}
}

void	run_parent_process(t_data data, int pipe_fd[])
{
	int	fd_out;

	fd_out = open(data.p.file_out, O_WRONLY | O_TRUNC | O_CREAT, S_IRWXU);
	if (fd_out < 0)
	{
		perror("Error: Cannot open file");
		exit(1);
	}
	dup2(pipe_fd[0], 0);
	close(pipe_fd[1]);
	dup2(fd_out, 1);
	if (execve(data.p.exe_path, data.p.cmd_two, data.envp) == -1)
	{
		perror("Error: Cannot Execute");
		exit(1);
	}
}
