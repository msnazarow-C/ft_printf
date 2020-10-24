/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_image_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgertrud <msnazarow@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 00:41:47 by sgertrud          #+#    #+#             */
/*   Updated: 2020/10/24 05:08:49 by sgertrud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "build_image.h"

int		get_texture_px(t_texture *texture, t_column *column, int line)
{
	double	ray_block_x;
	int		texture_px;

	ray_block_x = 0.0;
	if (column->wall == 'N')
		ray_block_x = 1. - (column->impact_x - (int)column->impact_x);
	else if (column->wall == 'S')
		ray_block_x = column->impact_x - (int)column->impact_x;
	else if (column->wall == 'E')
		ray_block_x = 1. - (column->impact_y - (int)column->impact_y);
	else if (column->wall == 'W')
		ray_block_x = column->impact_y - (int)column->impact_y;
	texture_px = line * texture->width + (int)(ray_block_x * texture->width);
	return (texture->data[texture_px]);
}

int		get_sky_color(t_data *data)
{
	return (data->color_textures.sky);
}

int		get_floor_color(t_data *data)
{
	return (data->color_textures.floor);
}

int		get_wall_color(t_data *data, t_column *column, int line)
{
	if (column->wall == 'N')
		if (!data->ps.north)
			return (0xff0000);
		else
			return (get_texture_px(&data->mlx.north_texture, column,
				line * data->mlx.north_texture.height / column->height));
	else if (column->wall == 'S')
		if (!data->ps.s)
			return (0xffff00);
		else
			return (get_texture_px(&data->mlx.south_texture, column,
				line * data->mlx.south_texture.height / column->height));
	else if (column->wall == 'E')
		if (!data->ps.e)
			return (0x0000ff);
		else
			return (get_texture_px(&data->mlx.east_texture, column,
				line * data->mlx.east_texture.height / column->height));
	else if (!data->ps.west)
		return (0xffffff);
	else
		return (get_texture_px(&data->mlx.west_texture, column,
				line * data->mlx.west_texture.height / column->height));
}
