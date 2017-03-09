/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymushet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 12:30:54 by ymushet           #+#    #+#             */
/*   Updated: 2016/12/10 19:13:35 by ymushet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*s1;
	unsigned char	*s2;
	size_t			i;

	s1 = (unsigned char *)src;
	s2 = (unsigned char *)dst;
	i = len;
	if (src == dst)
		return (dst);
	if (src < dst)
	{
		while (i-- > 0)
			s2[i] = s1[i];
	}
	else
	{
		i = 0;
		while (i++ < len)
			*s2++ = *s1++;
	}
	return (dst);
}
