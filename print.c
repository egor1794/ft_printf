#include "libftprintf.h"

void ft_print_width(int count, t_conv *flags) //get norme done // while count could be one function and all if with
//strchr
{
	// ignore ) with given .
	char p;

	p = ' ';
	flags->minuszero == 1 ? p = '0' : 0;
	/*if (flags->output == 's' || flags->output == 'S')
	{
		count = ft_calc_str_width((char *)arg, flags);
		while (count-- > 0)
			write(1, &p ,1);
	}*/
	if (flags->output == 'O' || flags->output == 'U' || flags->output == 'X' ||
		flags->output == 'o' || flags->output == 'u' || flags->output == 'x' || flags->output == 'p')
	{
		flags->precision > 0 ? p = ' ' : 0; // ???
		while (count-- > 0)
			write(1, &p, 1);
	}
	if (flags->output == 'd' || flags->output == 'D' || flags->output == 'i')
	{
		//flags->minuszero == 1 && flags->width > flags->precision ? p = ' ' : 0;
		flags->precision > 0 ? p = ' ' : 0;
		while (count-- > 0)
			write(1, &p, 1);
	}
	/*if (flags->output =='c' || flags->output == '%' || flags->output == 'C') // wrong ?
	{
		count = ft_calc_char_width(flags);
		while (count-- > 0)
			write(1, &p, 1);
	}*/
}

void ft_print_hex(unsigned int arg, t_conv *flags) //may not need here
{
	ft_put_hash(flags); //MAY NOT NEED HERE;
	if (flags->output == 'X')
		ft_putnbr_base(arg, HEX_BASE);
	if (flags->output == 'x')
		ft_putnbr_base(arg, HEx_BASE);
}

void ft_print_octal(unsigned int arg, t_conv *flags) //may not need here
{
	if (arg > 0)
		ft_put_hash(flags); //MAY NOT NEED HERE;
	ft_putnbr_base(arg, OCT_BASE);
}

int ft_put_hash(t_conv *flags)
{
	if (flags->hash == 1)
	{
		if (flags->output == 'x')
		{
			write(1, "0x", 2);
			return (2);
		}
		if (flags->output == 'X')
		{
			write(1, "0X", 2);
			return (2);
		}
		if (flags->output == 'o' || flags->output == 'O')
		{
			write(1, "0", 1);
			return (1);
		}
	}
	return (0);
}