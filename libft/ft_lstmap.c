/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymushet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/16 12:33:18 by ymushet           #+#    #+#             */
/*   Updated: 2016/12/20 16:44:18 by ymushet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f) (t_list *elem))
{
	t_list	*head;
	t_list	*tmp;

	if (lst != NULL)
	{
		head = ft_lstnew(lst->content, lst->content_size);
		if ((head = f(head)) == NULL)
			return (NULL);
		tmp = head;
		lst = lst->next;
		while (lst != NULL)
		{
			if ((head->next = f(lst)) == NULL)
				return (NULL);
			head = head->next;
			lst = lst->next;
		}
		head->next = NULL;
		return (tmp);
	}
	return (NULL);
}
