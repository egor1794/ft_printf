/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymushet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 14:26:02 by ymushet           #+#    #+#             */
/*   Updated: 2017/03/09 14:27:41 by ymushet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_print_width(int count, t_conv *flags)
{
	char p;

	p = ' ';
	flags->minuszero == 1 ? p = '0' : 0;
	if (flags->output == 'O' || flags->output == 'U' || flags->output == 'X' ||
		flags->output == 'o' || flags->output == 'u' || flags->output == 'x'
		|| flags->output == 'p')
	{
		flags->precision > 0 ? p = ' ' : 0;
		while (count-- > 0)
			write(1, &p, 1);
	}
	if (flags->output == 'd' || flags->output == 'D' || flags->output == 'i')
	{
		flags->precision > 0 ? p = ' ' : 0;
		while (count-- > 0)
			write(1, &p, 1);
	}
	return ;
}

int		ft_put_hash(t_conv *flags)
{
	if (flags->hash == 1)
	{
		if (flags->output == 'x')
		{
			write(1, "0x", 2);
			return (2);
		}
		if (flags->output == 'X')
		{
			write(1, "0X", 2);
			return (2);
		}
		if (flags->output == 'o' || flags->output == 'O')
		{
			write(1, "0", 1);
			return (1);
		}
	}
	return (0);
}
