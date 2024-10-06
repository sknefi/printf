/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkarika <filip.karika1@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 15:28:30 by fkarika           #+#    #+#             */
/*   Updated: 2024/10/04 16:15:05 by fkarika          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libraries/ft_printf.h"

static int	not_null_ptr(
		unsigned long long ptr, unsigned long long base, char *symbols)
{
	int	count;

	count = 0;
	if (ptr < base)
		return (ft_print_char(symbols[ptr]));
	else
	{
		count = ft_print_number(ptr / base, base, symbols);
		return (count + ft_print_number(ptr % base, base, symbols));
	}
}

int	ft_print_pointer(
		unsigned long long ptr, unsigned long long base, char *symbols)
{
	if (!ptr)
		return (write(1, "(nil)", 5));
	write(1, "0x", 2);
	return (not_null_ptr(ptr, base, symbols) + 2);
}
