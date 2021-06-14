
#include "ft_printf.h"
#include "libft.h"
#include <stdio.h>
#include <string.h>

int	test(char *s, ...)
{
	va_list ap;
	char	*c;

	va_start(ap, s);
	c = va_arg(ap, char *);
	printf("%d\n", strlen(c));
	/*
	while ((c = va_arg(ap, char*)))
	{
		printf("%s\n", c);
	}
	*/
	va_end(ap);
	return (0);
}

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
	printf("-->|%-4.*%|<--\n", -4);
	printf("-->|%-4.*%|<--\n", 0);
	printf("-->|%-4.*%|<--\n", 3);
	printf("%p\n", NULL);
	printf("%20p\n", NULL);
	printf("%.20p\n", &c);
	printf("%.d\n", 0);
	*/
	ft_printf("%5.-2d\n", 123);
	printf("[%5.*d]\n", -2, 123);
	ft_printf("-->|%*.*d|<--\n", 10, 1000, 1);
	printf("-->|%*.*d|<--\n", 10, 1000, 1);
	test("hello", "world", "i\'m", "eunbin", "a", "b", 'c');

	return (0);
}
