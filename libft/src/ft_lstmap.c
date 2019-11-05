/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkirszba <rkirszba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 12:04:58 by rkirszba          #+#    #+#             */
/*   Updated: 2018/11/14 13:50:32 by rkirszba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*alst2;
	t_list	*lst2;
	t_list	*tmp;

	if (!lst)
		return (NULL);
	alst2 = NULL;
	tmp = f(lst);
	lst2 = ft_lstnew(tmp->content, tmp->content_size);
	alst2 = lst2;
	while (lst->next != NULL)
	{
		lst = lst->next;
		tmp = f(lst);
		lst2->next = ft_lstnew(tmp->content, tmp->content_size);
		lst2 = lst2->next;
		ft_lstaddq(&alst2, lst2);
	}
	return (alst2);
}
