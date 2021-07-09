#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

int main(int argc, char **argv, char **envp)
{
	int pid;
	int counter = 1;
	int fd = open("./file4.txt", O_WRONLY | O_CREAT);
	int pipe_fd[2];
	char buf;

	pipe(pipe_fd);
	pid = fork();
	if (pid < 0)
	{
		printf("error\n");
		exit (-1);
	}
	else if (pid == 0)
	{
		printf("child\n");
		printf("execve start\n");
		dup2(pipe_fd[1], 1);
		close(pipe_fd[0]);
		int a = execve("hello", &argv[1], envp);
		if (a == -1)
		{
			write(2, "this is a\n", 10);
			a = execve("/bin/ls", &argv[1], envp);
			printf("hello ?? : %d\n", a);
		}
		write(2, "why exe?\n", 9);
		write(1, "33error\n", 8);
	}
	else
	{
		wait(&pid);
		printf("parent\n");
		dup2(pipe_fd[0], 0);
		close(pipe_fd[1]);
		while (read(pipe_fd[0], &buf, 1))
			write(fd, &buf, 1);
		close(fd);
		printf("process complete\n");
	}
	return (0);
}
