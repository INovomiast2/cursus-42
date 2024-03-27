/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivnovomi <ivnovomi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 13:29:35 by ivnovomi          #+#    #+#             */
/*   Updated: 2023/09/16 14:40:24 by ivnovomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	*ft_memcpy(void *dst, void *src, size_t n)
{
	size_t	i;
	char	*dest;
	char	*srce;

	i = 0;
	dest = (char *)dst;
	srce = (char *)src;
	if (!src && !dst)
		return (0);
	while (i < n)
	{
		dest[i] = (char)srce[i];
		i++;
	}
	return (dest);
}

/*
int main(void)
{
	char src[] = "Hello World!";
	char dest[] = "1234567890";
	char *p1;
	char *p2;

	p1 = src;
	p2 = dest;
	printf("Before memcpy dest = %s\n", dest);
	ft_memcpy(p2, p1, 5);
	printf("After memcpy dest = %s\n", dest);
	return (0);
}
*/