/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgertrud <msnazarow@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/19 12:17:35 by sgertrud          #+#    #+#             */
/*   Updated: 2020/06/05 02:25:55 by sgertrud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putchar_fd(int c, int fd)
{
	unsigned char	temp[4];
	int				i;

	if (c > 127)
	{
		i = -1;
		while (c > 0)
		{
			temp[3 - ++i] = c % 64;
			temp[3 - i] += (c / 64 > 0 || temp[3 - i] > 16) * 128;
			c /= 64;
		}
		if (temp[3 - i] > 16)
			i++;
		temp[3 - i] %= 16;
		temp[3 - i] += 128 + (i > 0) * 64 + (i > 1) * 32 + (i > 2) * 16;
		return (write(fd, &temp[3 - i], i + 1));
	}
	else
		return (write(fd, &c, 1));
}
