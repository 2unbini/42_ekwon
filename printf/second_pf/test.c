
#include "ft_printf.h"
#include "libft.h"
#include <stdio.h>

int main(void)
{
	/*
	ft_printf("[%5d]\n", 10);
	printf("[%5d]\n", 10);
	*/

	char str[10] = "olleh";
	char c = 'c';
	//printf("%d\n", ft_strlen(str));
	//ft_putstr(str);
	printf("%.10s\n", str);
	printf("%.c\n", c);
	printf("|%10.d|\n", 0);
	printf("|%5.*3d|\n", 5, 4);
	printf("|%0*.*d|\n", 5, -4, -12);
	printf("|%0-5.4d|\n", -12);
	printf("|%0*.*d|\n", 1, -4, -12);
	return (0);
}
