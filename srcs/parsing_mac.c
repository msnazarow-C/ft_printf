/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_mac.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgertrud <msnazarow@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/03 19:46:00 by sgertrud          #+#    #+#             */
/*   Updated: 2020/06/17 02:28:05 by sgertrud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void		flags(char **s, t_format *format)
{
	while (is_flag(**s))
	{
		if (**s == '-')
			format->flag[0] = 1;
		if (**s == '+')
			format->flag[1] = 1;
		if (**s == ' ')
			format->flag[2] = 1;
		if (**s == '#')
			format->flag[3] = 1;
		if (**s == '0')
			format->flag[4] = 1;
		(*s)++;
	}
	if (format->flag[1])
		format->flag[2] = 0;
	if (format->flag[0])
		format->flag[4] = 0;
}

int			pars_int(char **s)
{
	int out;

	out = 0;
	while (**s >= '0' && **s <= '9')
		out = out * 10 + (*(*s)++ - 48);
	return (out);
}

static void	mod_parsing(char **s, t_format *format)
{
	if (**s == 'h' || **s == 'l')
	{
		format->mod[0] = *(*s)++;
		if (**s == format->mod[0])
			format->mod[1] = *(*s)++;
	}
	else if (**s == 'L')
		format->mod[1] = *(*s)++;
}

static void	parsing_add(t_format *f)
{
	if (f->cv == 'u')
		f->flag[1] = 0;
	if (f->cv == 'p')
	{
		f->cv = 'x';
		f->p = 1;
		f->flag[3] = 1;
		f->mod[0] = 'l';
		f->mod[1] = 'l';
	}
	if (f->cv == 's' || f->cv == 'c' || f->cv == '%')
	{
		f->flag[1] = 0;
		f->flag[2] = 0;
		f->flag[3] = 0;
	}
	if (f->cv == 'c')
		f->prec = -1;
	if ((f->cv == 'f' || f->cv == 'e' || f->cv == 'g') && f->prec == -1)
		f->prec = 6;
}

char		*parsing(char *s, t_format *f, va_list arg)
{
	flags(&s, f);
	if (ft_isdigit(*s))
		f->width = pars_int(&s);
	if (*s == '*' && s++)
	{
		f->width = va_arg(arg, int);
		f->flag[0] = f->width >= 0 ? f->flag[0] : 1;
		f->width = ft_abs(f->width);
	}
	if (*s == '.' && s++)
	{
		if (*s == '*' && s++)
		{
			f->prec = va_arg(arg, int);
			f->prec = f->prec >= 0 ? f->prec : -1;
		}
		else if (ft_isdigit(*s))
			f->prec = pars_int(&s);
		else
			f->prec = 0;
	}
	mod_parsing(&s, f);
	f->cv = cv(&s);
	parsing_add(f);
	return (s);
}
