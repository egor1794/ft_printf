/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymushet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 16:30:53 by ymushet           #+#    #+#             */
/*   Updated: 2016/12/12 16:31:52 by ymushet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *str)
{
	size_t index;
	size_t counter;
	size_t n;

	counter = ft_strlen(str) - 1;
	n = ft_strlen(str) / 2;
	index = 0;
	while (index < n)
	{
		ft_swap(&str[index], &str[counter]);
		index++;
		counter--;
	}
	return (str);
}
