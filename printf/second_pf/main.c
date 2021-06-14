#include "libft.h"
#include "ft_printf.h"
#include "getfunc.h"
#include <stdio.h>

int main(void)
{
	void *p = NULL;
	printf("-->|%-10.p|<--\n", p);
	ft_printf("-->|%-10.p|<--\n", p);
	printf("-->|%.10p|<--\n", p);
	ft_printf("-->|%.10p|<--\n", p);
	printf("-->|%3.p|<--\n", p);
	ft_printf("-->|%3.p|<--\n", p);

	return (0);
}
