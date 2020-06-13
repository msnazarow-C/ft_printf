/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nbr.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgertrud <msnazarow@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/07 07:37:45 by sgertrud          #+#    #+#             */
/*   Updated: 2020/06/12 21:25:03 by sgertrud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	nbr_f(long double nb, int fd)
{
	if (nb < 0)
	{
		ft_putchar_fd('-', 1, fd);
	}
	if (nb / 10 != 0)
	{
		nbr_f(nb < 0 ? (nb / 10) * (-1) : nb / 10, fd);
		return (ft_putchar_fd(nb < 0 ? ((int)nb % 10) * (-1) + '0' :
		(int)nb % 10 + '0', 1, fd));
	}
	else
		return (ft_putchar_fd(nb > 0 ? nb + '0' : -nb + '0', 1, fd));
}

int	nbrbase(unsigned long long nb, int fd, int base, t_format *f)
{
	int i;

	i = 0;
	if (nb / base != 0)
	{
		i += nbrbase(nb / base, fd, base, f);
		if (f->cv == 'f' && i == f->len - f->prec - 1)
			i += ft_putchar_fd('.', 1, fd);
		return (i + ft_putchar_fd(f->cv == 'X' ?
		bigdigit(nb % base) : smalldigit(nb % base), 1, fd));
	}
	else
		return (i + ft_putchar_fd(f->cv == 'X' ?
		bigdigit(nb % base) : smalldigit(nb % base), 1, fd));
}

int	nbr(long long nb, int fd, t_format *f)
{
	unsigned long long temp;

	temp = (nb < 0 ? -nb : nb);
	f->flag[1] = nb < 0 ? 1 : f->flag[1];
	if ((f->flag[1] && nb >= 0) || nb < 0)
		return (ft_putchar_fd(nb >= 0 ? '+' : '-', 1, fd) + print_zeros(f) +
		(f->prec == 0 && nb == 0 ? 0 : nbrbase(temp, fd, base(f->cv), f)));
	else if (f->flag[2] && !u_digital(f->cv))
		return (ft_putchar_fd(' ', 1, fd) + print_zeros(f) +
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
	temp = nb;
	if (f->flag[1])
		return (ft_putchar_fd('+', 1, fd) + print_zeros(f)) +
		((f->prec == 0 && nb == 0) ? 0 : nbrbase(temp, fd, base(f->cv), f));
	else if (f->flag[2] && !u_digital(f->cv))
		return (ft_putchar_fd(' ', 1, fd) + print_zeros(f) +
		(f->prec == 0 && nb == 0 ? 0 : nbrbase(temp, fd, base(f->cv), f)));
	else
		return (printhex(f->cv, f) + print_zeros(f) + (((f->prec == 0 && nb == 0
		&& f->cv != 'o') || (f->nil && f->cv == 'o' && !f->flag[3] &&
		f->prec == 0)) ? 0 : nbrbase(temp, fd, base(f->cv), f)));
}
