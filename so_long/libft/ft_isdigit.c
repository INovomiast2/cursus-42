/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivnovomi <ivnovomi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 14:28:27 by ivnovomi          #+#    #+#             */
/*   Updated: 2023/09/12 16:15:06 by ivnovomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isdigit(int chr)
{
	if (chr >= 48 && chr <= 57)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

// int main(void)
// {
// 	printf("42, Is Digit?: %d", ft_isdigit('4'));
// 	printf("X, Is Digit?: %d", ft_isdigit('X'));
// 	return (0);
// }