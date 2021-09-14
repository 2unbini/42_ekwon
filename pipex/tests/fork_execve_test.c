#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

char *ft_strjoin(char *s1, char *s2);

int main(int argc, char **argv, char **envp)
{
	int pid;
	int counter = 1;
	int fd = open("./file.txt", O_WRONLY | O_CREAT);
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
		printf("fork start\n");
		dup2(pipe_fd[1], 1);
		close(pipe_fd[0]);

		char path = ft_strjoin("/usr/bin/", argv[1]);
		char** command;
		command = (char**)malloc(sizeof(char*) * 2);
		command[0] = argv[1];
		command[1] = '\0';
		int execve_status = execve(path, command, envp);
		if (execve_status == -1)
		{
			write(2, "cannot execute\n", 12);
			exit(0);
		}
		free(path);
		free(command);
		write(1, "write child\n", 12);
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

int	ft_strlen(char *s)
{
	int len;

	len = 0;
	if (s == NULL)
		return (0);
	while (s[len] != '\0')
		len++;
	return (len);
}

char *ft_strjoin(char *s1, char *s2)
{
	int i;
	char *ret;
	int s1_len;
	int s2_len;

	i = 0;
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	ret = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (!ret)
		return (NULL);
	while (*s1 != '\0')
		ret[i++] = *s1++;
	while (*s2 != '\0')
		ret[i++] = *s2++;
	ret[i] = '\0';
	return (ret);
}
