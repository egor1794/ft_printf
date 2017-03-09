/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymushet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 17:48:45 by ymushet           #+#    #+#             */
/*   Updated: 2016/12/16 19:06:07 by ymushet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f) (unsigned int, char))
{
	char			*ptr;
	unsigned int	index;

	if (s == NULL || f == NULL)
		return (NULL);
	index = 0;
	ptr = ft_strnew(ft_strlen(s));
	if (ptr)
	{
		while (s[index] != '\0')
		{
			ptr[index] = (*f)(index, s[index]);
			index++;
		}
		return (ptr);
	}
	else
		return (NULL);
}
