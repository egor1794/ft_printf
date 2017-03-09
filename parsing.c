#include "libftprintf.h"
#include <stdio.h>

int ft_nonformat(char c)
{
	if (ft_strchr(CNVS,c))
		return (0);
	return (1);
}

void ft_is_nonletter(char *str, t_conv *flags)
{
	if (*str == '#')
		flags->hash = 1;
	else if (flags->minuszero < 2 && *str == '0')
		flags->minuszero = 1;
	else if (*str == '-')
		flags->minuszero = 2;
	else if (flags->plusspace < 2 && *str == ' ')
		flags->plusspace = 1;
	else if (*str == '+')
		flags->plusspace = 2;
	else if (*str == '.')//&& ft_isdigit(*(str + 1))) //эта штука может не быть диджетом (нужно немного другое условие)
	{
		if (*str == '.' && ft_isdigit(*(str + 1)))
			flags->point = 1;
		flags->ispoint = 1;
	}
	return ;
}

void ft_is_letter_flag(char **str, t_conv *flags)
{
	if (**str == 'z' && flags->letter < 6)
		flags->letter = 6;
	else if (**str == 'j' && flags->letter < 5)
		flags->letter = 5;
	else if (**str == 'l' && *(*str + 1) == 'l' && flags->letter < 4)
	{
		flags->letter = 4;
		(*str)++;
	}
	else if (**str == 'l' && *(*str + 1) != 'l' && flags->letter < 3)
		flags->letter = 3;
	else if (**str == 'h' && *(*str + 1) == 'h' && flags->letter < 1)
	{
		flags->letter = 1;
		(*str)++;
	}
	else if (**str == 'h' && *(*str + 1) != 'h' && flags->letter < 2)
		flags->letter = 2;
	return ;
}

void ft_get_widthorprecision(char **str, t_conv *flags)
{
	if (flags->point == 1)
	{
		if (ft_isdigit(**str))
			flags->precision = ft_atoi(*str);
		flags->point = 0;
	}
	else if (flags->point == 0)
	{
		flags->width = ft_atoi(*str);
	}
	while (**str && ft_isdigit(**str))
	{
		++(*str);
	}
	--(*str);
}

t_conv *ft_read_flags(char **str, t_conv *flags)
{
	while(**str)
	{ //REWRITE FIRST IF IN IT ONE STRING WITH STRCHR
		if (**str == 's' || **str == 'S' || **str == 'p' || **str == 'D' || **str == 'i'
			|| **str == 'o' || **str == 'O' || **str == 'u' || **str == 'U' || **str == 'x' || **str == 'X'
			|| **str == 'c' || **str == 'C' || **str == 'd' || **str == '%' || ft_nonformat(**str))
		{
			//if (ft_nonformat(**str))
				//break ;
			flags->output = **str;
			break ;
		}
		if (!ft_isdigit(**str))
		{
			ft_is_letter_flag(str, flags);
			ft_is_nonletter(*str, flags);
		}
		else if (**str == '0')
			flags->minuszero < 2  && flags->point == 0 ? flags->minuszero = 1 : 0;
		else //if (ft_isdigit(*str))
			ft_get_widthorprecision(str, flags);
		++(*str);
	}
	//t_print_struct(flags);
	return (flags);
}

/*void t_print_struct(t_conv *flags)
{
	printf("CONVERSION: [ %c ] \n", flags->output);
	printf("HASH: [ %d ]\n", flags->hash);
	printf("MINUSZERO: [ %d ]\n", flags->minuszero);
	printf("PLUSSPACE: [ %d ]\n", flags->plusspace);
	printf("WIDTH: [ %d ]\n", flags->width);
	printf("PRECISION: [ %d ]\n", flags->precision);
	printf("LETTER: [ %d ]\n", flags->letter);
 	printf ("POINT: [ %d ]\n", flags->point);
}*/
