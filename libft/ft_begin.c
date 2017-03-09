/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_begin.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymushet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 19:04:34 by ymushet           #+#    #+#             */
/*   Updated: 2016/12/08 14:25:36 by ymushet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_begin(char const *s)
{
	size_t begin;

	begin = 0;
	while (s[begin])
		if (ft_isspace(s[begin]))
			begin++;
		else
			break ;
	return (begin);
}
