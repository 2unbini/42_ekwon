#include <fcntl.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <string.h>

int get_next_line(int fd, char **line);

/*
void check(bool succes)
{
	if (succes)
		printf("success\n");
	else
		printf("fail\n");
}
int main(void)
{
	int r = -1;
	char *s = NULL;
	char *line = NULL;
	int gnlReturn = get_next_line(1000, &line);
	printf("%d\n", gnlReturn);
	printf("%d\n", (s == NULL ? line == NULL : !strcmp(line, s)));
	printf("%d\n", (r == gnlReturn && (s == NULL ? line == NULL : !strcmp(line, s))));
	check(r == gnlReturn && (s == NULL ? line == NULL : !strcmp(line, s)));
	//free(line);
}
*/

int main(void)
{
	char *line = 0;
	int ret;
	int fd;

	fd = open("test.txt", O_RDONLY);
	while ((ret = get_next_line(1000, &line)) > 0)
	{
		printf("%d\n", ret);
		printf("%s\n", line);
		free(line);
	}
	printf("%d\n", ret);
	printf("%s\n", line);
	free(line);
	return (0);
}

/*
int main(void)
{
	char buf[100];
	int fd;
	int i = 0;

	fd = open("test.txt", O_RDONLY);
	if (fd == -1)
	{
		puts("open error");
		return (0);
	}
	if (read(fd, buf, BUFF_SIZE) == -1)
	{
		puts("read error");
		return (0);
	}
	while (buf[i] != '\n')
		printf("%c", buf[i++]);
	close(fd);
	return (0);
}
*/