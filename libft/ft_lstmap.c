/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amedvedi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 12:34:26 by amedvedi          #+#    #+#             */
/*   Updated: 2017/11/21 15:11:41 by amedvedi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*map;
	t_list	*lstmap;

	if (!lst || !f)
		return (NULL);
	lstmap = ft_memalloc(sizeof(lst));
	if (!lst)
		return (NULL);
	lstmap = f(lst);
	if (!lstmap)
		return (NULL);
	map = lstmap;
	while (lst->next)
	{
		lst = lst->next;
		lstmap->next = f(lst);
		if (!(lstmap->next))
		{
			free(lstmap->next);
			lstmap->next = NULL;
			lstmap->next->content_size = 0;
		}
		lstmap = lstmap->next;
	}
	return (map);
}
