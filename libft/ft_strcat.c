/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymushet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 16:21:11 by ymushet           #+#    #+#             */
/*   Updated: 2016/12/19 17:47:04 by ymushet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *dest, const char *src)
{
	int index;
	int destlen;

	destlen = ft_strlen(dest);
	index = 0;
	while (src[index] != '\0')
	{
		dest[destlen + index] = src[index];
		index++;
	}
	dest[destlen + index] = '\0';
	return (dest);
}
