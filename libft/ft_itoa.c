/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgertrud <msnazarow@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/19 11:01:08 by sgertrud          #+#    #+#             */
/*   Updated: 2020/06/08 21:49:14 by sgertrud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	memneed(int value, int base)
{
	int len;
	int temp;

	temp = value < 0 ? value : -value;
	len = (value < 0 && base == 10) ? 3 : 2;
	while (temp <= -base)
	{
		temp /= base;
		len++;
	}
	return (len);
}

static char	*ft_itoa_base(int value, int base)
{
	char	*out;
	int		len;

	len = memneed(value, base);
	if (!(out = (char *)malloc(len * sizeof(char))))
		return (0);
	if (value == 0)
		out[0] = '0';
	if (base == 10 && value < 0)
		out[0] = '-';
	out[len - 1] = '\0';
	while (value != 0)
	{
		out[len-- - 2] = bigdigit(ft_abs(value % base));
		value /= base;
	}
	return (out);
}

char		*ft_itoa(int n)
{
	return (ft_itoa_base(n, 10));
}
