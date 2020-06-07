/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nbr.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgertrud <msnazarow@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/07 07:37:45 by sgertrud          #+#    #+#             */
/*   Updated: 2020/06/07 07:38:21 by sgertrud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	nbrbase(unsigned long long nb, int fd, int base, t_format *f)
{
	int i;

	i = 0;
	if (nb / base != 0)
	{
		i += nbrbase(nb / base, fd, base, f);
		return (i + ft_putchar_fd(f->cv == 'X' ?
		bigdigit(nb % base) : smalldigit(nb % base), fd));
	}
	else
		return (i + ft_putchar_fd(f->cv == 'X' ?
		bigdigit(nb % base) : smalldigit(nb % base), fd));
}

int	nbr(long long nb, int fd, t_format *f)
{
	unsigned long long temp;

	temp = (nb < 0 ? -nb : nb);
	f->flag[1] = nb < 0 ? 1 : f->flag[1];
	if ((f->flag[1] && nb >= 0) || nb < 0)
		if (f->prec == 0 && nb == 0)
			return (ft_putchar_fd(nb >= 0 ? '+' : '-', fd) + print_zeros(f));
		else
			return (ft_putchar_fd(nb >= 0 ? '+' : '-', fd) + print_zeros(f)
			+ nbrbase(temp, fd, base(f->cv), f));
	else if (f->flag[2] && !u_digital(f->cv))
		return (ft_putchar_fd(' ', fd) + print_zeros(f) +
		(f->prec == 0 && nb == 0 ? 0 : nbrbase(temp, fd, base(f->cv), f)));
	else
		return (printhex(f->cv, f) + print_zeros(f) + (((f->prec == 0 && nb == 0
		&& f->cv != 'o') || (f->nil && f->cv == 'o' && !f->flag[3] &&
		f->prec == 0)) ? 0 : nbrbase(temp, fd, base(f->cv), f)));
}

int	nbr_ull(unsigned long long nb, int fd, t_format *f)
{
	unsigned long long temp;

	if (f->nil && f->cv == 'p')
		return (ft_putstr_fd("(nil)", 1));
	temp = (nb < 0 ? -nb : nb);
	f->flag[1] = nb < 0 ? 1 : f->flag[1];
	if ((f->flag[1] && nb >= 0) || nb < 0)
		if (f->prec == 0 && nb == 0)
			return (ft_putchar_fd(nb >= 0 ? '+' : '-', fd) + print_zeros(f));
		else
			return (ft_putchar_fd(nb >= 0 ? '+' : '-', fd) + print_zeros(f)
			+ nbrbase(temp, fd, base(f->cv), f));
	else if (f->flag[2] && !u_digital(f->cv))
		return (ft_putchar_fd(' ', fd) + print_zeros(f) +
		(f->prec == 0 && nb == 0 ? 0 : nbrbase(temp, fd, base(f->cv), f)));
	else
		return (printhex(f->cv, f) + print_zeros(f) + (((f->prec == 0 && nb == 0
		&& f->cv != 'o') || (f->nil && f->cv == 'o' && !f->flag[3] &&
		f->prec == 0)) ? 0 : nbrbase(temp, fd, base(f->cv), f)));
}
