#include "libftprintf.h"

int ft_print_ub(t_conv *flags)
{
	char p;
	int tmp;

	tmp = flags->width - 1;
	p = ' ';
	if (flags->minuszero == 2)
		p = '0';
	while (tmp-- > 0)
		write(1, &p, 1);
	return (flags->width > 1 ? flags->width - 1 : 0);
}

int ft_print_percent(t_conv *flags)
{
	char p;
	int tmp;

	tmp = flags->width - 1;
	p = ' ';
	if (flags->minuszero == 1)
		p = '0';
	if (flags->minuszero != 2)
	{
		while (tmp-- > 0)
			write(1, &p, 1);
		write(1, "%", 1);
	}
	if (flags->minuszero == 2)
	{
		write(1, "%", 1);
		while (tmp-- > 0)
			write(1, &p, 1);
	}
	return (flags->width > 1 ? flags->width-- : 1);
}

int ft_print_nonformat(t_conv *flags)
{
	write(1, &flags->output, 1);
	return (1);
}