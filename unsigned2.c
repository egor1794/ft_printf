/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsigned2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymushet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 18:32:48 by ymushet           #+#    #+#             */
/*   Updated: 2017/03/10 18:33:03 by ymushet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_print_unsigned_arg_subf(t_conv *flags, uintmax_t ar)
{
	flags->count += ft_put_hash(flags);
	flags->count += ft_get_unsigned_precision(flags, ar);
	flags->count += ft_udigits(ar, ft_get_base(flags));
	ft_putnbr_base(ar, ft_get_ubase(flags));
	flags->count += ft_calc_unsigned_num_width(ar, flags);
	return (flags->count);
}
