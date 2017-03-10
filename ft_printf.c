/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymushet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 17:32:03 by ymushet           #+#    #+#             */
/*   Updated: 2017/03/10 17:33:42 by ymushet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_printf(const char *fmt, ...)
{
	int		res;
	va_list	args;
	t_conv	*flags;

	flags = ft_new_struct();
	res = 0;
	va_start(args, fmt);
	while (*fmt != '\0')
	{
		if (*fmt != '%')
			write(1, &(*fmt), 1);
		else if (*fmt == '%' && *(fmt + 1) == '%')
		{
			write(1, "%", 1);
			fmt++;
		}
		else
			res += ft_percent_found((char **)&fmt, flags, args);
		res++;
		*fmt != '\0' ? fmt++ : 0;
	}
	free(flags);
	return (res);
}

int		ft_percent_found(char **fmt, t_conv *flags, va_list args)
{
	int res;

	res = 0;
	++(*fmt);
	flags = ft_read_flags(fmt, flags);
	if (ft_nonformat(flags->output) == 1)
		res += ft_print_arg(flags, NULL) - 1;
	else
		res += ft_print_arg(flags, va_arg(args, void*)) - 1;
	ft_bzero_flags(flags);
	return (res);
}

void	ft_bzero_flags(t_conv *flags)
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
