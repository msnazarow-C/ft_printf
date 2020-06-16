/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_print.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgertrud <msnazarow@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/11 15:45:39 by sgertrud          #+#    #+#             */
/*   Updated: 2020/06/16 12:05:20 by sgertrud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

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
			write(1, "10", 2 + !(++fl->len));
		else
			ft_putchar_fd(i + '0', 1, 1);
		if (d == 0 && f->g && !(f->prec = 0))
			return (fl->s = 0);
		fl->out += fl->s * i;
		(fl->len)++;
	}
	else if (fl->len > 32)
	{
		ft_putchar_fd('0', 1, 1);
		(fl->len)++;
	}
	(fl->s) /= 10;
	return (check.sum == 10 * f->prec + i ? 0 : check.sum - i);
}

int		f_print(t_format *f, long double d)
{
	int		outlen;
	int		sum;
	t_fl	fl;
	double temp;

	temp = d;
	fl_clear(&fl);
	outlen = 0;
	if ((d < 0 || check_zero((unsigned long long*)&temp)) && ++outlen)
		ft_putchar_fd('-', 1, 1);
	else if (f->flag[1] && ++outlen)
		ft_putchar_fd('+', 1, 1);
	else if (f->flag[2] && ++outlen)
		ft_putchar_fd(' ', 1, 1);
	if (f->inf)
		return (outlen + write(1, "inf", 3));
	if (f->nan)
		return (outlen + write(1, "nan", 3));
	outlen += print_zeros(f);
	d = f_abs(d);
	while (fl.s * 10 <= d)
		fl.s *= 10;
	while (fl.s >= 1)
		sum = f_print_0(d, &fl, f->prec, f);
	if ((f->flag[3] || ((f->prec || f->flag[3]) && ((sum != (10 * f->prec) && sum > 0) || !f->g))) && ++fl.len)
		ft_putchar_fd('.', 1, 1);
	while (f->prec--)
		f_print_0(d, &fl, f->prec, f);
	return (outlen + fl.len);
}

int		e_print(t_format *f, long double d)
{
	int		l;
	long double	temp;
	t_fl fl;
	fl_clear(&fl);
	t_check check;
	check_clear(&check);
	temp = f_abs(d);
	l = 0;
	if (!f->nan && !f->inf)
	{
		if (temp >= 10)
			while (temp >= 10 && ++l)
				temp /= 10;
		else if (temp < 1 && temp > 0)
			while (temp < 1 && temp > 0 && --l)
				temp *= 10;
		if (f_print_1(temp, fl, f->prec, &check) == 10)
		{
			l++;
			temp /= 10;
		}
	}
	f->count += f_print(f, (d > 0 ? temp : -temp));
	if (!f->nan && !f->inf && !(f->g && l == 0))
	{
		f->count += ft_putchar_fd('e', 1, 1);
		f->count += ft_putchar_fd(l < 0 ? '-' : '+', 1, 1);
		if (l >= 10 || l <= -10)
		{
			f->count += ft_putnbr_fd_ull(ft_abs(l), 1);
		}
		else
		{
			f->count += ft_putchar_fd('0', 1, 1);
			f->count += ft_putnbr_fd_ull(ft_abs(l), 1);
		}
	}
	return (0);
}
