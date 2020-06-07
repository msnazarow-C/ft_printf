/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgertrud <msnazarow@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/19 05:00:23 by sgertrud          #+#    #+#             */
/*   Updated: 2020/05/20 15:43:42 by sgertrud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t len;

	len = 0;
	while (dest[len])
		len++;
	dest = dest + len;
	if (len > size)
		len = size;
	while (*src++)
	{
		if (len + 1 < size)
			*dest++ = *(src - 1);
		else if (len + 1 == size)
			*dest = 0;
		len++;
	}
	if (len < size)
		*dest = 0;
	return (len);
}
