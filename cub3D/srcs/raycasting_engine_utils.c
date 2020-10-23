/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_engine_utils.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgertrud <msnazarow@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 23:44:24 by sgertrud          #+#    #+#             */
/*   Updated: 2020/10/24 00:03:52 by sgertrud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting_engine.h"

void	remove_sprite(t_list *prev, t_list **elem, t_ray *ray)
{
	t_list *tmp;

	if (prev)
		prev->next = (*elem)->next;
	else
		ray->sprites = (*elem)->next;
	tmp = (*elem)->next;
	ft_lstdelone(*elem, free);
	*elem = tmp;
}

t_ray	get_x_ray_len(t_data *data, double angle)
{
	t_ray	ray;
	int		check;

	check = (angle >= M_PI);
	ray.sprites = NULL;
	ray.impact_x = check ? (int)(data->player.pos_x) : ceil(data->player.pos_x);
	ray.impact_y = data->player.pos_y -
	(ray.impact_x - data->player.pos_x) / tan(angle);
	ray.ray_len = fabs((ray.impact_x - data->player.pos_x) /
	sin(angle));
	while (ray.impact_x >= check && ray.impact_x < data->map_w &&
		ray.impact_y >= 0 && ray.impact_y < data->map_h &&
		data->map[(int)ray.impact_y][(int)(ray.impact_x - check)] != '1')
	{
		if (data->map[(int)ray.impact_y][(int)(ray.impact_x - check)] == '2')
			sprite_detection(&ray, data, angle, 'x');
		ray.impact_x += (check ? -1 : 1);
		ray.impact_y = ray.impact_y + (check ? 1 : -1) / tan(angle);
		ray.ray_len = fabs((ray.impact_x - data->player.pos_x) /
		sin(angle));
	}
	return (ray);
}

t_ray	get_y_ray_len(t_data *data, double angle)
{
	t_ray	ray;
	int		check;

	check = (angle >= M_PI_2 && angle < (M_PI + M_PI_2));
	ray.sprites = NULL;
	ray.impact_y = check ? ceil(data->player.pos_y) : (int)data->player.pos_y;
	ray.impact_x = data->player.pos_x +
		(data->player.pos_y - ray.impact_y) * tan(angle);
	ray.ray_len = fabs((data->player.pos_y - ray.impact_y) / cos(angle));
	while (ray.impact_x >= 0 && ray.impact_x < data->map_w &&
		ray.impact_y >= !check && ray.impact_y < data->map_h &&
		data->map[(int)(ray.impact_y - !check)][(int)ray.impact_x] != '1')
	{
		if (data->map[(int)(ray.impact_y - !check)][(int)ray.impact_x] == '2')
			sprite_detection(&ray, data, angle, 'y');
		ray.impact_x += (check ? -1 : 1) * tan(angle);
		ray.impact_y += check ? 1 : -1;
		ray.ray_len = fabs((data->player.pos_y - ray.impact_y) / cos(angle));
	}
	return (ray);
}
