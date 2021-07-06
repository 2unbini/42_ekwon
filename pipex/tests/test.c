#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

void work(char *query)
{
	char *const argv[] = {query, NULL};
	char *const envp[] = {NULL};
	execve(query, argv, envp);
}

int main(void)
{
	char *command[2] = {"/bin/ls", "/usr/bin/wc"}
	int status = 0;
	int pi[2];
	pipe(pi);
	int pid = fork();

	if (pid == 0)
	{
		dup2(pi[1], 1);
		close(pi[0]);
		close(pi[1]);
		work(command[0]);
	}
	else
	{
		while (!waitpid(pid, &status, WNOHANG));
		dup2(pi[0], 0);
		close(pi[0]);
		close(pi[1]);
		work(command[1]);
	}
	return (0);
}
