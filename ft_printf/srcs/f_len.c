/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_len.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgertrud <msnazarow@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/11 15:42:47 by sgertrud          #+#    #+#             */
/*   Updated: 2020/06/13 04:32:39 by sgertrud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

double	chprec(long double d, long double *s)
{
	long double	out;
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

int		f_len(t_format *f,long double num)
{
	int		l;
	int		k;
	long double	s;
	double temp;

	s = 1;
	k = 0;
	temp = num;
	f->flag[1] = check_zero((unsigned long long*)&temp) ? 1 : f->flag[1];
	if (check_nan((unsigned long long*)&temp))
		return ((f->nan = 1) + 2);

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

int		e_len(t_format *f, long double num)
{
	int l;
	int k;
	double temp;

	k = 1;
	l = 1;
	temp = num;
	f->flag[1] = check_zero((unsigned long long*)&temp) ? 1 : f->flag[1];
	if (check_nan((unsigned long long*)&temp))
		return ((f->nan = 1) + 3);
	else if (check_inf((unsigned long long*)&temp))
		return ((f->inf = 1) + 2);
	if (num == 0)
		return (2 + 2 + (((f->prec == 0) && (!f->flag[3])) ? 0 : f->prec + 2));
	if (num < 0)
	{
		f->flag[1] = 1;
		f->flag[2] = 0;
	}
	num = f_abs(num);
	if (num >= 10)
	{
		while ((num /= 10) >= 1)
			l++;
		/*f->prec -= f->g ? l : 0;*/
	}
	else if (num < 1)
	{
		while ((num *= 10) < 1)
			l++;
		/*f->prec += f->g ? l : 0;*/
	}
	while ((l /= 10) > 0)
		k++;
	return (max(k, 2) + 2 + ((f->prec == 0 && !f->flag[3]) ? 0 : f->prec + 2));
}

int		g_len(t_format *f, long double num)
{
	int fl;
	int el;
	double temp;

	temp = num;
	f->flag[1] = check_zero((unsigned long long*)&temp) ? 1 : f->flag[1];
	if (check_nan((unsigned long long*)&temp))
		return ((f->nan = 1) + 3);
	else if (check_inf((unsigned long long*)&temp))
		return ((f->inf = 1) + 2);
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
