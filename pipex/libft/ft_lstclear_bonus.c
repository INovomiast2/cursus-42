/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivnovomi <ivnovomi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 23:40:26 by ivnovomi          #+#    #+#             */
/*   Updated: 2023/10/06 00:14:04 by ivnovomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*actual;

	if (!lst || !del)
		return ;
	while ((*lst))
	{
		del((*lst)->content);
		actual = *lst;
		*lst = actual->next;
		free(actual);
	}
	*lst = 0;
}
