/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymushet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/16 11:41:41 by ymushet           #+#    #+#             */
/*   Updated: 2016/12/20 16:42:42 by ymushet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del) (void *, size_t))
{
	t_list *node;
	t_list *tmp;

	if (alst == NULL)
		return ;
	if (alst)
	{
		node = *alst;
		while (node != NULL)
		{
			tmp = node->next;
			del(node->content, node->content_size);
			free(node);
			node = NULL;
			node = tmp;
		}
		*alst = NULL;
	}
}
