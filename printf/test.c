#include <stdio.h>
int main(void)
{
	printf("[%4%]\n");
	printf("%4%d\n");
	printf("%%\n");
	printf("%%%d\n", 3);
	printf("-0*%%\n");
	printf("[%-*.*d]\n", 5, 4, 3);
	printf("[%-*.%]\n", 5);
	printf("[%- 75.2d]\n", 4);
	printf("[%-5.*4d]\n", -2, 4);
	return (0);
}
