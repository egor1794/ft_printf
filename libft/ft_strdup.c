/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymushet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 15:22:07 by ymushet           #+#    #+#             */
/*   Updated: 2016/12/06 20:43:55 by ymushet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	int	index;
	char*pointer;

	index = ft_strlen(str);
	pointer = (char *)malloc(sizeof(*str) * (index + 1));
	if (pointer)
	{
		ft_strcpy(pointer, str);
		pointer[index] = '\0';
		return (pointer);
	}
	return (NULL);
}
