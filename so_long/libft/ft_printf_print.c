/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_print.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivnovomi <ivnovomi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 14:11:57 by ivnovomi          #+#    #+#             */
/*   Updated: 2024/03/25 12:22:28 by ivnovomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_char(char c)
{
	int	writen_byte;

	writen_byte = write(1, &c, 1);
	if (writen_byte == -1)
		return (-1);
	return (1);
}

int	ft_print_str(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (ft_print_str("(null)"));
	while (str[i] != '\0')
	{
		ft_print_char(str[i]);
		i++;
	}
	return (i);
}

int	ft_print_dec(int nb)
{
	long int	n;

	n = 0;
	ft_putnbr(nb);
	if (nb >= 0)
		return (ft_countn(nb));
	n = (long int)nb * (-1);
	return (ft_countn(n) + 1);
}

int	ft_print_uns(unsigned int nb)
{
	int	i;

	i = 0;
	if (nb >= 10)
		i += ft_print_uns(nb / 10);
	ft_print_char(nb % 10 + '0');
	i++;
	return (i);
}

int	ft_print_hex(unsigned long long nb, char c)
{
	unsigned long long	i;

	i = 0;
	if (nb >= 16)
		i += ft_print_hex(nb / 16, c);
	if (c == 'x')
		ft_print_char("0123456789abcdef"[nb % 16]);
	if (c == 'X')
		ft_print_char("0123456789ABCDEF"[nb % 16]);
	i++;
	return (i);
}
