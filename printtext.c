/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printtext.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymushet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 14:28:54 by ymushet           #+#    #+#             */
/*   Updated: 2017/03/10 17:57:14 by ymushet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_print_text(t_conv *flags, void *ar)
{
	if (flags->letter == 3)
	{
		if (flags->output == 's')
			flags->output = 'S';
		if (flags->output == 'c')
			flags->output = 'C';
	}
	if (flags->output == 's')
		return (ft_printstrandflags(flags, (char *)ar));
	if (flags->output == 'c' || flags->output == 'C')
		return (ft_printcharwithflags((char)ar, flags));
	if (flags->output == 'S')
		return (ft_printwstr_withflags((wchar_t *)ar, flags));
	return (-1);
}

int	ft_printstrandflags(t_conv *flags, char *str)
{
	if (str == NULL)
		str = "(null)";
	if (flags->minuszero != 2)
	{
		flags->count += ft_calc_str_width(str, flags);
		flags->count += ft_printstr(str, flags);
	}
	if (flags->minuszero == 2)
	{
		flags->count += ft_printstr(str, flags);
		flags->count += ft_calc_str_width(str, flags);
	}
	return (flags->count);
}

int	ft_printstr(char *str, t_conv *flags)
{
	int len;
	int tmp;

	len = (int)ft_strlen(str);
	if (len == 0)
	{
		ft_putstr("");
		return (0);
	}
	flags->precision != 0 && flags->precision < len
	? len = flags->precision : 0;
	tmp = len;
	while (len > 0)
	{
		ft_putchar(*str);
		str++;
		len--;
	}
	return (tmp);
}

int	ft_printcharwithflags(char c, t_conv *flags)
{
	if (flags->minuszero != 2)
	{
		flags->count += ft_calc_char_width(flags);
		ft_putchar(c);
	}
	else if (flags->minuszero == 2)
	{
		ft_putchar(c);
		flags->count += ft_calc_char_width(flags);
	}
	flags->count++;
	return (flags->count);
}
