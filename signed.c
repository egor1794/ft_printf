/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signed.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymushet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 17:58:37 by ymushet           #+#    #+#             */
/*   Updated: 2017/03/10 18:04:54 by ymushet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_print_signed_zero(t_conv *flags)
{
	if (flags->width > 0)
	{
		write(1, " ", 1);
		flags->count++;
	}
	flags->count += ft_calc_signed_num_width(0, flags);
	return (flags->count);
}

int	ft_print_signed_arg(t_conv *flags, intmax_t ar)
{
	flags->minuszero == 1 && flags->precision > 0 ? flags->minuszero = 0 : 0;
	flags->ispoint == 1 && flags->precision == 0 && flags->minuszero == 1 ?
	flags->minuszero = 0 : 0;
	if (ar == 0 && flags->ispoint == 1 && flags->precision == 0)
		return (ft_print_signed_zero(flags));
	if (ar < 0)
	{
		flags->count = ft_print_lesszero(flags, ar);
	}
	else if (ar >= 0)
	{
		flags->count = ft_print_morezero(flags, ar);
	}
	return (flags->count);
}

int	ft_print_lesszero(t_conv *flags, intmax_t ar)
{
	if (flags->minuszero == 2)
	{
		write(1, "-", 1);
		flags->count += ft_get_signed_precision(flags, ar);
		flags->count += ft_digits(ar, ft_get_base(flags));
		ft_putnbr_base((uintmax_t)(-ar), DEC_BASE);
		flags->count += ft_calc_signed_num_width(ar, flags);
	}
	else if (flags->minuszero == 1)
	{
		write(1, "-", 1);
		flags->count += ft_calc_signed_num_width(ar, flags);
		flags->count += ft_get_signed_precision(flags, ar);
		flags->count += ft_digits(ar, ft_get_base(flags));
		ft_putnbr_base((uintmax_t)(-ar), DEC_BASE);
	}
	else if (flags->minuszero == 0)
	{
		flags->count += ft_calc_signed_num_width(ar, flags);
		write(1, "-", 1);
		flags->count += ft_get_signed_precision(flags, ar);
		flags->count += ft_digits(ar, ft_get_base(flags));
		ft_putnbr_base((uintmax_t)(-ar), DEC_BASE);
	}
	return (flags->count);
}

int	ft_print_morezero(t_conv *flags, intmax_t ar)
{
	if (flags->minuszero == 2)
		return (ft_print_morezero_withzerof(flags, ar));
	else if (flags->minuszero == 1)
	{
		flags->plusspace == 1 ? write(1, " ", 1) : 0;
		flags->plusspace == 2 ? write(1, "+", 1) : 0;
		flags->count += ft_calc_signed_num_width(ar, flags);
		flags->count += ft_get_signed_precision(flags, ar);
		flags->count += ft_digits(ar, ft_get_base(flags));
		ft_putnbr_base((uintmax_t)(ar), DEC_BASE);
	}
	else if (flags->minuszero == 0)
	{
		flags->count += ft_calc_signed_num_width(ar, flags);
		flags->plusspace == 1 ? write(1, " ", 1) : 0;
		flags->plusspace == 2 ? write(1, "+", 1) : 0;
		flags->count += ft_get_signed_precision(flags, ar);
		flags->count += ft_digits(ar, ft_get_base(flags));
		ft_putnbr_base((uintmax_t)(ar), DEC_BASE);
	}
	flags->plusspace != 0 ? flags->count++ : 0;
	return (flags->count);
}

int	ft_print_morezero_withzerof(t_conv *flags, intmax_t ar)
{
	if (flags->minuszero == 2)
	{
		if (flags->plusspace == 1)
			write(1, " ", 1);
		else if (flags->plusspace == 2)
			write(1, "+", 1);
		flags->count += ft_get_signed_precision(flags, ar);
		flags->count += ft_digits(ar, ft_get_base(flags));
		ft_putnbr_base((uintmax_t)(ar), DEC_BASE);
		flags->count += ft_calc_signed_num_width(ar, flags);
	}
	flags->plusspace != 0 ? flags->count++ : 0;
	return (flags->count);
}
