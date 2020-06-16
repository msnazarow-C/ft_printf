/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_utils2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgertrud <msnazarow@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/16 23:23:47 by sgertrud          #+#    #+#             */
/*   Updated: 2020/06/16 23:35:21 by sgertrud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "length.h"
#include "libft.h"

int		check_print(t_format *f, long double d)
{
	double	temp;
	int		outlen;

	outlen = 0;
	temp = d;
	if ((d < 0 || check_zero((unsigned long long*)&temp)) && ++outlen)
		ft_putchar_fd('-', 1, 1);
	else if (f->flag[1] && ++outlen)
		ft_putchar_fd('+', 1, 1);
	else if (f->flag[2] && ++outlen)
		ft_putchar_fd(' ', 1, 1);
	return (outlen);
}
