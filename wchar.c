/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wchar.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymushet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 14:57:00 by ymushet           #+#    #+#             */
/*   Updated: 2017/03/09 15:47:37 by ymushet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

// NOTE: *NOT* thread safe, not re-entrant
const char* unicode_to_utf8(wchar_t c)
{
    static unsigned char b_static[5];
    unsigned char* b = b_static;

    if (c<(1<<7))// 7 bit Unicode encoded as plain ascii
    {
        *b++ = (unsigned char)(c);
    }
    else if (c<(1<<11))// 11 bit Unicode encoded in 2 UTF-8 bytes
    {
        *b++ = (unsigned char)((c>>6)|0xC0);
        *b++ = (unsigned char)((c&0x3F)|0x80);
    }
    else if (c<(1<<16))// 16 bit Unicode encoded in 3 UTF-8 bytes
	{
        *b++ = (unsigned char)(((c>>12))|0xE0);
        *b++ =  (unsigned char)(((c>>6)&0x3F)|0x80);
        *b++ =  (unsigned char)((c&0x3F)|0x80);
    }
    else if (c<(1<<21))// 21 bit Unicode encoded in 4 UTF-8 bytes
    {
        *b++ = (unsigned char)(((c>>18))|0xF0);
        *b++ = (unsigned char)(((c>>12)&0x3F)|0x80);
        *b++ = (unsigned char)(((c>>6)&0x3F)|0x80);
        *b++ = (unsigned char)((c&0x3F)|0x80);
    }
    *b = '\0';
    return (const char*)b_static;
}

int ft_printwstr(wchar_t *str, t_conv *flags)
{
	int i;
	int count;
	wchar_t *tmp;
	const char *s;

	i = 0;
	count = 0;
	tmp = str;
	while(*tmp++)
		count++;
	if(count == 0)
	{
		ft_putstr("");
		return (0);
	}
	flags->precision != 0 && flags->precision < count
	? count = flags->precision : 0;
	while(count-- > 0)
	{
		s = unicode_to_utf8(*str);
		ft_putstr(unicode_to_utf8(*str));
		str++;
		i += ft_strlen(s);
	}
	return (i);
}

int ft_calc_wstr_width(wchar_t *str, t_conv *flags)
{
	char c;
	int len;
	int res;
	int tmp;
	wchar_t *wstr;

	wstr = str;
	len = 0;
	if(flags->minuszero == 1)
		c = '0';
	else
		c = ' ';
	while(*wstr)
	{
		wstr++;
		len++;
	}
	res = flags->width;
	flags->precision != 0 && flags->precision < len ? len = flags->precision : 0;
	res = res - len;
	flags->plusspace == 1 ? res-- : 0;
	tmp = res;
	if (res > 0)
		while (tmp-- > 0)
			write(1, &c, 1);
	return (res > 0 ? res : 0);
}

int		ft_printwstr_withflags(wchar_t *str, t_conv *flags)
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

/*int main() {
    int r;
    wchar_t myChar1 = L'Ω';
    r = printf("char is %s\n", unicode_to_utf8(myChar1));
    return 0;
}*/

/*int main(void)
{
	wchar_t *str = L"@@";
 	int a = ft_printf("%ls", str);
	printf("\n%d\n", a);
	int b = printf("%ls", str);
	printf("\n%d", b);
	return (0);
}*/
