/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgertrud <msnazarow@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/20 15:52:51 by sgertrud          #+#    #+#             */
/*   Updated: 2020/05/20 16:05:26 by sgertrud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*out;
	unsigned int	i;

	i = -1;
	if (!s || !f || !(out = (char*)malloc(ft_strlen(s) + 1)))
		return (0);
	while (s[++i])
		out[i] = f(i, s[i]);
	out[i] = 0;
	return (out);
}
