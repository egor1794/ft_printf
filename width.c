/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymushet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 18:34:23 by ymushet           #+#    #+#             */
/*   Updated: 2017/03/10 18:44:04 by ymushet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int				ft_calc_signed_num_width(intmax_t arg, t_conv *flags)
{
	int	res;
	int	digits;
	int	base;

	res = flags->width;
	base = ft_get_base(flags);
	digits = ft_digits(arg, base);
	arg >= 0 && flags->plusspace == 2 ? digits++ : 0;
	res = flags->width - digits - ft_kostyl(flags, arg);
	flags->plusspace == 1 ? res-- : 0;
	res < 0 ? res = 0 : 0;
	ft_print_width(res, flags);
	return (res);
}

unsigned int	ft_digits(intmax_t arg, int base)
{
	unsigned int digits;

	digits = 0;
	arg <= 0 ? digits++ : 0;
	while (arg != 0)
	{
		arg /= base;
		digits++;
	}
	return (digits);
}

unsigned int	ft_udigits(uintmax_t arg, int base)
{
	unsigned int digits;

	digits = 0;
	arg == 0 ? digits++ : 0;
	while (arg != 0)
	{
		arg /= base;
		digits++;
	}
	return (digits);
}

int				ft_calc_str_width(char *str, t_conv *flags)
{
	int		res;
	int		tmp;
	int		len;
	char	c;

	if (flags->minuszero == 1)
		c = '0';
	else
		c = ' ';
	len = (int)ft_strlen(str);
	res = flags->width;
	if (flags->precision != 0 && flags->precision < len)
		len = flags->precision;
	res = res - len;
	flags->plusspace == 1 ? res-- : 0;
	tmp = res;
	if (res > 0)
		while (tmp-- > 0)
			write(1, &c, 1);
	return (res > 0 ? res : 0);
}

int				ft_calc_unsigned_num_width(uintmax_t arg, t_conv *flags)
{
	int				res;
	unsigned int	digits;
	int				base;

	base = ft_get_base(flags);
	digits = ft_udigits(arg, base);
	arg == 0 && flags->precision == 0 ? digits-- : 0;
	res = flags->width - digits - ft_kostyl2(flags, arg);
	if (flags->hash == 1 && (flags->output != 'o' && flags->output != 'O'))
		res -= 2;
	else if (flags->hash == 1 && (flags->output == 'o' || flags->output == 'O'))
		res--;
	flags->plusspace == 1 ? res-- : 0;
	res < 0 ? res = 0 : 0;
	ft_print_width(res, flags);
	return (res);
}
