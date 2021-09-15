/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing_utils_mac.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgertrud <msnazarow@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/05 15:38:15 by sgertrud          #+#    #+#             */
/*   Updated: 2020/06/17 02:17:04 by sgertrud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		base(char c)
{
	if (c == 'd' || c == 'i' || c == 'u' || c == 'f')
		return (10);
	if (c == 'x' || c == 'X' || c == 'p')
		return (16);
	if (c == 'o')
		return (8);
	return (-1);
}

int		printhex(char c, t_format *f)
{
	if (f->nil && !f->p)
		return (0);
	if (f->flag[3])
	{
		if (c == 'x' || c == 'p')
			return (ft_putstr_fd("0x", 1));
		if (c == 'X')
			return (ft_putstr_fd("0X", 1));
		if (c == 'o')
			return (ft_putstr_fd("0", 1));
	}
	return (0);
}

char	bigdigit(int a)
{
	if (a >= 0 && a <= 9)
		return (a + '0');
	if (a >= 10 && a <= 16)
		return (a - 10 + 'A');
	return (0);
}

char	smalldigit(int a)
{
	if (a >= 0 && a <= 9)
		return (a + '0');
	if (a >= 10 && a <= 16)
		return (a - 10 + 'a');
	return (0);
}
