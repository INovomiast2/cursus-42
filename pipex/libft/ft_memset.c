/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivnovomi <ivnovomi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 11:50:13 by ivnovomi          #+#    #+#             */
/*   Updated: 2023/09/17 07:15:40 by ivnovomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*str;

	i = 0;
	str = (unsigned char *)b;
	while (i < len)
	{
		str[i++] = (unsigned char)c;
	}
	return (b);
}

/*
int main(void)
{
 	char str[50] = "Hello world";
 	ft_memset(str, 'a', 6);
 	printf("%s", str);
 	return (0);
}
*/
