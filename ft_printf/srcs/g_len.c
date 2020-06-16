/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g_len.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgertrud <msnazarow@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/16 23:25:55 by sgertrud          #+#    #+#             */
/*   Updated: 2020/06/16 23:32:46 by sgertrud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "length.h"
#include "libft.h"

static void	g_len_o(long double num, t_format *f, int prec_temp)
{
	int			l;
	long double	lim;
	int			i;

	l = 0;
	lim = 9;
	i = 0;
	while (++i <= prec_temp)
		lim += ft_pw(10, -i) * (i == prec_temp ? 5 : 9);
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
}

int			g_len(t_format *f, long double num)
{
	int		fl;
	int		el;
	int		prec_temp;

	f->g = 1;
	num = f_abs(num);
	if (num == 0 && (f->cv = 'f'))
		return (f->flag[3] ? --f->prec + 2 : (f->prec = 0) + 1);
	prec_temp = f->prec ? f->prec : 1;
	f->prec = f->prec > 1 ? f->prec - 1 : 0;
	el = e_len(f, num);
	f->cv = 'f';
	g_len_o(num, f, prec_temp);
	fl = f->prec >= 0 ? f_len(f, num) : 0;
	if (f->cv == 'e')
		f->prec = max(prec_temp - 1, 0);
	return (f->cv == 'e' ? el : fl);
}
