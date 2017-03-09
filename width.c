#include "libftprintf.h"

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

int ft_calc_signed_num_width(intmax_t arg, t_conv *flags)
{
	int res;
	int digits;
	int base;

	res = flags->width;
	base = ft_get_base(flags);
	digits = ft_digits(arg,base);
	arg >= 0 && flags->plusspace == 2 ? digits++ : 0;
	res = flags->width - digits - ft_kostyl(flags,arg);
	flags->plusspace == 1 ? res-- : 0;
	res < 0 ? res = 0 : 0;
	ft_print_width(res, flags);
	return (res);
}

unsigned int ft_digits(intmax_t arg, int base)
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

unsigned int ft_udigits(uintmax_t arg, int base)
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

int ft_calc_str_width(char *str, t_conv *flags) //not tasted and not done yet
{
	int	res;
	int tmp;
	int len;
	char c;

	if (flags->minuszero == 1)
		c = '0';
	else
		c = ' ';
	len = ft_strlen(str);
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

int ft_calc_unsigned_num_width(uintmax_t arg, t_conv *flags)
{
	int	res;
	unsigned int	digits;
	int				base;

	base = ft_get_base(flags);
	digits = ft_udigits(arg,base);
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

/*---------------------------------------------------------------------------------

int ft_calc_str_width(char *str, t_conv *flags)
{
	int	res;

	res = flags->width;
	res = res - ft_strlen(str);
 	flags->
 	if (res > 0)

	return (res > 0 ? res : 0);
}*/

int ft_calc_char_width(t_conv *flags)
{
	int tmp;
	char c;

	c = ' ';
	if (flags->minuszero == 1)
		c = '0';
	flags->width > 0 ? flags->width-- : 0;
	tmp = flags->width;
	while (tmp-- > 0)
		write(1, &c, 1);
	return (flags->width);
}
