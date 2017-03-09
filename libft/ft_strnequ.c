/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymushet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 20:21:20 by ymushet           #+#    #+#             */
/*   Updated: 2016/12/20 16:31:00 by ymushet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	size_t res;

	if (s1 == NULL || s2 == NULL)
		return (0);
	res = ft_strncmp(s1, s2, n);
	if (res == 0)
		return (1);
	return (0);
}
