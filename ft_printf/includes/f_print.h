/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_print.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgertrud <msnazarow@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/11 22:55:26 by sgertrud          #+#    #+#             */
/*   Updated: 2020/06/12 00:20:36 by sgertrud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef F_PRINT_H
# define F_PRINT_H

typedef struct	s_fl
{
	double	out;
	double	s;
	int		len;
}				t_fl;

typedef struct	s_check
{
	int	depth;
	int	sum;
}				t_check;

void			check_clear(t_check *check);
void			fl_clear(t_fl *fl);
#endif
