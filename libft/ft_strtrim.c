/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymushet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 14:11:11 by ymushet           #+#    #+#             */
/*   Updated: 2016/12/20 16:30:25 by ymushet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*src;
	char	*ptr;
	size_t	begin;
	size_t	end;
	size_t	size;

	src = (char *)s;
	if (s != NULL)
	{
		begin = ft_begin(src);
		if (src[begin] == '\0')
			return (ft_strnew(0));
		end = ft_end(src);
		size = end - begin + 1;
		if ((ptr = ft_strsub(s, (unsigned int)begin, size)) == NULL)
			return (0);
		return (ptr);
	}
	return (NULL);
}
