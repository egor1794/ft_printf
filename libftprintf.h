/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymushet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 20:31:16 by ymushet           #+#    #+#             */
/*   Updated: 2017/03/10 20:35:31 by ymushet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _LIBFTPRINTF_H
# define _LIBFTPRINTF_H

# include "libft/libft.h"
# include <stdarg.h>
# include <stdint.h>
# include <wchar.h>
# define HEX_BASE "0123456789ABCDEF"
# define HEXX_BASE "0123456789abcdef"
# define OCT_BASE "01234567"
# define DEC_BASE "0123456789"
# define CNVS "#+- 0%sSpdDioOuUxXcChljz0123456789."
# define CONV "sSpDioOuUxXcCd%"

typedef struct	s_conv
{
	char		output;
	int			letter;
	int			hash;
	int			plusspace;
	int			minuszero;
	int			point;
	int			width;
	int			precision;
	int			count;
	int			kostyl;
	int			ispoint;
}				t_conv;

int				ft_printf(const char *fmt, ...);
t_conv			*ft_new_struct(void);
int				ft_print_arg(t_conv *flags, void *ar);
int				ft_nonformat(char c);
void			ft_is_nonletter(char *str, t_conv *flags);
void			ft_is_letter_flag(char **str, t_conv *flags);
void			ft_get_widthorprecision(char **str, t_conv *flags);
t_conv			*ft_read_flags(char **str, t_conv *flags);
intmax_t		ft_smodifier(t_conv *flags, void *arg);
int				ft_get_signed_precision(t_conv *flags, intmax_t ar);
int				ft_get_base(t_conv *flags);
int				ft_calc_signed_num_width(intmax_t arg, t_conv *flags);
void			ft_print_width(int count, t_conv *flags);
unsigned int	ft_digits(intmax_t arg, int base);
int				ft_kostyl(t_conv *flags, intmax_t ar);
int				ft_print_lesszero(t_conv *flags, intmax_t ar);
int				ft_print_morezero(t_conv *flags, intmax_t ar);
int				ft_print_text(t_conv *flags, void *ar);
int				ft_printstrandflags(t_conv *flags, char *str);
int				ft_calc_str_width(char *str, t_conv *flags);
int				ft_printstr(char *str, t_conv *flags);
int				ft_printcharwithflags(char c, t_conv *flags);
void			ft_putnbr_base(uintmax_t num, char *base);
int				ft_calc_char_width(t_conv *flags);
int				ft_get_unsigned_precision(t_conv *flags, uintmax_t ar);
int				ft_kostyl2(t_conv *flags, uintmax_t ar);
unsigned int	ft_udigits(uintmax_t arg, int base);
int				ft_put_hash(t_conv *flags);
int				ft_calc_unsigned_num_width(uintmax_t arg, t_conv *flags);
int				ft_print_unsigned_arg(t_conv *flags, uintmax_t ar);
uintmax_t		ft_umodifier(t_conv *flags, void *arg);
char			*ft_get_ubase(t_conv *flags);
int				ft_print_p(t_conv *flags, uintmax_t ar);
int				ft_print_ub(t_conv *flags);
int				ft_print_percent(t_conv *flags);
void			ft_bzero_flags(t_conv *flags);
int				ft_print_signed_zero(t_conv *flags);
int				ft_print_nonformat(t_conv *flags);
void			ft_modifier_bigletter(t_conv *flags);
int				ft_print_signed_arg(t_conv *flags, intmax_t ar);
int				ft_print_morezero_withzerof(t_conv *flags, intmax_t ar);
int				ft_percent_found(char **fmt, t_conv *flags, va_list args);
int				ft_printwstr_withflags(wchar_t *str, t_conv *flags);
int				ft_calc_wstr_width(wchar_t *str, t_conv *flags);
int				ft_printwstr(wchar_t *str, t_conv *flags);
const char		*unicode_to_utf8(wchar_t c);
int				ft_print_unsigned_arg_subf(t_conv *flags, uintmax_t ar);
void			unicode_to_utf8_subf(wchar_t c, unsigned char **b);
#endif
