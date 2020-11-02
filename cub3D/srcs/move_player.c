/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgertrud <msnazarow@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 00:08:10 by sgertrud          #+#    #+#             */
/*   Updated: 2020/10/26 23:20:12 by sgertrud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "cub3d.h"
#include "move_player.h"

static	int	is_move_possible(t_player *player, char **map, double y_shift,
		double x_shift)
{
	double	new_pos_y;
	double	new_pos_x;
	int		check_y;
	int		check_x;

	check_x = x_shift > 0 ? 1 : -1;
	check_y = y_shift > 0 ? 1 : -1;
	if (y_shift)
	{
		new_pos_y = player->pos_y + y_shift;
		if (map[(int)(new_pos_y + check_y * 0.2)]
		[(int)(player->pos_x + check_x * 0.2)] != '0')
			return (0);
	}
	if (x_shift)
	{
		new_pos_x = player->pos_x + x_shift;
		if (map[(int)(player->pos_y + check_y * 0.2)]
		[(int)(new_pos_x + check_x * 0.2)] != '0')
			return (0);
	}
	return (1);
}

t_move		get_move(double angle)
{
	t_move	move;
	double	rad_angle;

	rad_angle = angle;
	move.x_shift = sin(rad_angle) * 0.2;
	move.y_shift = cos(rad_angle) * 0.2 * -1;
	move.offset_wall_x = move.x_shift > 0 ? 1 : -1;
	move.offset_wall_y = move.y_shift > 0 ? 1 : -1;
	return (move);
}

void		move_player(double angle, t_data *data)
{
	t_move	move;

	move = get_move(angle);
	if (!(is_move_possible(&data->player, data->map, 0, move.x_shift)
	&& !is_move_possible(&data->player, data->map, move.y_shift, move.x_shift)
	&& is_move_possible(&data->player, data->map, move.y_shift, 0)))
	{
		if (is_move_possible(&data->player, data->map, 0, move.x_shift))
			data->player.pos_x += move.x_shift;
		if (is_move_possible(&data->player, data->map, move.y_shift, 0))
			data->player.pos_y += move.y_shift;
	}
}
