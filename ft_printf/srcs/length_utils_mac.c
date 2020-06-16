/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   length_utils_mac.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgertrud <msnazarow@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/07 07:52:21 by sgertrud          #+#    #+#             */
/*   Updated: 2020/06/17 01:25:44 by sgertrud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	u_len(t_format *f, va_list arg)
{
	if (f->mod[0] == 'l')
		return (f->mod[1] == 'l' ? u_lbase(va_arg(arg,
		unsigned long long), f, base(f->cv)) : u_lbase(
		va_arg(arg, unsigned long), f, base(f->cv)));
	else if (f->mod[0] == 'h')
		return (f->mod[1] == 'h' ? u_lbase((char)va_arg(arg, int), f,
		base(f->cv)) : u_lbase((short)va_arg(arg, int), f, base(f->cv)));
	else
		return (u_lbase(va_arg(arg, unsigned int), f, base(f->cv)));
}

int	s_len(t_format *f, va_list arg)
{
	if (f->mod[0] == 'l')
		return (f->mod[1] == 'l' ? lbase(va_arg(arg, long long), f, base(f->cv))
		: lbase(va_arg(arg, long), f, base(f->cv)));
	else if (f->mod[0] == 'h')
		return (f->mod[1] == 'h' ? lbase((char)va_arg(arg, int), f, base(f->cv))
		: lbase((short)va_arg(arg, int), f, base(f->cv)));
	else
		return (lbase(va_arg(arg, int), f, base(f->cv)));
}

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
	{
		if (f->prec != -1)
		f->prec = min(f->prec, 5);
		return (5);
	}
	while (a /= base)
		len++;
	return (len);
}

int	lenhex(char c, t_format *f)
{
	if (f->prec > f->len && f->cv == 'o')
		return (0);
	if (f->flag[3])
	{
		if (c == 'x' || c == 'X' || c == 'p')
			return (2);
		if (c == 'o')
			return (1);
	}
	return (0);
}
