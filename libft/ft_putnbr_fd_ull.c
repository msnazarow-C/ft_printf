/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd_ull.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgertrud <msnazarow@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/19 12:29:19 by sgertrud          #+#    #+#             */
/*   Updated: 2020/06/08 21:48:19 by sgertrud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_fd_ull(unsigned long long nb, int fd)
{
	int i;

	i = 0;
	if (nb / 10 != 0)
	{
		i += ft_putnbr_fd_ull(nb / 10, fd);
		return (i + ft_putchar_fd((nb % 10) + '0', 1, fd));
	}
	else
		return (i + ft_putchar_fd((nb % 10) + '0', 1, fd));
}
