#include "libftprintf.h"

int ft_print_unsigned_zero(t_conv *flags, uintmax_t ar)
{
	flags->count += ft_calc_unsigned_num_width(ar, flags);
	return (flags->count);
}

int ft_print_unsigned_arg(t_conv* flags, uintmax_t ar)
{
	if (ar == 0 && flags->ispoint == 1 && flags->precision == 0 && ((ft_strchr("Oo", flags->output) && flags->hash != 1) || (ft_strchr("Xx", flags->output)))) //&& flags->output != 'o' && flags->output != 'O') //part of this can be at the print_unsigned_zero func if nor needed
		return (ft_print_unsigned_zero(flags, ar));
	flags->minuszero == 1 && flags->precision != 0 ? flags->minuszero = 0 : 0;
	ar == 0 ? flags->hash = 0 : 0; // ?
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

char *ft_get_ubase(t_conv *flags)
{
	if (flags->output == 'x')
		return(HEx_BASE);
	if (flags->output == 'X')
		return (HEX_BASE);
	if (flags->output == 'o' || flags->output == 'O')
		return (OCT_BASE);
	if (flags->output == 'u' || flags->output == 'U')
		return (DEC_BASE);
    return (DEC_BASE);
}

int ft_print_p(t_conv *flags, uintmax_t ar) //updated
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
