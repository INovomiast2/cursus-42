/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivnovomi <ivnovomi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 20:38:01 by ivnovomi          #+#    #+#             */
/*   Updated: 2023/09/26 21:07:40 by ivnovomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	n_len;
	size_t	i;

	n_len = ft_strlen(needle);
	if (n_len == 0 || haystack == needle)
	{
		return ((char *)haystack);
	}
	while (*haystack != '\0' && len >= n_len)
	{
		i = 0;
		while (haystack[i] == needle[i] && needle[i] != '\0')
		{
			i++;
		}
		if (needle[i] == '\0')
		{
			return ((char *)haystack);
		}
		haystack++;
		len--;
	}
	return (NULL);
}
