/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgertrud <msnazarow@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 04:35:13 by sgertrud          #+#    #+#             */
/*   Updated: 2020/10/24 05:33:15 by sgertrud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MOVE_PLAYER_H
# define MOVE_PLAYER_H
# include "cub3d.h"

typedef struct	s_move
{
	double	x_shift;
	double	y_shift;
	double	offset_wall_x;
	double	offset_wall_y;
}				t_move;
t_move			get_move(double angle);
void			move_player(double angle, t_data *data);

#endif
