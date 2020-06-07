/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lenprint.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgertrud <msnazarow@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/06 05:58:09 by sgertrud          #+#    #+#             */
/*   Updated: 2020/06/07 03:14:06 by sgertrud         ###   ########.fr       */
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

int	lenprint(t_format *f, va_list arg)
{
	if (f->cv == '%' || f->cv == 'c')
		return (1);
	if (f->cv == 'i' || f->cv == 'd')
		return (s_len(f, arg));
	if (f->cv == 'u' || f->cv == 'x' || f->cv == 'X' ||
	f->cv == 'o' || f->cv == 'p')
		return (u_len(f, arg));
	if (f->cv == 's')
		return (ft_strlen_f(va_arg(arg, char*), f));
	return (-1);
}

int	ft_strlen_f(char *s, t_format *f)
{
	if (!s && f->prec < 6 && f->prec > -1)
		return (0);
	else
		return (ft_strlen(s));
}
