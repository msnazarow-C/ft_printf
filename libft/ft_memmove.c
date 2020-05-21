/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgertrud <msnazarow@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/19 11:22:18 by sgertrud          #+#    #+#             */
/*   Updated: 2020/05/20 07:44:40 by sgertrud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t i;

	i = -1;
	if (n == 0 || src == dest)
		return (dest);
	if (dest > src)
		while (--n + 1)
			((unsigned char*)dest)[n] = ((unsigned char*)src)[n];
	else
		while (++i < n)
			((unsigned char*)dest)[i] = ((unsigned char*)src)[i];
	return (dest);
}
