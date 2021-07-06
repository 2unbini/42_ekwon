#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

int main(void)
{
	char *argv[] = {"ls -l", NULL};
	int pid;
	int counter = 1;
	int fd = open("./file2.txt", O_WRONLY | O_CREAT);
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
		execve("/bin/ls", &argv[0], &argv[1]);
		printf("error\n");
	}
	else
	{
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
