#include "libftprintf.h"

int ft_get_signed_precision(t_conv *flags, intmax_t ar)
{
	int res;
	int digits;
	int base;
	int tmp;

	digits = 0;
	base = ft_get_base(flags);
	res = flags->precision;
	ar == 0 ? digits++ : 0;
	if (res > 0)
	{
		while (ar != 0)
		{
			ar /= base;
			digits++;
		}
		if (digits >= res)
			res = 0;
		else
			res = res - digits;
			flags->kostyl = res;
		//digits >= res ? res = 0 : res -= digits;
	}
	tmp = res;
	while (tmp-- > 0)
		write(1, "0", 1);
	return (res);
}

int ft_kostyl(t_conv *flags, intmax_t ar)
{
	int res;
	int digits;
	int base;

	digits = 0;
	base = ft_get_base(flags);
	res = flags->precision;
	ar == 0 ? digits++ : 0;
	if (res > 0)
	{
		while (ar != 0)
		{
			ar /= base;
			digits++;
		}
		if (digits >= res)
			res = 0;
		else
			res = res - digits;
		flags->kostyl = res;
	}
	return (flags->kostyl);
}

int ft_get_unsigned_precision(t_conv *flags, uintmax_t ar)
{
	int res;
	int digits;
	int base;
	int tmp;

	digits = 0;
	base = ft_get_base(flags);
	res = flags->precision;
	ar == 0 ? digits++ : 0;
	if (res > 0)
	{
		while (ar != 0)
		{
			ar /= base;
			digits++;
		}
		if (digits >= res)
			res = 0;
		else
			res = res - digits;
		flags->kostyl = res;
		//digits >= res ? res = 0 : res -= digits;
	}
	tmp = res;
	while (tmp-- > 0)
		write(1, "0", 1);
	return (res);
}

int ft_kostyl2(t_conv *flags, uintmax_t ar)
{
	int res;
	int digits;
	int base;

	digits = 0;
	base = ft_get_base(flags);
	res = flags->precision;
	ar == 0 ? digits++ : 0;
	if (res > 0)
	{
		while (ar != 0)
		{
			ar /= base;
			digits++;
		}
		if (digits >= res)
			res = 0;
		else
			res = res - digits;
		flags->kostyl = res;
	}
	return (flags->kostyl);
}