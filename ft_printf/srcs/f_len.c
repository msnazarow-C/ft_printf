/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_len.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgertrud <msnazarow@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/11 15:42:47 by sgertrud          #+#    #+#             */
/*   Updated: 2020/06/16 18:08:58 by sgertrud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

long double	chprec(long double d, long double *s)
{
	long double	out;
	int		i;

	out = 0;
	i = 0;
	/*while (*s >= d && d && *s)*/
		*s /= 10;
	while ((i + 1) * *s + out <= d && d && *s)
		i++;
	out += *s * i;
	return (d - out);
}

static int		f_print_1(long double d, t_fl fl, int prec, t_check *check)
{
	int i;
	int l;

	i = 0;
	if (check->depth > prec + 1 || fl.out == d)
		return (0);
	while ((i + 1) * fl.s + fl.out <= d)
		i++;
	fl.out += fl.s * i;
	fl.s /= 10;
	if (fl.s >= 1)
		prec++;
	check->depth++;
	if ((l = f_print_1(d, fl, prec, check)) > 9
	|| (l >= 5 && prec < check->depth))
		i++;
	check->depth--;
	check->sum += i;
	if (prec < check->depth || i == 10)
		check->sum -= i;
	return (i);
}

static int		f_print_0(long double d, t_fl *fl, int prec, t_format *f)
{
	int		i;
	t_check	check;

	check_clear(&check);
	i = 0;
	if (fl->len <= 32 || fl->out == 0)
	{
		i = f_print_1(d, *fl, prec, &check);
		if (check.sum == 0 && f->g && d != 0 && fl->s < 1 && !(f->flag[3]))
			return (0);
		if (i == 10)
			++fl->len;
		if (d == 0 && f->g && !(f->prec = 0))
			return (fl->s = 0);
		fl->out += fl->s * i;
		(fl->len)++;
	}
	else if (fl->len > 32)
	{
		(fl->len)++;
	}
	(fl->s) /= 10;
	return (check.sum == 10 * f->prec + i /*- 1*/? 0 : check.sum - i);
}

int		f_len(t_format *f,long double num)
{
	int		l;
	int 	sum;
	int		k;
	long double	s;
	double temp;
	int prec;
	t_fl fl;
	fl_clear(&fl);
	t_check check;
	check_clear(&check);
	s = 10;
	k = 0;
	temp = num;
	prec = f->prec;
	f->flag[1] = check_zero((unsigned long long*)&temp) ? 1 : f->flag[1];
	if (check_nan((unsigned long long*)&temp))
		return ((f->nan = 1) + 2);
	else if (check_inf((unsigned long long*)&temp))
		return ((f->inf = 1) + 2);
	if ((l = 0) && num == 0)
		return (2 + (((f->prec == 0) && (!f->flag[3])) ? 0 : f->prec));
	if (num < 0 && (f->flag[1] = 1))
		f->flag[2] = 0;
	num = f_abs(num);
	while (s < num)
		s *= 10;
	while (fl.s * 10 <= num)
		fl.s *= 10;
	while (fl.s >= 1)
		sum = f_print_0(num, &fl, f->prec, f);
	if ((f->flag[3] || ((f->prec || f->flag[3]) && ((sum != (10 * f->prec) && sum > 0) || !f->g))))
		++fl.len;
	while (fl.len < 308 && f->prec--)
		f_print_0(num, &fl, f->prec, f);
	f->prec = prec;
/*	if (f_print_1(num, fl, f->prec, &check) == 10)
		l++;
	while (num >= 1 && l < 310 && ++l)
		num /= 10;
	while (k <= f->prec && (num > ft_pw(10,-(f->prec + l))) )
	{
		num = chprec(num, &s);
		num *= 10;
		check_clear(&check);
		if (f_print_1(num, fl, f->prec, &check) == 10 || !check.sum)
		{
			f->prec -= 1;
			break;
		}
		++k;
	}*/
	/*	num = chprec(num, &s);*/
/*	if (l == 310 && !(f->flag[4] = 0))
		return ((f->inf = 1) + 2);*/
/*	while (k < f->prec && (num > ft_pw(10,-(f->prec + l)) || ((f_abs(num - ft_pw(10, -(f->prec + l)))) < ft_pw(10, -(f->prec + l + 1)))) && ++k)
		num = chprec(num, &s);*/
/*	if (f->g)
		f->prec = min(k, f->prec);*/
	return (fl.len);
	/*return (l + (((f->prec == 0) && (!f->flag[3])) ? 0 : f->prec + 1));*/
}

int		e_len(t_format *f, long double num)
{
	int l;
	int k;
	double temp;
	t_fl fl;
	fl_clear(&fl);
	t_check check;
	check_clear(&check);

	k = 1;
	l = 1;
	temp = num;
	f->flag[1] = check_zero((unsigned long long*)&temp) ? 1 : f->flag[1];
	f->flag[2] = f->flag[1] ? 0 : f->flag[2];
	if (check_nan((unsigned long long*)&temp))
		return ((f->nan = 1) + 2);
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
	/*if (f_print_1(num, fl, f->prec, &check) == 10)
		l++;*/
	if (num >= 10)
	{
		while (num >= 1 && ++l)
			num /= 10;
		/*f->prec -= f->g ? l : 0;*/
	}
	else if (num < 1)
	{
		while (num < 1 && ++l)
			num *= 10;
		/*f->prec += f->g ? l : 0;*/
	}
	while ((l /= 10) > 0)
		k++;
	return (max(k, 2) + 2 + f_len(f, num)/* - (num >= 1 ? 0 : 1)*/ /*+ ((f->prec == 0 && !f->flag[3]) ? 1 : f->prec + 2)*/);
}

int		g_len(t_format *f, long double num)
{
	int fl;
	int el;
	int l;
	int i;
	long double lim;
	double temp;
	int prec_temp;

	l = 0;
	temp = num;
	num = f_abs(num);
	f->flag[1] = check_zero((unsigned long long*)&temp) ? 1 : f->flag[1];
	if (check_nan((unsigned long long*)&temp) && (f->cv = 'f'))
		return ((f->nan = 1) + 2);
	else if (check_inf((unsigned long long*)&temp) && (f->cv = 'f'))
		return ((f->inf = 1) + 2);
	if (num == 0)
	{
		f->cv = 'f';
		return (f->flag[3] ? --f->prec + 1 : (f->prec = 0) + 1);
	}
	prec_temp = f->prec ? f->prec : 1;
	f->prec = f->prec > 1 ? f->prec - 1 : 0;
	el = e_len(f, num);
	f->g = 1;
	f->cv = 'f';
	lim = 9;
	i = 0;
	while (++i < prec_temp)
		lim += 9 * ft_pw(10, -i);
	lim += 5 * ft_pw(10, -i);
	if (num >= lim)
	{
		while (num >= lim / 10 && ++l)
			num /= 10;
		if (l > prec_temp)
			f->cv = 'e';
		f->prec = prec_temp - l;
	}
	else if (num < 1)
	{
		while (num < 1 && ++l)
			num *= 10;
		if (l > 4)
			f->cv = 'e';
		f->prec = prec_temp - 1 + l;
	}
	num = temp;
	fl = f->prec >= 0 ? f_len(f, num) : 0;
	if (f->cv == 'e')
		f->prec = max(prec_temp - 1, 0);
	return (f->cv == 'e' ? el : fl);
	/*if (fl < el && fl)
	{
		f->cv = 'f';
		return (fl);
	}
	else
	{
		f->cv = 'e';
		return (el);
	}*/
}
