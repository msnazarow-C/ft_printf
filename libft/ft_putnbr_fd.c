/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgertrud <msnazarow@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/19 12:29:19 by sgertrud          #+#    #+#             */
/*   Updated: 2020/05/19 12:54:17 by sgertrud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int nb, int fd)
{
	if (nb < 0)
	{
		ft_putchar_fd('-', fd);
	}
	if (nb / 10 != 0)
	{
		ft_putnbr_fd(nb < 0 ? (nb / 10) * (-1) : nb / 10, fd);
		ft_putchar_fd(nb < 0 ? (nb % 10) * (-1) + '0' : nb % 10 + '0', fd);
	}
	else
		ft_putchar_fd(nb > 0 ? nb + '0' : -nb + '0', fd);
}
