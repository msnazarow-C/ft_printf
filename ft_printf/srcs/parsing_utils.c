/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgertrud <msnazarow@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/04 21:20:15 by sgertrud          #+#    #+#             */
/*   Updated: 2020/06/13 01:51:06 by sgertrud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		is_flag(char c)
{
	return (c == '+' || c == '-' || c == ' ' || c == '#' || c == '0');
}

int		cv(char **s)
{
	if (**s == 'd' || **s == 'i' || **s == 'u' || **s == 'o' || **s == 'x'
	|| **s == 'X' || **s == 'f' || **s == 'F' || **s == 'e' || **s == 'g'
	|| **s == 'G' || **s == 'a' || **s == 'A' || **s == 'c' || **s == 's' ||
	**s == 'S' || **s == 'p' || **s == 'n' || **s == '%')
		return (*(*s)++);
	return (0);
}

int		ft_abs(int a)
{
	return (a > 0 ? a : -a);
}

void	clear(t_format *format)
{
	format->cv = 0;
	format->flag[0] = 0;
	format->flag[1] = 0;
	format->flag[2] = 0;
	format->flag[3] = 0;
	format->flag[4] = 0;
	format->mod[0] = 0;
	format->mod[1] = 0;
	format->prec = -1;
	format->width = -1;
	format->count = 0;
	format->len = 0;
	format->nil = 0;
	format->inf = 0;
	format->g = 0;
	format->nan = 0;
}
