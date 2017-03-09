/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymushet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 11:58:45 by ymushet           #+#    #+#             */
/*   Updated: 2016/12/19 19:16:24 by ymushet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	char	*b;
	char	*l;
	size_t	k;

	b = (char *)big;
	l = (char *)little;
	if (*little == '\0')
		return ((char *)big);
	while (*big && len > 0)
	{
		b = (char *)big;
		l = (char *)little;
		k = len;
		while (*b == *l && *b != '\0' && *l != '\0' && k > 0)
		{
			l++;
			b++;
			k--;
		}
		if (*l == '\0')
			return ((char *)big);
		big++;
		len--;
	}
	return (NULL);
}
