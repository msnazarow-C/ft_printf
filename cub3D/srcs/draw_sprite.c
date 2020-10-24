/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_sprite_drawing.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgertrud <msnazarow@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 00:14:09 by sgertrud          #+#    #+#             */
/*   Updated: 2020/10/24 00:14:48 by sgertrud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "build_image.h"
#include "raycasting_engine.h"

static int	set_px(t_data *data, t_sprite *sprite, int *px, int line)
{
	int	sprite_texture_px;
	int	sprite_height;

	sprite_height = data->mlx.w / sprite->dist;
	if (line > data->mlx.h / 2 - sprite_height / 2 &&
			line < data->mlx.h / 2 + sprite_height / 2)
	{
		sprite_texture_px =
			((line - (data->mlx.h / 2 - sprite_height / 2)) *
			data->mlx.sprite_texture.height / sprite_height) *
			data->mlx.sprite_texture.width +
			(sprite->texture_column * data->mlx.sprite_texture.width);
		if (data->mlx.sprite_texture.data[sprite_texture_px])
		{
			*px = data->mlx.sprite_texture.data[sprite_texture_px];
			return (1);
		}
	}
	return (0);
}

int			get_sprite_color(t_data *data, t_column *column, int line, int *px)
{
	t_sprite	*sprite;
	t_list		*sprites;
	int			color;

	color = 0;
	sprites = column->sprites;
	while (sprites && sprites->content)
	{
		sprite = sprites->content;
		if (set_px(data, sprite, px, line))
		{
			color = 1;
			break ;
		}
		sprites = sprites->next;
	}
	return (*px != 0 && color);
}
