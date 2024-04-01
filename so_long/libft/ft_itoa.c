/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivnovomi <ivnovomi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 08:17:26 by ivnovomi          #+#    #+#             */
/*   Updated: 2023/10/05 21:55:44 by ivnovomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	nlen(long int num)
{
	size_t	i;

	i = 0;
	while (num >= 10)
	{
		num = num / 10;
		i++;
	}
	return (i + 1);
}

char	*ft_itoa(int n)
{
	char		*str;
	size_t		len;
	long int	num2;

	num2 = n;
	if (num2 < 0)
		num2 = num2 * -1;
	len = nlen(num2);
	if (n < 0)
		len++;
	str = (char *)malloc(len + 1);
	if (str == 0)
		return (NULL);
	str[len--] = '\0';
	if (num2 == 0)
		str[0] = 48;
	while (num2 > 0)
	{
		str[len--] = (num2 % 10) + 48;
		num2 = num2 / 10;
	}
	if (n < 0)
		str[0] = '-';
	return (str);
}
