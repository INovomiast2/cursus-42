/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivnovomi <ivnovomi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 18:03:10 by ivnovomi          #+#    #+#             */
/*   Updated: 2023/09/17 07:35:58 by ivnovomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*p_str1;
	unsigned const char	*p_str2;

	if (dst < src)
		return (ft_memcpy(dst, src, len));
	p_str1 = (unsigned char *)dst;
	p_str2 = (unsigned const char *)src;
	if (!len || dst == src)
		return (dst);
	while (len--)
		p_str1[len] = p_str2[len];
	return (dst);
}
