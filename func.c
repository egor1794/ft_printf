/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymushet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 15:50:56 by ymushet           #+#    #+#             */
/*   Updated: 2017/03/10 17:38:53 by ymushet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

t_conv	*ft_new_struct(void)
{
	t_conv *flags;

	flags = malloc(sizeof(t_conv));
	flags->letter = 0;
	flags->output = '\0';
	flags->hash = 0;
	flags->minuszero = 0;
	flags->width = 0;
	flags->plusspace = 0;
	flags->precision = 0;
	flags->point = 0;
	flags->count = 0;
	flags->kostyl = 0;
	flags->ispoint = 0;
	return (flags);
}

void	ft_putnbr_base(uintmax_t num, char *base)
{
	if (num >= ft_strlen(base))
	{
		ft_putnbr_base(num / ft_strlen(base), base);
		ft_putnbr_base(num % ft_strlen(base), base);
	}
	else
		ft_putchar(base[num]);
}

int		ft_get_base(t_conv *flags)
{
	if (flags->output == 'd' || flags->output == 'i' || flags->output == 'U' ||
		flags->output == 'u')
	{
		return (10);
	}
	if (flags->output == 'x' || flags->output == 'X')
	{
		return (16);
	}
	if (flags->output == 'o' || flags->output == 'O')
	{
		return (8);
	}
	return (10);
}

char	*ft_get_ubase(t_conv *flags)
{
	if (flags->output == 'x')
		return (HEXX_BASE);
	if (flags->output == 'X')
		return (HEX_BASE);
	if (flags->output == 'o' || flags->output == 'O')
		return (OCT_BASE);
	if (flags->output == 'u' || flags->output == 'U')
		return (DEC_BASE);
	return (DEC_BASE);
}

int		ft_print_arg(t_conv *flags, void *ar)
{
	if (flags->output == 'd' || flags->output == 'i' || flags->output == 'D')
		return (ft_print_signed_arg(flags, ft_smodifier(flags, ar)));
	if (flags->output == 'S' || flags->output == 's' || flags->output == 'C'
		|| flags->output == 'c')
		return (ft_print_text(flags, ar));
	if (flags->output == 'o' || flags->output == 'O' || flags->output == 'u'
		|| flags->output == 'U' || flags->output == 'x' || flags->output == 'X')
		return (ft_print_unsigned_arg(flags, ft_umodifier(flags, ar)));
	if (flags->output == 'p')
		return (ft_print_p(flags, (uintmax_t)ar));
	if (flags->output == '%')
		return (ft_print_percent(flags));
	if (flags->output == '\0')
		return (ft_print_ub(flags));
	if (ft_nonformat(flags->output))
		return (ft_print_nonformat(flags));
	return (-1);
}
