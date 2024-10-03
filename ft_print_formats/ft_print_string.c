#include "../libraries/ft_printf.h"

int ft_print_string(char *str)
{
    int count;

    count = 0;
    while (*str)
        count += write(1, str++, 1);
    return (count);
}
