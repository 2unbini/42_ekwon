
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
	/*
	printf("%.10s\n", str);
	printf("%.c\n", c);
	printf("|%10.d|\n", 0);
	printf("|%5.*3d|\n", 5, 4);
	printf("|%0*.*d|\n", 5, -4, -12);
	printf("|%0-5.4d|\n", -12);
	printf("|%0*.*d|\n", 1, -4, -12);
	printf("%.d\n", 0);
	printf("%.d\n", 10);
	printf("%3\n");
	*/
	printf("-->|%-4.*%|<--\n", -4);
	printf("-->|%-4.*%|<--\n", 0);
	printf("-->|%-4.*%|<--\n", 3);
	return (0);
}
