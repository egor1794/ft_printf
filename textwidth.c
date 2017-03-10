/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textwidth.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymushet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 18:45:25 by ymushet           #+#    #+#             */
/*   Updated: 2017/03/10 18:49:20 by ymushet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int			ft_calc_char_width(t_conv *flags)
{
	int		tmp;
	char	c;

	c = ' ';
	if (flags->minuszero == 1)
		c = '0';
	flags->width > 0 ? flags->width-- : 0;
	tmp = flags->width;
	while (tmp-- > 0)
		write(1, &c, 1);
	return (flags->width);
}

int			ft_calc_wstr_width(wchar_t *str, t_conv *flags)
{
	char	c;
	int		len;
	int		res;
	int		tmp;
	wchar_t	*wstr;

	wstr = str;
	len = 0;
	c = ' ';
	flags->minuszero == 1 ? c = '0' : 0;
	while (*wstr)
	{
		wstr++;
		len++;
	}
	res = flags->width;
	flags->precision != 0 && flags->precision < len
	? len = flags->precision : 0;
	res = res - len;
	flags->plusspace == 1 ? res-- : 0;
	tmp = res;
	if (res > 0)
		while (tmp-- > 0)
			write(1, &c, 1);
	return (res > 0 ? res : 0);
}
