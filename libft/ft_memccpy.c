/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymushet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 15:29:47 by ymushet           #+#    #+#             */
/*   Updated: 2016/12/20 16:29:48 by ymushet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*ptrdst;
	unsigned char	*ptrsrc;

	ptrdst = (unsigned char *)dst;
	ptrsrc = (unsigned char *)src;
	while (n > 0)
	{
		if (*ptrsrc == (unsigned char)c)
		{
			*ptrdst = *ptrsrc;
			return ((void *)ptrdst + 1);
		}
		else
			*ptrdst++ = *ptrsrc++;
		n--;
	}
	return (NULL);
}
