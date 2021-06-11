#include "libft.h"
#include "ft_printf.h"
#include "getfunc.h"
#include <stdio.h>

int main(void)
{
	int d = -135;
	ft_printf("-->|%-3.*d|<--\n", 4, d);
	ft_printf("-->|%-3.0d|<--\n", d);
}
