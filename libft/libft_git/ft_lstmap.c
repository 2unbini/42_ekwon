/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekwon <ekwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 16:48:54 by ekwon             #+#    #+#             */
/*   Updated: 2021/05/10 17:59:35 by ekwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*cp_lst;
	t_list	*start;
	t_list	*tmp;

	if (!lst || !f || !del)
		return (NULL);
	if (!(cp_lst = ft_lstnew(f(lst->content))))
		return (NULL);
	start = cp_lst;
	while (lst->next)
	{
		lst = lst->next;
		cp_lst->next = ft_lstnew(f(lst->content));
		if (!(cp_lst->next))
		{
			ft_lstclear(&start, del);
			return (NULL);
		}
	}
	cp_lst->next = NULL;
	return (cp_lst);
}
