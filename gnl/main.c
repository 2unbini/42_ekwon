#include <fcntl.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int get_next_line(int fd, char **line);

int main()
{
	int fd;
	int i;
	int j;
	char *line = 0;

	j = 1;
	printf("\n==========================================\n");
	printf("========== TEST 1 : The Alphabet =========\n");
	printf("==========================================\n\n");

	if (!(fd = open("/Users/eunbin/cardet/gnl/42testers-gnl/files/huge_alphabet", O_RDONLY)))
	{
		printf("\nError in open\n");
		return (0);
	}
	while ((i = get_next_line(fd, &line)) > 0)
	{
		printf("|%s\n", line);
		free(line);
		j++;
	}
	printf("|%s\n", line);
	free(line);
	close(fd);

	if (i == -1)
		printf("\nError in Fonction - Returned -1\n");
	else if (j == 1056)
		printf("\nRight number of lines\n");
	else if (j != 1056)
		printf("\nNot Good - Wrong Number Of Lines\n");
	j = 1;
	printf("\n==========================================\n");
	printf("========= TEST 8 : SUPER FAT FILE ========\n");
	printf("==========================================\n\n");

	if (!(fd = open("/Users/eunbin/cardet/gnl/42testers-gnl/files/huge_file", O_RDONLY)))
	{
		printf("\nError in open\n");
		return (0);
	}
	while ((i = get_next_line(fd, &line)) > 0)
	{
		printf("|%s\n", line);
		free(line);
		j++;
	}
	printf("|%s\n", line);
	free(line);
	close(fd);

	if (i == -1)
		printf("\nError in Fonction - Returned -1\n");
	else if (j == 2916)
		printf("\nRight number of lines\n");
	else if (j != 2916)
		printf("\nNot Good - Wrong Number Of Lines\n");
	j = 1;
	printf("\n==========================================\n");
	printf("======== TEST 8 : SUPER LONG LINE ========\n");
	printf("==========================================\n\n");

	if (!(fd = open("/Users/eunbin/cardet/gnl/42testers-gnl/files/huge_line", O_RDONLY)))
	{
		printf("\nError in open\n");
		return (0);
	}
	while ((i = get_next_line(fd, &line)) > 0)
	{
		printf("%s\n", line);
		free(line);
		j++;
	}
	printf("%s\n", line);
	free(line);
	close(fd);

	if (i == -1)
		printf("\nError in Fonction - Returned -1\n\n");
	else if (j == 1)
		printf("\nRight number of lines\n\n");
	else if (j != 1)
		printf("\nNot Good - Wrong Number Of Lines\n\n");
	return (0);
}

/*
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
*/
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