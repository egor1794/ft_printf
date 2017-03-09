/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymushet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 17:16:20 by ymushet           #+#    #+#             */
/*   Updated: 2016/12/14 19:21:13 by ymushet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char const *s, int fd)
{
	int index;

	if (s == NULL)
		return ;
	index = 0;
	if (fd >= 0)
		while (s[index])
			ft_putchar_fd(s[index++], fd);
}
