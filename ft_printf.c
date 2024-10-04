#include "libraries/ft_printf.h"

void	ft_handle_format(char c, va_list args, int *count)
{
	if (c == 's')
		(*count) += ft_print_string(va_arg(args, char *));
	else if (c == 'c')
		(*count) += ft_print_char((char)va_arg(args, int));
	else if (c == 'd' || c == 'i')
		(*count) += ft_print_number(va_arg(args, int), 10, DEC);
	else if (c == 'u')
		(*count) += ft_print_number(
				(unsigned long)va_arg(args, unsigned int), 10, DEC);
	else if (c == 'x')
		(*count) += ft_print_number(
				va_arg(args, unsigned int), 16, HEX);
	else if (c == 'X')
		(*count) += ft_print_number(
				va_arg(args, unsigned int), 16, UP_HEX);
	else if (c == 'p')
	{
		(*count) += write(1, "0x", 2);
		(*count) += ft_print_pointer(
				(unsigned long long)va_arg(args, void *), 16, HEX);
	}
	else
		(*count) += write(1, &c, 1);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		count;
	va_list	args;

	i = 0;
	count = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			if (str[++i])
				ft_handle_format(str[i], args, &count);
		}
		else
			count += write(1, &str[i], 1);
		i++;
	}
	va_end(args);
	return (count);
}

// int		main(void)
// {
// 	write(1, "\n", 1);

// 	printf("%d\n", ft_printf("> %x - ", 543));
// 	printf("%d\n", printf("> %x - ", 543));

// 	write(1, "\n", 1);

// 	printf("%d\n", ft_printf("> %s - ", "Ahoj ako sa mas"));
// 	printf("%d\n", printf(   "> %s - ", "Ahoj ako sa mas"));

// 	write(1, "\n", 1);

// 	printf("%d\n", ft_printf("> %d - ", 6910));
// 	printf("%d\n", printf(   "> %d - ", 6910));

// 	write(1, "\n", 1);

// 	printf("%d\n", ft_printf("> %i - ", 71292));
// 	printf("%d\n", printf(   "> %i - ", 71292));

// 	write(1, "\n", 1);

// 	printf("%d\n", ft_printf("> %x - ", 32012));
// 	printf("%d\n", printf(   "> %x - ", 32012));


// 	write(1, "\n", 1);

// 	printf("%d\n", ft_printf("> %x - ", -42178));
// 	printf("%d\n", printf(   "> %x - ", -42178));

// 	write(1, "\n", 1);

// 	printf("%d\n", ft_printf("> %X - ", -42178));
// 	printf("%d\n", printf(   "> %X - ", -42178));

// 	write(1, "\n", 1);

// 	printf("%d\n", ft_printf("> %X - ", 32012));
// 	printf("%d\n", printf(   "> %X - ", 32012));

// 	write(1, "\n", 1);

// 	printf("%d\n", ft_printf("> %u - ",  4294967295));
// 	printf("%d\n", printf(   "> %ld - ", 4294967295));
	
// 	write(1, "\n", 1);

// 	int		a;
// 	printf("%d\n", ft_printf("> %p - ", &a));
// 	printf("%d\n", printf(   "> %p - ", &a));

// 	write(1, "\n", 1);

// 	char *b = NULL;
// 	printf("%d\n", ft_printf("> %p - ", b));
// 	printf("%d\n", printf(   "> %p - ", b));

// 	// multiple params

// 	write(1, "\n", 1);

// 	printf("%d\n", ft_printf("> %x %c %d  - ", 543, 'c', 1025));
// 	printf("%d\n", printf(   "> %x %c %d  - ", 543, 'c', 1025));
	
// 	return (0);
// }