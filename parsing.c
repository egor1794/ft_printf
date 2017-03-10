/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymushet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 17:39:58 by ymushet           #+#    #+#             */
/*   Updated: 2017/03/10 17:55:34 by ymushet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_nonformat(char c)
{
	if (ft_strchr(CNVS, c))
		return (0);
	return (1);
}

void	ft_is_nonletter(char *str, t_conv *flags)
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
	else if (*str == '.')
	{
		if (*str == '.' && ft_isdigit(*(str + 1)))
			flags->point = 1;
		if (*str == '.' && !ft_isdigit(*(str + 1)))
			flags->precision = 0;
		flags->ispoint = 1;
	}
	return ;
}

void	ft_is_letter_flag(char **str, t_conv *flags)
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

void	ft_get_widthorprecision(char **str, t_conv *flags)
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

t_conv	*ft_read_flags(char **str, t_conv *flags)
{
	while (**str)
	{
		if (ft_strchr(CONV, **str) != NULL || ft_nonformat(**str))
		{
			flags->output = **str;
			break ;
		}
		if (!ft_isdigit(**str))
		{
			ft_is_letter_flag(str, flags);
			ft_is_nonletter(*str, flags);
		}
		else if (**str == '0')
		{
			flags->minuszero < 2 && flags->point == 0
			? flags->minuszero = 1 : 0;
		}
		else
			ft_get_widthorprecision(str, flags);
		++(*str);
	}
	return (flags);
}
