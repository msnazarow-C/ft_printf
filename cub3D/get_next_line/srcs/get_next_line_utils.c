/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgertrud <msnazarow@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/29 22:17:24 by sgertrud          #+#    #+#             */
/*   Updated: 2020/10/23 23:46:45 by sgertrud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char		*ft_strjoin_gnl(char const *s1, char const *s2)
{
	char *out;
	char *head;
	char *copy1;

	copy1 = (char*)s1;
	if (!(out = (char*)malloc(ft_strlen_gnl(s1) + ft_strlen_gnl(s2) + 1)))
		return (0);
	head = out;
	while (s1 && *s1++)
		*out++ = *(s1 - 1);
	while (s2 && *s2++)
		*out++ = *(s2 - 1);
	free(copy1);
	*out = 0;
	return (head);
}

size_t		ft_strlen_gnl(const char *s)
{
	size_t len;

	len = 0;
	if (s)
		while (s[len])
			len++;
	return (len);
}

void		*ft_memchr_gnl(const void *s, int c, size_t n)
{
	while (n--)
	{
		if (*(unsigned char*)s++ == (unsigned char)c)
			return ((void*)(s - 1));
	}
	return (0);
}

static void	ft_bzero(void *s, size_t n)
{
	while (n--)
		*(unsigned char*)s++ = 0;
}

char		**ft_realloc(char **data, size_t len, size_t newlen)
{
	char **out;

	if (!(out = (char**)malloc(newlen * sizeof(char*))))
		return (0);
	ft_bzero(out, newlen * sizeof(char*));
	while (data && len--)
		out[len] = data[len];
	free(data);
	return (out);
}
