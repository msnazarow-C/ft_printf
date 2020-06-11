/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgertrud <msnazarow@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/19 12:17:35 by sgertrud          #+#    #+#             */
/*   Updated: 2020/06/11 15:47:29 by sgertrud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putchar_fd(wchar_t c, unsigned int prec, int fd)
{
	unsigned char	temp[4];
	unsigned int	i;

	if (c > 127)
	{
		i = -1;
		while (c > 0)
		{
			temp[3 - ++i] = c % 64;
			temp[3 - i] |= (c / 64 > 0 ||
			temp[3 - i] > (i < 2 ? 32 : 16)) * 128;
			c /= 64;
		}
		if (temp[3 - i] > (i < 2 ? 32 : 16))
			temp[3 - ++i] = 0;
		temp[3 - i] |= 128 | (i > 0) * 64 | (i > 1) * 32 | (i > 2) * 16;
		return ((prec > i + 1) ? write(fd, &temp[3 - i], i + 1) : 0);
	}
	else
		return (write(fd, &c, 1));
}
