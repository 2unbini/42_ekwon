#include <stdio.h>
#include <unistd.h>

int main(void)
{
	char *argv[] = {"ls -l", NULL};
	printf("execve start\n");
	execve("/bin/ls", &argv[0], &argv[1]);
	printf("error\n");
	return (0);
}
