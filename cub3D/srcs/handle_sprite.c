/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_sprite.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgertrud <msnazarow@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 00:13:20 by sgertrud          #+#    #+#             */
/*   Updated: 2020/10/24 00:13:59 by sgertrud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting_engine.h"
#include "libft.h"
#include "cub3d.h"
#include <math.h>

void	build_sprite(t_data *data, t_sprite **spr, double angle, t_ray *ray)
{
	double		x_diff;
	double		y_diff;

	x_diff = -data->player.pos_x + (*spr)->pos_x;
	y_diff = -data->player.pos_y + (*spr)->pos_y;
	(*spr)->dist = sqrt(x_diff * x_diff + y_diff * y_diff);
	(*spr)->angle = (x_diff >= 0 ? -1 : 1) * acos(y_diff / (*spr)->dist) + M_PI;
	(*spr)->angle_diff = (*spr)->angle - angle;
	(*spr)->impact_distance = ray->ray_len;
	(*spr)->texture_column = 0.5 - (*spr)->dist * tan((*spr)->angle_diff);
}

void	sprite_detection(t_ray *ray, t_data *data, double angle, char ray_type)
{
	t_sprite	*spr;

	spr = malloc(sizeof(t_sprite));
	spr->pos_x = ((int)ray->impact_x) -
	((ray_type == 'x' && angle > M_PI) ? 0.5 : -0.5);
	spr->pos_y = ((int)ray->impact_y) -
	((ray_type == 'y' && (angle < M_PI_2 || angle > M_PI_2 * 3)) ? 0.5 : -0.5);
	build_sprite(data, &spr, angle, ray);
	ft_lstadd_front(&(ray->sprites), ft_lstnew(spr));
}
