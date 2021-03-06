/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puendl_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymushet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 17:49:17 by ymushet           #+#    #+#             */
/*   Updated: 2016/12/14 19:22:30 by ymushet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char const *s, int fd)
{
	if (s == NULL)
		return ;
	if (fd >= 0)
	{
		ft_putstr_fd(s, fd);
		write(fd, "\n", 1);
	}
}
