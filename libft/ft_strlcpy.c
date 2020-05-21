/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgertrud <msnazarow@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/20 05:48:52 by sgertrud          #+#    #+#             */
/*   Updated: 2020/05/21 06:10:31 by sgertrud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t n)
{
	size_t len;

	if (!dest || !src)
		return (0);
	len = ft_strlen(src);
	if (!(n == 0 || src == dest))
	{
		while (--n && *src)
			*dest++ = *src++;
		*dest = '\0';
	}
	return (len);
}
