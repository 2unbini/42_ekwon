#include "libft.h"
#include "ft_printf.h"
#include "getfunc.h"
#include <stdio.h>

int main(void)
{
	int d = 0;
	unsigned int u = 4294967161;
	ft_printf("-->|%-4.x|<--\n", u);
}
