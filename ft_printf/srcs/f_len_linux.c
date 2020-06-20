/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_len.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgertrud <msnazarow@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/11 15:42:47 by sgertrud          #+#    #+#             */
/*   Updated: 2020/06/16 23:26:46 by sgertrud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int				check(t_format *f, long double num)
{
	double temp;

	temp = num;
	f->flag[1] = check_zero((unsigned long long*)&temp) ? 1 : f->flag[1];
	f->flag[2] = f->flag[1] ? 0 : f->flag[2];
	if (check_nan((unsigned long long*)&temp) && (f->cv = 'f'))
		return ((f->nan = 1) + 2);
	else if (check_inf((unsigned long long*)&temp) && (f->cv = 'f'))
		return ((f->inf = 1) + 2);
	if (f->cv == 'f')
		return (f_len(f, num));
	if (f->cv == 'e')
		return (e_len(f, num));
	if (f->cv == 'g')
		return (g_len(f, num));
	return (-1);
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
	return (check.sum - i);
}

int				f_len(t_format *f, long double num)
{
	int			sum;
	long double	s;
	int			prec;
	t_fl		fl;

	s = 10;
	fl_clear(&fl);
	prec = f->prec;
	if ((num = f_abs(num)) == 0)
		return (2 + (((f->prec == 0) && (!f->flag[3])) ? -1 : f->prec));
	while (s < num)
		s *= 10;
	while (fl.s * 10 <= num)
		fl.s *= 10;
	while (fl.s >= 1)
		sum = f_print_0(num, &fl, f->prec, f);
	if (f->flag[3] || (f->prec && sum > 0) || (!f->g && f->prec))
		++fl.len;
	while (fl.len < 308 && f->prec--)
		f_print_0(num, &fl, f->prec, f);
	f->prec = prec;
	if ((sum < 0 || (sum == 0 && f->prec)) && f->g && num < 1)
		fl.len -= fl.len > 1 ? 1 : (!--f->prec);
	return (fl.len);
}

int				e_len(t_format *f, long double num)
{
	int		l;
	int		k;

	k = 1;
	l = 1;
	num = f_abs(num);
	if (num >= 10)
		while (num >= 1 && ++l)
			num /= 10;
	else if (num < 1 && num)
		while (num < 1 && ++l)
			num *= 10;
	while ((l /= 10) > 0)
		k++;
	return (max(k, 2) + 2 + f_len(f, num));
}
