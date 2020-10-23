/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgertrud <msnazarow@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/02 15:41:22 by frdescam          #+#    #+#             */
/*   Updated: 2020/10/23 22:16:09 by sgertrud         ###   ########.fr       */
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
