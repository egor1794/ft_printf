/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wchar.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymushet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 14:57:00 by ymushet           #+#    #+#             */
/*   Updated: 2017/03/10 20:28:25 by ymushet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

const char		*unicode_to_utf8(wchar_t c)
{
	static unsigned char	b_static[5];
	unsigned char			*b;

	b = b_static;
	if (c < (1 << 7))
		*b++ = (unsigned char)(c);
	else if (c < (1 << 11))
	{
		*b++ = (unsigned char)((c >> 6) | 0xC0);
		*b++ = (unsigned char)((c & 0x3F) | 0x80);
	}
	else if (c < (1 << 16))
	{
		*b++ = (unsigned char)(((c >> 12)) | 0xE0);
		*b++ = (unsigned char)(((c >> 6) & 0x3F) | 0x80);
		*b++ = (unsigned char)((c & 0x3F) | 0x80);
	}
	else if (c < (1 << 21))
		unicode_to_utf8_subf(c, &b);
	*b = '\0';
	return (const char*)b_static;
}

void			unicode_to_utf8_subf(wchar_t c, unsigned char **b)
{
	**b++ = (unsigned char)(((c >> 18)) | 0xF0);
	**b++ = (unsigned char)(((c >> 12) & 0x3F) | 0x80);
	**b++ = (unsigned char)(((c >> 6) & 0x3F) | 0x80);
	**b++ = (unsigned char)((c & 0x3F) | 0x80);
	return ;
}

int				ft_printwstr(wchar_t *str, t_conv *flags)
{
	int			i;
	int			count;
	wchar_t		*tmp;
	const char	*s;

	i = 0;
	count = 0;
	tmp = str;
	while (*tmp++)
		count++;
	if (count == 0)
	{
		ft_putstr("");
		return (0);
	}
	flags->precision != 0 && flags->precision < count
		? count = flags->precision : 0;
	while (count-- > 0)
	{
		s = unicode_to_utf8(*str);
		ft_putstr(unicode_to_utf8(*str));
		str++;
		i += ft_strlen(s);
	}
	return (i);
}

int				ft_printwstr_withflags(wchar_t *str, t_conv *flags)
{
	if (str == NULL)
		return (ft_printf("%s", NULL));
	if (flags->minuszero != 2)
	{
		flags->count += ft_calc_wstr_width(str, flags);
		flags->count += ft_printwstr(str, flags);
	}
	if (flags->minuszero == 2)
	{
		flags->count += ft_printwstr(str, flags);
		flags->count += ft_calc_wstr_width(str, flags);
	}
	return (flags->count);
}
