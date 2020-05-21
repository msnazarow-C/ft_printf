/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgertrud <msnazarow@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/18 11:43:23 by sgertrud          #+#    #+#             */
/*   Updated: 2020/05/19 04:54:01 by sgertrud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	if (n == 0 || src == dest)
		return (dest);
	while (--n + 1)
		((unsigned char*)dest)[n] = ((unsigned char*)src)[n];
	return (dest);
}
