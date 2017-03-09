#include "libftprintf.h"
#include <stdio.h>

t_conv *ft_new_struct(void)
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

void ft_putnbr_base(uintmax_t num, char *base)
{
	if (num >= ft_strlen(base))
	{
		ft_putnbr_base(num / ft_strlen(base), base);
		ft_putnbr_base(num % ft_strlen(base), base);
	}
	else
		ft_putchar(base[num]);
}

int ft_print_signed_zero(t_conv *flags)
{
	if (flags->width > 0)
	{
		write(1, " ", 1);
		flags->count++;
	}
	flags->count += ft_calc_signed_num_width(0, flags);
	return (flags->count);
}

int ft_print_signed_arg(t_conv *flags, intmax_t ar)
{
	flags->minuszero == 1 && flags->precision > 0 ? flags->minuszero = 0 : 0; //КОСТЫЛЬ стоявший в парсинге но для чего ?
	if (ar == 0 && flags->ispoint == 1 && flags->precision == 0)
		return (ft_print_signed_zero(flags));
	if (ar < 0) // space are not printed for negative numbers;
	{
		flags->count = ft_print_lesszero(flags, ar);
	}
	else if (ar >= 0)
	{
		flags->count = ft_print_morezero(flags, ar);
	}
	return (flags->count);
}

int ft_print_lesszero(t_conv *flags, intmax_t ar)
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
		write(1 ,"-", 1);
		flags->count += ft_calc_signed_num_width(ar,flags);
		flags->count += ft_get_signed_precision(flags, ar);
		flags->count += ft_digits(ar, ft_get_base(flags));
		ft_putnbr_base((uintmax_t)(-ar), DEC_BASE);
	}
	else if (flags->minuszero == 0)
	{
		flags->count += ft_calc_signed_num_width(ar,flags);
		write(1 ,"-", 1);
		flags->count += ft_get_signed_precision(flags, ar);
		flags->count += ft_digits(ar, ft_get_base(flags));
		ft_putnbr_base((uintmax_t)(-ar), DEC_BASE);
	}
	return (flags->count);
}

int ft_print_morezero(t_conv *flags, intmax_t ar)
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
	else if (flags->minuszero == 1)
	{
		if (flags->plusspace == 1)
			write(1, " ", 1);
		else if (flags->plusspace == 2)
			write(1, "+", 1);
		flags->count += ft_calc_signed_num_width(ar,flags);
		flags->count += ft_get_signed_precision(flags, ar);
		flags->count += ft_digits(ar, ft_get_base(flags));;
		ft_putnbr_base((uintmax_t)(ar), DEC_BASE);
	}
	else if (flags->minuszero == 0)
	{
		flags->count += ft_calc_signed_num_width(ar,flags);
		if (flags->plusspace == 1)
			write(1, " ", 1);
		else if (flags->plusspace == 2)
			write(1, "+", 1);
		flags->count += ft_get_signed_precision(flags, ar);
		flags->count += ft_digits(ar, ft_get_base(flags));;
		ft_putnbr_base((uintmax_t)(ar), DEC_BASE);
	}
	flags->plusspace != 0 ? flags->count++ : 0;
	return (flags->count);
}

int ft_print_arg(t_conv *flags, void *ar) //ADD A NULL CASE;
{
	if (flags->output == 'd' || flags->output == 'i' || flags->output == 'D')
			return (ft_print_signed_arg(flags, ft_smodifier(flags, ar)));
	if (flags->output == 'S' || flags->output == 's' || flags->output == 'C' || flags->output == 'c')
			return (ft_print_text(flags,ar));
	if (flags->output == 'o' || flags->output == 'O' || flags->output == 'u' || flags->output == 'U'
			|| flags->output == 'x' || flags->output == 'X')
		return (ft_print_unsigned_arg(flags, ft_umodifier(flags, ar)));
	if (flags->output == 'p')
		return (ft_print_p(flags, (uintmax_t) ar));
	if (flags->output == '%')
		return (ft_print_percent(flags));
	if (flags->output == '\0')
		return (ft_print_ub(flags));
	if (ft_nonformat(flags->output))
		return (ft_print_nonformat(flags));
	return (-1);
}
