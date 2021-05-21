#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

int			get_next_line(int fd, char **line);


int main(void)
{
    char *line = 0;
    int ret;
    int fd;

    fd = open("test.txt", O_RDONLY);
    while ((ret = get_next_line(fd, &line)) > 0)
    {
        printf("%s\n", line);
        free(line);
    }
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