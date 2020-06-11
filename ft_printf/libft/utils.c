/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgertrud <msnazarow@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/07 07:54:12 by sgertrud          #+#    #+#             */
/*   Updated: 2020/06/11 15:53:00 by sgertrud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		u_digital(char c)
{
	return (c == 'u' || c == 'x' || c == 'X' || c == 'o' || c == 'p');
}

int		digital(char c)
{
	return (c == 'i' || c == 'd' || u_digital(c));
}

int		is_float(char c)
{
	return (c == 'f' || c == 'g' || c == 'e');
}

int		min(int a, int b)
{
	return (a < b ? a : b);
}

double	f_abs(double l)
{
	return (l > 0 ? l : -l);
}
