#include <stdio.h>
int main(void)
{
	//int num = 3;
	printf("[%4%]\n");
	//printf("%4%d\n", num);
	printf("%%\n");
	printf("%%%d\n", 3);
	printf("-0*%%\n");
	printf("[%-*.d]\n", 5, 5);
	printf("[%-*.%]\n", 5);
	return (0);
}
