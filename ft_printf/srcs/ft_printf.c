/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgertrud <msnazarow@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/03 01:45:38 by sgertrud          #+#    #+#             */
/*   Updated: 2020/06/07 01:01:54 by sgertrud         ###   ########.fr       */
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
				out += print_width(&format, arg);
			}
			if (*s)
			{
				out += ft_putchar_fd(*s, 1);
				s++;
			}
		}
	va_end(arg);
	return (out);
}
