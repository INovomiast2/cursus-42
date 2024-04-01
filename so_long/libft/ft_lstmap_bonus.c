/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivnovomi <ivnovomi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 09:32:35 by ivnovomi          #+#    #+#             */
/*   Updated: 2023/10/10 19:38:22 by ivnovomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*nd;
	void	*new_content;

	if (!lst)
		return (NULL);
	new_list = NULL;
	while (lst)
	{
		new_content = f(lst->content);
		nd = ft_lstnew(new_content);
		if (!nd)
		{
			del(new_content);
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		ft_lstadd_back(&new_list, nd);
		lst = lst->next;
	}
	return (new_list);
}
