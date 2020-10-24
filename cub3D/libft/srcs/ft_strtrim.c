/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgertrud <msnazarow@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/20 14:58:56 by sgertrud          #+#    #+#             */
/*   Updated: 2020/10/24 05:59:56 by sgertrud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	char	check(char const *set, char c)
{
	while (*set)
		if (*set++ == c)
			return (1);
	return (0);
}

char			*ft_strtrim(char const *s1, char const *set)
{
	size_t len;

	if (!s1 || !set)
		return (0);
	while (*s1 && check(set, *s1))
		s1++;
	len = ft_strlen(s1);
	while (check(set, s1[len - 1]))
		len--;
	return (ft_substr(s1, 0, len));
}
