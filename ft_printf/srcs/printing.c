/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgertrud <msnazarow@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/04 22:53:04 by sgertrud          #+#    #+#             */
/*   Updated: 2020/06/07 07:41:53 by sgertrud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	print_zeros(t_format *f)
{
	int out;

	out = 0;
	if (digital(f->cv))
	{
		if (f->prec != -1)
			while (f->len++ + (base(f->cv) == 16 ? 0 : lenhex(f->cv, f))
				< f->prec)
				out += write(1, "0", 1);
		else if (!f->flag[0] && f->flag[4])
			while (f->len + (f->flag[1] || f->flag[2]) + lenhex(f->cv, f)
			< f->width && ++f->len)
				out += write(1, "0", 1);
	}
	return (out);
}

int	ft_putstr_fd_f(char *s, int fd, t_format *f)
{
	int out;

	out = 0;
	if (!s)
	{
		if (f->prec >= 6 || f->prec == -1)
			return (ft_putstr_fd("(null)", 1));
		else
			return (0);
	}
	if (f->prec != -1)
		while (*s && f->prec--)
			out += ft_putchar_fd(*s++, 1);
	else
		out = ft_putstr_fd(s, fd);
	return (out);
}

int	print_width(t_format *f, va_list arg)
{
	va_list	copy;

	va_copy(copy, arg);
	f->len = lenprint(f, copy);
	if (f->flag[0])
	{
		f->count = print_one(f, arg);
		while (f->count < f->width && ++f->count)
			write(1, " ", 1);
	}
	else
	{
		if (f->prec != -1)
			while (f->count + f->flag[2] + lenhex(f->cv, f) < f->width -
			(f->cv == 's' ? min(f->prec, f->len) : max(f->prec, f->len)) -
			f->flag[1] && ++f->count)
				write(1, " ", 1);
		else if (!f->flag[4])
			while (f->count + f->flag[2] + lenhex(f->cv, f) < f->width -
			f->len - f->flag[1] && ++f->count)
				write(1, " ", 1);
		f->count += print_one(f, arg);
	}
	return (f->count);
}
