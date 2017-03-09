/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymushet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/20 17:00:51 by ymushet           #+#    #+#             */
/*   Updated: 2016/12/20 17:09:51 by ymushet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _LIBFT_H
# define _LIBFT_H

# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <stdint.h>


typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

size_t				ft_strlen(const char *str);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_atoi(char *str);
char				*ft_strcat(char *dest, const char *src);
char				*ft_strncat(char *dest, const char *src, size_t n);
size_t				ft_strlcat(char *dest, const char *src, size_t count);
void				ft_strclr(char *s);
void				ft_memdel(void **ap);
int					ft_tolower(int c);
int					ft_toupper(int c);
int					ft_isdigit(int c);
int					ft_isalpha(int c);
int					ft_isalnum(int c);
int					ft_islower (unsigned char c);
int					ft_isupper (unsigned char c);
int					ft_isascii (int c);
int					ft_isprint (int c);
void				*ft_memccpy(void *dest, const void *src, int c, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
char				*ft_strchr(const char *s, int c);
void				ft_strdel(char **as);
void				*ft_memalloc(size_t size);
char				*ft_strnew(size_t size);
void				ft_striter(char *s, void(f)(char *));
void				ft_striteri(char *s, void(*f) (unsigned int, char *));
char				*ft_strmap(char const *s, char (*f) (char));
char				*ft_strmapi(char const *s, char (*f) (unsigned int, char));
int					ft_strequ(char const *s1, const char *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
int					ft_strncmp(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strncpy(char *dst, char *src, size_t n);
char				*ft_strtrim(char const *s);
void				ft_putchar(char c);
void				ft_putnbr(intmax_t nb);
void				ft_putstr(char const *s);
void				ft_putendl(char const *s);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
char				*ft_strdup(const char *str);
char				*ft_strcpy(char *dest, const char *src);
int					ft_isspace(char const c);
size_t				ft_begin(char const *s);
size_t				ft_end(char const *s);
char				*ft_strstr(const char *big, const char *little);
char				*ft_strnstr(const char *big, const char *little,
					size_t len);
char				*ft_itoa(int n);
int					ft_sign(int n);
int					ft_ndigits(int n);
void				ft_swap(char *c1, char *c2);
char				*ft_strrev(char *str);
unsigned int		ft_is_minint(int n);
t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void				ft_lstaddend(t_list **alst, t_list *new);
char				**ft_strsplit(char const *s, char c);
void				*ft_memmove(void *dst, const void *src, size_t len);
char				*ft_strrchr(const char *s, int c);
void				*ft_memset(void *s, int c, size_t n);
char				*ft_strjoin(char const *s1, char const *s2);
#endif
