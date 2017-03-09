#ifndef _LIBFTPRINTF_H
# define _LIBFTPRINTF_H

# include "libft/libft.h"
# include <stdarg.h>
# include <stdint.h>
# define HEX_BASE "0123456789ABCDEF"
# define HEx_BASE "0123456789abcdef"
# define OCT_BASE "01234567"
# define BIN_BASE "01"
# define DEC_BASE "0123456789"
# define CNVS "#+- 0%sSpdDioOuUxXcChljz0123456789."

typedef struct	s_conv
{
	char output;
	int letter; // z = 1 , j = 2 , l = 3 ll = 33 h = 4 hh = 44
	int hash;
	int plusspace;
	int minuszero; //plus is 2 space is 1;
	int point;
	int width;
	int precision; //number after point
	int count;
	int kostyl;
	int ispoint;
}				t_conv;

int ft_printf(const char *fmt, ...);
t_conv *ft_new_struct(void);
int ft_print_arg(t_conv *flags, void *ar);
int ft_nonformat(char c); //validation is not done yet (for no conversion case and %% not coded properly yet
void ft_is_nonletter(char *str, t_conv *flags);
void ft_is_letter_flag(char **str, t_conv *flags);
void ft_get_widthorprecision(char **str, t_conv *flags);
t_conv *ft_read_flags(char **str, t_conv *flags);
intmax_t ft_smodifier(t_conv *flags, void *arg);
int ft_get_signed_precision(t_conv *flags, intmax_t ar);
int	ft_get_base(t_conv *flags);
int ft_calc_signed_num_width(intmax_t arg, t_conv *flags);
void ft_print_width(int count, t_conv *flags);
unsigned int ft_digits(intmax_t arg, int base);
int ft_kostyl(t_conv *flags, intmax_t ar);//get norme done // while count could be one function and all ifwith
int ft_print_lesszero(t_conv *flags, intmax_t ar);
int ft_print_morezero(t_conv *flags, intmax_t ar);
int ft_print_text(t_conv *flags, void *ar);
int ft_printstrandflags(t_conv *flags, char *str);
int ft_calc_str_width(char *str, t_conv *flags);
int ft_printstr(char *str, t_conv *flags);
int ft_printcharwithflags(char c, t_conv *flags);
void ft_putnbr_base(uintmax_t num, char *base);
int ft_calc_char_width(t_conv *flags);
int ft_get_unsigned_precision(t_conv *flags, uintmax_t ar);
int ft_kostyl2(t_conv *flags, uintmax_t ar);
unsigned int ft_udigits(uintmax_t arg, int base);
int ft_put_hash(t_conv *flags);
int ft_calc_unsigned_num_width(uintmax_t arg, t_conv *flags);
int ft_print_unsigned_arg(t_conv* flags, uintmax_t ar);
uintmax_t ft_umodifier(t_conv *flags, void *arg); //not done yet
char *ft_get_ubase(t_conv *flags);
int ft_print_p(t_conv *flags, uintmax_t ar);
int ft_print_ub(t_conv *flags);
int ft_print_percent(t_conv *flags);
void ft_bzero_flags(t_conv *flags);
int ft_print_signed_zero(t_conv *flags);
int ft_print_nonformat(t_conv *flags);
#endif
//0 игнорируется если есть точность
