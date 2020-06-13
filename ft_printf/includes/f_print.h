/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_print.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgertrud <msnazarow@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/11 22:55:26 by sgertrud          #+#    #+#             */
/*   Updated: 2020/06/13 02:45:27 by sgertrud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef F_PRINT_H
# define F_PRINT_H

typedef struct	s_fl
{
	long double	out;
	long double	s;
	int			len;
}				t_fl;

typedef struct	s_check
{
	int	depth;
	int	sum;
}				t_check;

void			check_clear(t_check *check);
void			fl_clear(t_fl *fl);
char			check_zero(unsigned long long *c);
char			check_nan(unsigned long long *c);
char			check_inf(unsigned long long *c);
#endif
