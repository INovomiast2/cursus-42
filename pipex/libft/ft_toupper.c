/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivnovomi <ivnovomi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 14:31:48 by ivnovomi          #+#    #+#             */
/*   Updated: 2023/09/26 14:43:45 by ivnovomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z' )
	{
		return (c - 32);
	}
	return (c);
}

// int	main(void)
// {
// 	int	c;

// 	c = 'a';
// 	printf("Character: %c \n", c);
// 	printf("Upper: %c", ft_toupper(c));
// 	return (0);
// }