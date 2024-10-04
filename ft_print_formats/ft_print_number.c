#include "../libraries/ft_printf.h"

int	ft_print_number(long n, int base, char *symbols)
{
	int	count;

	count = 0;
	if (n < 0)
	{
		write(1, "-", 1);
		return (ft_print_number(-n, base, symbols) + 1);
	}
	else if (n < base)
		return (ft_print_char(symbols[n]));
	else
	{
		count = ft_print_number(n / base, base, symbols);
		return (count + ft_print_number(n % base, base, symbols));
	}
}
