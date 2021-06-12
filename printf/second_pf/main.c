#include "libft.h"
#include "ft_printf.h"
#include "getfunc.h"
#include <stdio.h>

int main(void)
{
	ft_printf("-->|%-4.*%|<--\n", -4);
	ft_printf("-->|%-4.*%|<--\n", 0);
	ft_printf("-->|%-4.*%|<--\n", 4);
}
