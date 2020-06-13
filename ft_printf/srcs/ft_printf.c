/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgertrud <msnazarow@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/03 01:45:38 by sgertrud          #+#    #+#             */
/*   Updated: 2020/06/12 21:09:12 by sgertrud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void parse_n(t_format *f, va_list arg,unsigned long long out)
{
	if (f->mod[0] == 'l')
		if(f->mod[1] == 'l')
		*va_arg(arg,unsigned long long*) = (unsigned long long)out;
		else
		*va_arg(arg,unsigned long*) = (unsigned long)out;
	else if (f->mod[0] == 'h')
		if (f->mod[1] == 'h')
		*va_arg(arg,unsigned int*) = (unsigned char)out;
		else
		*va_arg(arg,unsigned int*) = (unsigned short)out;
	else
		*va_arg(arg,unsigned int*) = out;
}

int	ft_printf(const char *s, ...)
{
	t_format	format;
	va_list		arg;
	long long	out;

	out = 0;
	va_start(arg, s);
	if (!s)
		return (ft_putstr_fd("(null)", 1));
	else
		while (*s)
		{
			while (*s == '%')
			{
				clear(&format);
				s = parsing((char*)(s + 1), &format, arg);
				if (format.cv == 'n')
					parse_n(&format, arg, out);
				else
					out += print_width(&format, arg);
			}
			if (*s)
				out += ft_putchar_fd(*s++, 1, 1);
		}
	va_end(arg);
	return (out);
}
