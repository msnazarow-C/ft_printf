/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgertrud <msnazarow@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/03 01:45:38 by sgertrud          #+#    #+#             */
/*   Updated: 2020/06/11 21:05:23 by sgertrud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_printf(const char *s, ...)
{
	t_format	format;
	va_list		arg;
	int			out;

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
					*(va_arg(arg, int*)) = out;
				else
					out += print_width(&format, arg);
			}
			if (*s)
				out += ft_putchar_fd(*s++, 1, 1);
		}
	va_end(arg);
	return (out);
}
