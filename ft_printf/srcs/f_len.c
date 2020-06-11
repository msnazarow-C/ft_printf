/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_len.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgertrud <msnazarow@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/11 15:42:47 by sgertrud          #+#    #+#             */
/*   Updated: 2020/06/12 00:14:35 by sgertrud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

double	chprec(double d, double *s)
{
	double	out;
	int		i;

	out = 0;
	i = 0;
	while (*s >= d && d && *s)
		*s /= 10;
	while ((i + 1) * *s + out <= d && d && *s)
		i++;
	out += *s * i;
	return (d - out);
}

int		f_len(t_format *f, double num)
{
	int		l;
	int		k;
	double	s;

	s = 1;
	k = 0;
	if ((l = 1) && num == 0)
		return (2 + (((f->prec == 0) && (!f->flag[3])) ? 0 : f->prec));
	if (num < 0 && (f->flag[1] = 1))
		f->flag[2] = 0;
	num = f_abs(num);
	while ((num /= 10) >= 1 && l < 310)
		l++;
	if (l == 310 && !(f->flag[4] = 0))
		return ((f->inf = 1) + 2);
	while (k < f->prec)
	{
		num = chprec(num, &s);
		if (num < ft_pw(10, -f->prec))
			break ;
		++k;
	}
	if (f->g)
		f->prec = min(k, f->prec);
	return (l + (((f->prec == 0) && (!f->flag[3])) ? 0 : f->prec + 1));
}

int		e_len(t_format *f, double num)
{
	int l;
	int k;

	k = 1;
	l = 1;
	if (num == 0)
		return (2 + 2 + (((f->prec == 0) && (!f->flag[3])) ? 0 : f->prec + 2));
	if (num < 0)
	{
		f->flag[1] = 1;
		f->flag[2] = 0;
	}
	num = f_abs(num);
	if (num >= 10)
		while ((num /= 10) >= 1)
			l++;
	else if (num < 1)
		while ((num *= 10) < 1)
			l++;
	while ((l /= 10) > 0)
		k++;
	return (max(k, 2) + 2 + ((f->prec == 0 && !f->flag[3]) ? 0 : f->prec + 2));
}

int		g_len(t_format *f, double num)
{
	int fl;
	int el;

	f->g = 1;
	fl = f_len(f, num);
	el = e_len(f, num);
	if (fl < el)
	{
		f->cv = 'f';
		return (fl);
	}
	else
	{
		f->cv = 'e';
		return (el);
	}
}
