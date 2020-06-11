/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_one.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgertrud <msnazarow@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/06 06:01:24 by sgertrud          #+#    #+#             */
/*   Updated: 2020/06/11 15:45:37 by sgertrud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	u_print(t_format *f, va_list arg)
{
	if (f->mod[0] == 'l')
		return (f->mod[1] == 'l' ? nbr_ull(va_arg(arg, unsigned long long), 1,
		f) : nbr_ull(va_arg(arg, unsigned long), 1, f));
	else if (f->mod[0] == 'h')
		return (f->mod[1] == 'h' ? nbr_ull((unsigned char)va_arg(arg,
		int), 1, f) : nbr((unsigned short)va_arg(arg, int),
		1, f));
	else
		return (nbr_ull(va_arg(arg, unsigned int), 1, f));
}

int	s_print(t_format *f, va_list arg)
{
	if (f->mod[0] == 'l')
		return (f->mod[1] == 'l' ? nbr(va_arg(arg, long long), 1,
		f) : nbr(va_arg(arg, long), 1, f));
	else if (f->mod[0] == 'h')
		return (f->mod[1] == 'h' ? nbr((char)va_arg(arg, int), 1,
		f) : nbr((short)va_arg(arg, int), 1, f));
	else
		return (nbr(va_arg(arg, int), 1, f));
}

int	print_one(t_format *f, va_list arg)
{
	if (f->cv == '%')
		return (ft_putchar_fd('%', 1, 1));
	if (f->cv == 's')
		return (putstr(f, arg));
	if (f->cv == 'i' || f->cv == 'd')
		return (s_print(f, arg));
	if (f->cv == 'u' || f->cv == 'x' || f->cv == 'X' ||
	f->cv == 'o' || f->cv == 'p')
		return (u_print(f, arg));
	if (f->cv == 'f')
		return (f_print(f, va_arg(arg, double)));
	if (f->cv == 'e')
		return (e_print(f, va_arg(arg, double)));
	if (f->cv == 'c')
	{
		return (ft_putchar_fd((f->mod[0] == 'l' ? va_arg(arg, wchar_t) :
		(char)va_arg(arg, int)), f->prec, 1));
	}
	return (-1);
}
