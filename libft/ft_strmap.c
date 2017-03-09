/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymushet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 16:09:55 by ymushet           #+#    #+#             */
/*   Updated: 2016/12/16 19:01:10 by ymushet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f) (char))
{
	char	*ptr;
	int		index;

	if (s == NULL || f == NULL)
		return (NULL);
	index = 0;
	ptr = ft_strnew(ft_strlen(s));
	if (ptr)
	{
		while (s[index] != '\0')
		{
			ptr[index] = (*f)(s[index]);
			index++;
		}
		return (ptr);
	}
	else
		return (NULL);
}
