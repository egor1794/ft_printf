/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsigned.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymushet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 14:47:13 by ymushet           #+#    #+#             */
/*   Updated: 2017/03/10 18:32:08 by ymushet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_print_unsigned_zero(t_conv *flags, uintmax_t ar)
{
	flags->count += ft_calc_unsigned_num_width(ar, flags);
	return (flags->count);
}

int		ft_print_unsigned_arg(t_conv *flags, uintmax_t ar)
{
	if (ar == 0 && flags->ispoint == 1 && flags->precision == 0 &&
		((ft_strchr("Oo", flags->output) && flags->hash != 1)
		|| (ft_strchr("Xx", flags->output))))
		return (ft_print_unsigned_zero(flags, ar));
	flags->minuszero == 1 && flags->precision != 0 ? flags->minuszero = 0 : 0;
	ar == 0 ? flags->hash = 0 : 0;
	flags->ispoint == 1 && flags->precision == 0 && flags->minuszero == 1 ?
	flags->minuszero = 0 : 0;
	if (flags->minuszero == 2)
	{
		return (ft_print_unsigned_arg_subf(flags, ar));
	}
	if (flags->minuszero != 2)
	{
		flags->minuszero == 1 ? flags->count += ft_put_hash(flags) : 0;
		flags->count += ft_calc_unsigned_num_width(ar, flags);
		flags->minuszero != 1 ? flags->count += ft_put_hash(flags) : 0;
		flags->count += ft_get_unsigned_precision(flags, ar);
		flags->count += ft_udigits(ar, ft_get_base(flags));
		ft_putnbr_base(ar, ft_get_ubase(flags));
	}
	return (flags->count);
}

int		ft_print_p(t_conv *flags, uintmax_t ar)
{
	flags->output = 'x';
	flags->hash = 1;
	flags->minuszero == 1 && flags->precision != 0 ? flags->minuszero = 0 : 0;
	if (flags->minuszero == 2)
	{
		flags->count += ft_put_hash(flags);
		flags->count += ft_get_unsigned_precision(flags, ar);
		flags->count += ft_udigits(ar, ft_get_base(flags));
		ft_putnbr_base(ar, ft_get_ubase(flags));
		flags->count += ft_calc_unsigned_num_width(ar, flags);
	}
	if (flags->minuszero != 2)
	{
		flags->minuszero == 1 ? flags->count += ft_put_hash(flags) : 0;
		flags->count += ft_calc_unsigned_num_width(ar, flags);
		flags->minuszero != 1 ? flags->count += ft_put_hash(flags) : 0;
		flags->count += ft_get_unsigned_precision(flags, ar);
		flags->count += ft_udigits(ar, ft_get_base(flags));
		ft_putnbr_base(ar, ft_get_ubase(flags));
	}
	return (flags->count);
}
