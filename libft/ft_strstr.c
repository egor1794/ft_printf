/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymushet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 22:24:03 by ymushet           #+#    #+#             */
/*   Updated: 2016/12/19 19:07:29 by ymushet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	char *ptrl;
	char *ptrb;

	if (*little == '\0')
		return ((char*)big);
	while (*big)
	{
		ptrb = (char*)big;
		ptrl = (char*)little;
		while (*ptrb == *ptrl && *ptrb != '\0' && *ptrl != '\0')
		{
			ptrl++;
			ptrb++;
		}
		if (*ptrl == '\0')
			return ((char*)big);
		big++;
	}
	return (NULL);
}
