#include "libftprintf.h"

int ft_print_text(t_conv *flags, void *ar)  //handle ls and lc case;
{
	if (flags->output == 's' || flags->output == 'S')
		return (ft_printstrandflags(flags, (char *)ar));
	if (flags->output == 'c' || flags->output == 'C')
		return (ft_printcharwithflags((char )ar,flags));
	/*if (flags->output == 'S')
		return (ft_wprintstrwithflags(());*/
    return (-1);
}

int ft_printstrandflags(t_conv *flags, char *str)
{
	if (str == NULL)
		str = "(null)";
	if (flags->minuszero != 2)
	{
		flags->count += ft_calc_str_width(str, flags);
		flags->count += ft_printstr(str, flags);
	}
	if (flags->minuszero == 2)
	{
		flags->count += ft_printstr(str, flags);
		flags->count += ft_calc_str_width(str, flags);
	}
	return (flags->count);
}

int ft_printstr(char *str, t_conv *flags)
{
	int len;
	int tmp;

	len = ft_strlen(str);
	if (len == 0)
	{
		ft_putstr("");
		return (0);
	}
	flags->precision != 0 && flags->precision < len ? len = flags->precision : 0;
	tmp = len;
	while (len > 0)
	{
		ft_putchar(*str);
		str++;
		len--;
	}
	return (tmp);
}

int ft_printcharwithflags(char c, t_conv *flags)
{
	if (flags->minuszero != 2)
	{
		flags->count += ft_calc_char_width(flags);
		ft_putchar(c);
	}
	else if (flags->minuszero == 2)
	{
		ft_putchar(c);
		flags->count += ft_calc_char_width(flags);
	}
	flags->count++;
	return (flags->count);
}
