/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymushet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 12:37:44 by ymushet           #+#    #+#             */
/*   Updated: 2016/12/20 16:36:52 by ymushet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*node;

	if ((node = (t_list*)malloc(sizeof(*node))) == NULL)
		return (NULL);
	if (content == NULL)
	{
		node->content = NULL;
		node->content_size = 0;
	}
	else
	{
		if ((node->content = malloc(content_size)) == NULL)
		{
			free(node);
			return (NULL);
		}
		ft_memcpy((node->content), content, content_size);
		node->content_size = content_size;
	}
	node->next = NULL;
	return (node);
}
