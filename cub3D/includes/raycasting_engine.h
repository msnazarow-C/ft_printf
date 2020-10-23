/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_engine.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgertrud <msnazarow@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 23:43:37 by sgertrud          #+#    #+#             */
/*   Updated: 2020/10/24 00:07:38 by sgertrud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCASTING_ENGINE_H
# define RAYCASTING_ENGINE_H

# include "cub3d.h"
# include "libft.h"

typedef struct	s_ray
{
	double	ray_len;
	char	wall;
	double	impact_x;
	double	impact_y;
	t_list	*sprites;
}				t_ray;

typedef struct	s_sprite
{
	double	pos_x;
	double	pos_y;
	double	dist;
	double	impact_distance;
	double	angle;
	double	angle_diff;
	double	texture_column;
}				t_sprite;

t_ray			get_x_ray_len(t_data *data, double angle);
t_ray			get_y_ray_len(t_data *data, double angle);
void			sprite_detection(t_ray *ray, t_data *data, double angle,
				char ray_type);
t_ray			get_ray(t_data *data, double angle, double offset);
void			remove_sprite(t_list *prev, t_list **elem, t_ray *ray);

#endif
