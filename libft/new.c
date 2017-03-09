#include "libftprintf.h"

int ft_printf(const char *fmt, ...)
{
	int res;
	va_list args ;
	va_start(args, fmt);

	res = 0;
	while (*fmt != '\0')
	{
		if (*fmt != '%')
			write(1, &(*fmt), 1);
		else
		{
			++fmt;
			void *ar = va_arg(args, void*);
			print_arg((char **)&fmt, ar);
		}
		res++;
		++fmt;
	}
	return (1);
}

t_conv *print_arg(char *fmt, void arg) //write presicion and handle presicion in width; and handle - with all this (some kind of reverse to all of that)
{
	t_conv *flags;

	flags = ft_new_struct();
	flags = ft_read_flags(&fmt, flags);
	if (flags->output == 'd' || flags->output == 'i' || flaga->output == 'D')
		if (flags->minuszero != 2)
		{
			ft_print_width(flags, arg);

		}
}

//presicion test for d,i
//0 - " " +
// " " - combined
//different width
