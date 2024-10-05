/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkarika <filip.karika1@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 15:28:37 by fkarika           #+#    #+#             */
/*   Updated: 2024/10/04 15:28:38 by fkarika          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libraries/ft_printf.h"

int	ft_print_char(char c)
{
	return (write(1, &c, 1));
}
