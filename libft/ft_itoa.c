/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymushet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/11 14:21:29 by ymushet           #+#    #+#             */
/*   Updated: 2016/12/19 14:15:44 by ymushet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char			*str;
	int				index;
	int				digit;
	unsigned int	nb;

	if (!(str = (char*)malloc(sizeof(*str) * (ft_ndigits(n) + ft_sign(n) + 1))))
		return (NULL);
	index = ft_ndigits(n) + ft_sign(n);
	str[index--] = '\0';
	nb = ft_is_minint(n);
	while (index >= 0)
	{
		digit = nb % 10;
		str[index] = digit + '0';
		nb /= 10;
		index--;
	}
	if (n < 0)
		str[0] = '-';
	return (str);
}
