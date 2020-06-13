/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pw.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgertrud <msnazarow@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 03:09:15 by sgertrud          #+#    #+#             */
/*   Updated: 2020/06/12 21:25:29 by sgertrud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

double	iter(long double nb, int power)
{
	int		i;
	long double	out;

	i = 0;
	out = 1;
	if (power > 0)
		while (i++ < power)
		{
			if ((out * nb / nb) != out)
			{
				return (0);
			}
			out = out * nb;
		}
	else
		while (i-- > power)
		{
			if ((out * nb / nb) != out)
			{
				return (0);
			}
			out = out / nb;
		}
	return (out);
}

long double	ft_pw(long double nb, int power)
{
	if (power == 0 || nb == 1)
	{
		return (1);
	}
	if (power == 1 || nb == 0)
	{
		return (nb);
	}
	return (iter(nb, power));
}
