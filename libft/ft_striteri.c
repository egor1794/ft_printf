/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymushet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 18:08:11 by ymushet           #+#    #+#             */
/*   Updated: 2016/12/20 16:20:38 by ymushet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f) (unsigned int, char *))
{
	size_t index;

	index = 0;
	if (s != NULL && *f != NULL)
	{
		while (s[index] != '\0')
		{
			(*f)(index, &s[index]);
			index++;
		}
	}
}
