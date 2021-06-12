#include "libft.h"
#include "ft_printf.h"
#include "getfunc.h"
#include <stdio.h>

int main(void)
{
	int d = 0;
	ft_printf("-->|%0*.*d|<--\n", 4, -4, d);
}
