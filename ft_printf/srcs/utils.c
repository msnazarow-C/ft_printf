/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgertrud <msnazarow@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/07 07:54:12 by sgertrud          #+#    #+#             */
/*   Updated: 2020/06/07 07:54:22 by sgertrud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	max(int a, int b)
{
	return (a > b ? a : b);
}

int u_digital(char c)
{
	return (c == 'u' || c == 'x' || c == 'X' || c == 'o' || c == 'p');
}

int	digital(c)
{
	return (c == 'i' || c == 'd' || u_digital(c));
}

int	min(int a, int b)
{
	return (a < b ? a : b);
}
