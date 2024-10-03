#include "../libraries/ft_printf.h"


int ft_print_pointer(unsigned long long ptr, unsigned long long base, char *symbols)
{
    int count;

    count = 0;
    if (ptr < base)
        return (ft_print_char(symbols[ptr]));
    else
    {
        count = ft_print_number(ptr / base, base, symbols);
        return (count + ft_print_number(ptr % base, base, symbols));
    }
}
