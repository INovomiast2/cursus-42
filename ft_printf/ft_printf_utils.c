/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivnovomi <ivnovomi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 16:33:06 by ivnovomi          #+#    #+#             */
/*   Updated: 2024/01/12 09:59:59 by ivnovomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_countn(long long nb)
{
	int	i;

	i = 0;
	while (nb >= 10)
	{
		i++;
		nb /= 10;
	}
	return (i + 1);
}

void	ft_putnbr(int n)
{
	if (n == -2147483648)
	{
		ft_print_char('-');
		ft_print_char('2');
		n = 147483648;
	}
	if (n < 0)
	{
		ft_print_char('-');
		n *= -1;
	}
	if (n >= 0 && n <= 9)
		ft_print_char(n + 48);
	else
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
}

// POR FALTA DE ESPACIO:
int	ft_print_ptr(unsigned long long ptr)
{
	int	i;

	i = 0;
	i += ft_print_str("0x");
	i += ft_print_hex(ptr, 'x');
	return (i);
}
