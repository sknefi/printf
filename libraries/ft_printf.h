#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "stdio.h"
# include <unistd.h>

# define DEC "0123456789"
# define HEX "0123456789abcdef"
# define UP_HEX "0123456789ABCDEF"

int		ft_print_char(char c);
int		ft_print_string(char *str);
int		ft_print_number(long n, int base, char *symbols);
int		ft_print_pointer(
			unsigned long long ptr, unsigned long long base, char *symbols);

#endif