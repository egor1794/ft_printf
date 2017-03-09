#include "libftprintf.h"
#include <stdio.h>

int ft_printf(const char *fmt, ...)
{
	int res;
	va_list args;
	t_conv *flags;

	flags = ft_new_struct();
	res = 0;
	va_start(args, fmt);
	while(*fmt != '\0')
	{
		if(*fmt != '%')
			write(1, &(*fmt), 1);
		else if (*fmt == '%' && *(fmt + 1) == '%')
		{
			write(1, "%", 1);
			fmt++;
		}
		else
		{
			++fmt;
			flags = ft_read_flags((char **)&fmt, flags);
			if (ft_nonformat(flags->output) == 1)
				res += ft_print_arg(flags, NULL) - 1;
			else
				res += ft_print_arg(flags, va_arg(args, void*)) - 1; //iterate string here please. 	ft_printf("{%04.1d}", 0);ft_printf("{%2d}", 0);
			ft_bzero_flags(flags);
		}
		res++;
		*fmt != '\0' ? fmt++ : 0;
	}
	free(flags);
	return (res);
}

int ft_percent_found(char **fmt, t_conv *flags, va_list args)
{
	int res;

	res = 0;
	++(*fmt);
	flags = ft_read_flags(fmt, flags);
	if (ft_nonformat(flags->output) == 1)
		res += ft_print_arg(flags, NULL) - 1;
	else
		res += ft_print_arg(flags, va_arg(args, void*)) - 1; //iterate string here please. 	ft_printf("{%04.1d}", 0);ft_printf("{%2d}", 0);
	ft_bzero_flags(flags);
	return (res);
}

void ft_bzero_flags(t_conv *flags)
{
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
}

/*int  main()
{
	int a = ft_printf("@main_ftprintf: %###-#0000 33...12..#0+0d", 256);
	printf("\n%d\n", a);
	int b = printf("%ll#x", 9223372036854775807);
	printf("\n%d", b);
}*/

/*# 0093 (int)
ft_printf("@moulitest: %.o %.0o", 0, 0);
1. (   15) -->@moulitest: 0 0<--
2. (   13) -->@moulitest:  <--

# 0094 (int)
ft_printf("@moulitest: %5.o %5.0o", 0, 0);
1. (   25) -->@moulitest:      0      0<--
2. (   23) -->@moulitest:            <--


# 0095 (int)
ft_printf("@moulitest: %#.o %#.0o", 0, 0);
1. (   13) -->@moulitest:  <--
2. (   15) -->@moulitest: 0 0<--
 ============================================
 # 0137 (short)
  ft_printf("%hd", 32767);
  1. (    2) -->-1<--
  2. (    5) -->32767<--

# 0139 (short)
  ft_printf("%hd", 32768);
  1. (    1) -->0<--
  2. (    6) -->-32768<--

 # 0175
  ft_printf("@moulitest: %.d %.0d", 0, 0);
  1. (   15) -->@moulitest:    <--
  2. (   13) -->@moulitest:  <--

# 0176 (int)
	ft_printf("@moulitest: %5.d %5.0d", 0, 0);
	1. (   23) -->@moulitest:          <--
	2. (   23) -->@moulitest:            <--*/