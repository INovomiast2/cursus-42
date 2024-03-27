/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivnovomi <ivnovomi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 14:33:27 by ivnovomi          #+#    #+#             */
/*   Updated: 2023/12/08 16:42:44 by ivnovomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_find(char const *con, int i, va_list *args)
{
	int	c;

	c = 0;
	if (con[i] == 'c')
		c += ft_print_char(va_arg(*args, int));
	if (con[i] == 's')
		c += ft_print_str(va_arg(*args, char *));
	if (con[i] == 'p')
		c += ft_print_ptr(va_arg(*args, unsigned long long));
	if (con[i] == 'u')
		c += ft_print_uns(va_arg(*args, unsigned int));
	if (con[i] == 'd' || con[i] == 'i')
		c += ft_print_dec(va_arg(*args, int));
	if (con[i] == 'x' || con[i] == 'X')
		c += ft_print_hex(va_arg(*args, unsigned int), con[i]);
	if (con[i] == '%')
		c += ft_print_char('%');
	return (c);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (write(1, "", 0) == -1)
		return (-1);
	va_start(args, format);
	while (format[i])
	{
		if (format[i] != '%')
			j += ft_print_char(format[i]);
		else
		{
			i++;
			j += ft_find(format, i, &args);
		}
		i++;
	}
	va_end(args);
	return (j);
}
