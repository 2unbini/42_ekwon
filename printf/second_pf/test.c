
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
	printf("%d\n", ft_strlen(str));
	ft_putstr(str);
	return (0);
}
