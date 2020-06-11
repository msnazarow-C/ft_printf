/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_utils.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgertrud <msnazarow@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/12 00:14:00 by sgertrud          #+#    #+#             */
/*   Updated: 2020/06/12 00:14:16 by sgertrud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "f_print.h"

void	fl_clear(t_fl *fl)
{
	fl->len = 0;
	fl->s = 1;
	fl->out = 0;
}

void	check_clear(t_check *check)
{
	check->depth = 0;
	check->sum = 0;
}
