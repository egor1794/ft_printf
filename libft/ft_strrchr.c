/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymushet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 22:07:29 by ymushet           #+#    #+#             */
/*   Updated: 2016/12/19 22:32:02 by ymushet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*res;
	char	*ptr;

	ptr = (char *)s;
	res = NULL;
	while (*ptr)
	{
		if (*ptr == (char)c)
			res = ptr;
		ptr++;
	}
	if (*ptr == (char)c)
		res = ptr;
	return (res);
}
