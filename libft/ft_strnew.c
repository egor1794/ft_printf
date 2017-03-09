/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymushet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 13:46:26 by ymushet           #+#    #+#             */
/*   Updated: 2016/12/20 16:40:25 by ymushet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*ptr;

	ptr = (char *)malloc(size + 1);
	if (ptr == 0)
		return (NULL);
	if (ptr)
	{
		ft_bzero(ptr, size + 1);
		return ((char *)ptr);
	}
	return (NULL);
}
