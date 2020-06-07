/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lenght_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgertrud <msnazarow@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/07 07:52:21 by sgertrud          #+#    #+#             */
/*   Updated: 2020/06/07 07:56:15 by sgertrud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	lbase(long long a, t_format *f, int base)
{
	int len;

	len = f->prec == 0 && a == 0 ? 0 : 1;
	f->flag[1] = a < 0 && !u_digital(f->cv) ? 1 : f->flag[1];
	if (f->flag[1])
		f->flag[2] = 0;
	while (a /= base)
		len++;
	return (len);
}

int	u_lbase(unsigned long long a, t_format *f, int base)
{
	int len;

	f->nil = (a == 0);
	len = (f->prec == 0 && a == 0 && !(f->flag[3] && f->cv == 'o')) ? 0 : 1;
	if (f->cv == 'p' && f->nil)
		return (5);
	f->flag[1] = a < 0 && !u_digital(f->cv) ? 1 : f->flag[1];
	while (a /= base)
		len++;
	return (len);
}

int	lenhex(char c, t_format *f)
{
	if (f->prec > f->len && f->cv == 'o')
		return (0);
	if (f->flag[3] && !f->nil)
	{
		if (c == 'x' || c == 'X' || c == 'p')
			return (2);
		if (c == 'o')
			return (1);
	}
	return (0);
}
