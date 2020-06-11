/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgertrud <msnazarow@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/04 22:53:04 by sgertrud          #+#    #+#             */
/*   Updated: 2020/06/12 00:40:08 by sgertrud         ###   ########.fr       */
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
			while ((f->len++ + (base(f->cv) == 16 ? 0 : lenhex(f->cv, f)))
				< (is_float(f->cv) ? f->width - f->flag[1] : f->prec))
				out += write(1, "0", 1);
		else if (!f->flag[0] && f->flag[4])
			while (f->len + (f->flag[1] || f->flag[2]) + lenhex(f->cv, f)
			< f->width && ++f->len)
				out += write(1, "0", 1);
	}
	else if (is_float(f->cv) && f->flag[4])
		while ((f->count + f->len + (base(f->cv) == 16 ? 0 : lenhex(f->cv, f)))
				< f->width - (f->flag[1] || f->flag[2]))
			f->count += write(1, "0", 1);
	return (out);
}

int	putstr(t_format *f, va_list arg)
{
	if (f->mod[0] != 'l')
		return (ft_putstr_fd_f(va_arg(arg, char*), 1, f));
	return (ft_putstr_w(va_arg(arg, wchar_t*), 1, f));
}

int	ft_putstr_w(wchar_t *s, int fd, t_format *f)
{
	int out;
	int temp;

	out = 0;
	if (!s)
	{
		if (f->prec >= 6 || f->prec == -1)
			return (ft_putstr_fd("(null)", 1));
		else
			return (0);
	}
	if (f->prec != -1)
		while (*s && f->prec > 0)
		{
			temp = ft_putchar_fd(*s++, f->prec, fd);
			if (!temp)
				break ;
			out += temp;
			f->prec -= temp;
		}
	else
		while (*s)
			out += ft_putchar_fd(*s++, f->prec, fd);
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
			out += ft_putchar_fd(*s++, 1, 1);
	else
		out = ft_putstr_fd(s, fd);
	return (out);
}

int	print_width(t_format *f, va_list arg)
{
	va_list	copy;

	va_copy(copy, arg);
	if ((f->len = lenprint(f, copy)) >= 0)
	{
		if (f->flag[0] && ((f->count += print_one(f, arg)) ? 1 : 1))
			while (f->count < f->width && ++f->count)
				write(1, " ", 1);
		else
		{
			if (f->prec != -1 && !is_float(f->cv))
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
	}
	va_end(copy);
	return (f->count);
}
