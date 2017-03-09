/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_end.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymushet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 19:07:02 by ymushet           #+#    #+#             */
/*   Updated: 2016/12/14 18:11:01 by ymushet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_end(char const *s)
{
	long	index;

	index = 0;
	index = ft_strlen(s) - 1;
	while (index >= 0)
	{
		if (ft_isspace(s[index]))
			index--;
		else
			break ;
	}
	return ((size_t)index);
}
