/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgertrud <msnazarow@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/20 13:10:20 by sgertrud          #+#    #+#             */
/*   Updated: 2020/05/22 10:53:40 by sgertrud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char *out;

	if (!s)
		return (0);
	if (ft_strlen(s) <= start)
		return (ft_strdup(""));
	len = len > ft_strlen(s) - start ? ft_strlen(s) - start + 1 : len + 1;
	if (!(out = (char*)malloc(len)))
		return (0);
	ft_strlcpy(out, &s[start], len);
	return (out);
}
