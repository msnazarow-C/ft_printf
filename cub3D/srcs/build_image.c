/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_image.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgertrud <msnazarow@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 00:41:31 by sgertrud          #+#    #+#             */
/*   Updated: 2020/10/24 05:36:06 by sgertrud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "cub3d.h"
#include "build_image.h"
#include "raycasting_engine.h"
#include "mlx.h"
#include <math.h>
#include "errors.h"

static void		draw_column_in_img(t_img *img, t_data *data, t_column *column)
{
	int		i;
	int		line;
	int		px;

	i = 0;
	while (i < data->mlx.h)
	{
		px = i * data->mlx.w + column->column;
		if (!get_sprite_color(data, column, i, &img->data[px]))
		{
			if (i < column->start)
				img->data[px] = get_sky_color(data);
			else if (i > column->end)
				img->data[px] = get_floor_color(data);
			else
			{
				if (column->height > data->mlx.h)
					line = i + (column->height - data->mlx.h) / 2;
				else
					line = i - column->start;
				img->data[px] = get_wall_color(data, column, line);
			}
		}
		i++;
	}
}

static void		draw_columns_in_img(t_img *img, t_column *columns, t_data *data)
{
	int		i;
	int		height;

	i = 0;
	while (i < data->mlx.w)
	{
		if (columns[i].height > data->mlx.h)
			height = data->mlx.h;
		else if (columns[i].height < 0)
			height = 0;
		else
			height = columns[i].height;
		columns[i].start = (data->mlx.h - height) / 2;
		columns[i].end = columns[i].start + height - 1;
		draw_column_in_img(img, data, &(columns[i]));
		i++;
	}
}

static void		build_columns(t_data *data, t_column *columns)
{
	double	offset;
	double	offset_inc;
	t_ray	ray;
	double	ray_angle;
	int		i;

	offset = -FOV / 2;
	offset_inc = FOV / (float)(data->mlx.w - 1);
	i = 0;
	while (i < data->mlx.w)
	{
		ray_angle = data->player.orientation + offset;
		ray_angle = (ray_angle > 2 * M_PI) ? ray_angle - 2 * M_PI : ray_angle;
		ray_angle = (ray_angle < 0) ? ray_angle + 2 * M_PI : ray_angle;
		ray.sprites = NULL;
		ray = get_ray(data, ray_angle, offset);
		offset += offset_inc;
		columns[i].impact_x = ray.impact_x;
		columns[i].impact_y = ray.impact_y;
		columns[i].column = i;
		columns[i].height = data->mlx.w / ray.ray_len;
		columns[i].wall = ray.wall;
		columns[i].sprites = ray.sprites;
		i++;
	}
}

void			clear_columns(t_data *data, t_column *columns)
{
	int		i;

	i = 0;
	while (i < data->mlx.w)
	{
		ft_lstclear(&(columns[i].sprites), free);
		i++;
	}
	free(columns);
}

int				build_image(t_data *data, t_img **img)
{
	t_column	*columns;

	if (!(columns = malloc(sizeof(t_column) * data->mlx.w)))
		return (ERR_MALLOC);
	build_columns(data, columns);
	draw_columns_in_img(*img, columns, data);
	clear_columns(data, columns);
	return (OK);
}
