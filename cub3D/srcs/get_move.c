/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_move.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgertrud <msnazarow@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 23:33:30 by sgertrud          #+#    #+#             */
/*   Updated: 2020/10/23 23:33:31 by sgertrud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include <math.h>
#include "move_player.h"

t_move		get_move(double angle)
{
	t_move	move;
	double	rad_angle;

	rad_angle = angle;
	move.x_shift = sin(rad_angle) * 0.1;
	move.y_shift = cos(rad_angle) * 0.1 * -1;
	move.offset_wall_x = move.x_shift > 0 ? 1 : -1;
	move.offset_wall_y = move.y_shift > 0 ? 1 : -1;
	return (move);
}
