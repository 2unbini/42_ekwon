#include <stdio.h>
int main(void)
{
	printf("[%4%]\n");
	printf("%4%c\n");
	printf("123avab%\n");
	printf("%%%c\n", 'c');
	printf("-0*%%\n");
	printf("[%-*.*c]\n", 5, 4, 'c');
	printf("[%-*.%]\n", 5);
	printf("[%- 75.2c]\n", 'c');
	printf("[%-5.*4c]\n", -2, 'c');
	printf("[%5.3c]\n", 'c');
	return (0);
}
