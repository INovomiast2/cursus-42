/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivnovomi <ivnovomi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 11:44:47 by ivnovomi          #+#    #+#             */
/*   Updated: 2023/09/26 13:57:09 by ivnovomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	j = 0;
	k = 0;
	while (dst[i] != '\0')
		i++;
	while (src[k] != '\0')
		k++;
	if (dstsize <= i)
		k += dstsize;
	else
		k += i;
	while (src[j] != '\0' && i + 1 < dstsize)
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (k);
}

// int	main(void)
// {
// 	char	*src;
// 	size_t	dstsize;
// 	size_t	result;

// 	char dst[20] = "Hello";
// 	src = " World!";
// 	dstsize = 20;
// 	result = ft_strlcat(dst, src, dstsize);
// 	printf("Result: %zu\n", result);
// 	printf("dst: %s\n", dst);
// 	return (0);
// }
