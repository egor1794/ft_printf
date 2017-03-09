/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymushet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 10:54:47 by ymushet           #+#    #+#             */
/*   Updated: 2016/12/20 16:31:41 by ymushet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*p;
	size_t				i;

	i = n;
	p = (unsigned char *)s;
	if (n != 0)
	{
		while (i > 0)
		{
			if (*p++ == (unsigned char)c)
				return ((void *)(p - 1));
			i--;
		}
	}
	return (NULL);
}
