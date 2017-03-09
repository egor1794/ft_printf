/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymushet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/17 18:09:59 by ymushet           #+#    #+#             */
/*   Updated: 2016/12/21 19:46:06 by ymushet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	char	*ft_nextword(char const *s, char c)
{
	while (*s == c)
		s++;
	return ((char *)s);
}

static	size_t	ft_countwords(char const *s, char c)
{
	size_t	n;
	char	*tmp;

	n = 0;
	tmp = (char *)s;
	while (*tmp && *(tmp = ft_nextword(tmp, c)))
	{
		while (*tmp && *tmp != c)
			tmp++;
		n++;
	}
	return (n);
}

static	char	*ft_mystrdup(char const *s, char c)
{
	char	*tmp;
	size_t	index;
	char	*new;

	index = 0;
	tmp = (char *)s;
	while (*tmp && *tmp != c)
	{
		index++;
		tmp++;
	}
	if ((new = (char*)malloc(index + 1)) == NULL)
		return (NULL);
	new = ft_strncpy(new, tmp - index, index);
	new[index] = '\0';
	return (new);
}

char			**ft_strsplit(char const *s, char c)
{
	char	*tmp;
	char	**ptr;
	size_t	n;
	size_t	i;

	if (s == NULL)
		return (NULL);
	i = 0;
	n = ft_countwords(s, c);
	if (!(ptr = (char**)malloc(sizeof(char*) * (n + 1))))
		return (NULL);
	tmp = (char *)s;
	while (i < n)
	{
		tmp = ft_nextword(tmp, c);
		ptr[i] = ft_mystrdup(tmp, c);
		while (*tmp && *tmp != c)
			tmp++;
		i++;
	}
	ptr[n] = NULL;
	return (ptr);
}
