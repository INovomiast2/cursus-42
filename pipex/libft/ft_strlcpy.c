/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivnovomi <ivnovomi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 14:31:35 by ivnovomi          #+#    #+#             */
/*   Updated: 2023/09/26 14:29:36 by ivnovomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	while (*src && i + 1 < dstsize)
	{
		*dst++ = *src++;
		++i;
	}
	if (i < dstsize)
	{
		*dst = 0;
	}
	while (*src++)
	{
		++i;
	}
	return (i);
}

/*
int main()
{
	char *src = "Hello";
	char dst[10];
	int i;

	i = ft_strlcpy(dst, src, 0);
	printf("%d\n", i);
	printf("%s\n", dst);
	return (0);
}
*/