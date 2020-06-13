/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_utils.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgertrud <msnazarow@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/12 00:14:00 by sgertrud          #+#    #+#             */
/*   Updated: 2020/06/13 02:44:01 by sgertrud         ###   ########.fr       */
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

char	check_zero(unsigned long long *c)
{
	return (*c >> 63);
}

char	check_nan(unsigned long long *c)
{
	int a;

	a = (*c >> 52);
	return ((a == 4095 || a == 2047) && (*c & 1 || *c & 2 || *c & 4 || *c & 8 ||
	*c & 16 || *c & 32 || *c & 64 || *c & 128 || *c & 256 || *c & 512 ||
	*c & 1024 || *c & 2048 || *c & 4096 || *c & 8192 || *c & 32768 ||
	*c & 65536 || *c & 131072 || *c & 262144 || *c & 524288 || *c & 1048576 ||
	*c & 2097152 || *c & 4194304 || *c & 8388608 || *c & 16777216 ||
	*c & 33554432 || *c & 67108864 || *c & 134217728 || *c & 268435456 ||
	*c & 536870912 || *c & 1073741824 || *c & 2147483648));
}

char	check_inf(unsigned long long *c)
{
	int a;

	a = (*c >> 52);
	return ((a == 4095 || a == 2047) && !(*c & 1 || *c & 2 || *c & 4 || *c & 8
	|| *c & 16 || *c & 32 || *c & 64 || *c & 128 || *c & 256 || *c & 512 ||
	*c & 1024 || *c & 2048 || *c & 4096 || *c & 8192 || *c & 32768 ||
	*c & 65536 || *c & 131072 || *c & 262144 || *c & 524288 || *c & 1048576 ||
	*c & 2097152 || *c & 4194304 || *c & 8388608 || *c & 16777216 ||
	*c & 33554432 || *c & 67108864 || *c & 134217728 || *c & 268435456 ||
	*c & 536870912 || *c & 1073741824 || *c & 2147483648));
}
