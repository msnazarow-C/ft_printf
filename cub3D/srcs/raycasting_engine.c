/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_engine.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgertrud <msnazarow@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 23:41:35 by sgertrud          #+#    #+#             */
/*   Updated: 2020/10/24 00:04:27 by sgertrud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting_engine.h"
#include <math.h>
#include "cub3d.h"

typedef struct s_ray	t_ray;

int				is_sprite_closer(void *content1, void *content2)
{
	t_sprite	*sprite1;
	t_sprite	*sprite2;

	sprite1 = content1;
	sprite2 = content2;
	if (sprite1->dist > sprite2->dist)
		return (1);
	return (0);
}

static void		remove_unwanted_sprites(t_ray *ray)
{
	t_list		*elem;
	t_list		*prev;
	t_sprite	*sprite;

	prev = NULL;
	elem = ray->sprites;
	while (elem)
	{
		sprite = elem->content;
		if (sprite->impact_distance > ray->ray_len
			|| sprite->texture_column > 1 || sprite->texture_column < 0)
			remove_sprite(prev, &elem, ray);
		else
		{
			prev = elem;
			elem = elem->next;
		}
	}
}

static t_ray	choose_ray(double offset, double angle, t_ray ray_x,
		t_ray ray_y)
{
	if (ray_y.ray_len < ray_x.ray_len)
	{
		ray_y.wall = ((angle >= M_PI_2 && (angle < (3 * M_PI_2))) ? 'N' : 'S');
		ft_lstconcat(&ray_y.sprites, &ray_x.sprites);
		ft_lstsort(&ray_y.sprites, &is_sprite_closer);
		remove_unwanted_sprites(&ray_y);
		ray_y.ray_len *= cos(offset);
		return (ray_y);
	}
	else
	{
		ray_x.wall = ((angle >= 0 && (angle < M_PI)) ? 'W' : 'E');
		ft_lstconcat(&ray_x.sprites, &ray_y.sprites);
		ft_lstsort(&ray_x.sprites, &is_sprite_closer);
		remove_unwanted_sprites(&ray_x);
		ray_x.ray_len *= cos(offset);
		return (ray_x);
	}
}

t_ray			get_ray(t_data *data, double angle, double offset)
{
	t_ray	ray_y;
	t_ray	ray_x;

	ray_x = get_x_ray_len(data, angle);
	ray_y = get_y_ray_len(data, angle);
	return (choose_ray(offset, angle, ray_x, ray_y));
}
