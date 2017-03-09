/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymushet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 13:00:30 by ymushet           #+#    #+#             */
/*   Updated: 2016/12/14 18:54:04 by ymushet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char		*ptr;
	const char	*st;

	if (s == NULL)
		return (NULL);
	st = &s[start];
	ptr = ft_strnew(len);
	if (ptr)
		return ((char *)ft_strncpy(ptr, (char *)st, len));
	return (NULL);
}
