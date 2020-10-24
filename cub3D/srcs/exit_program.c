/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_program.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgertrud <msnazarow@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 22:03:44 by sgertrud          #+#    #+#             */
/*   Updated: 2020/10/24 05:54:22 by sgertrud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "cub3d.h"
#include "mlx.h"

int		exit_program(t_data *data)
{
	if (data->img)
		mlx_destroy_image(data->mlx.mlx_id, data->img->img);
	free(data->img);
	if (data->mlx.mlx_window_id)
		mlx_destroy_window(data->mlx.mlx_id, data->mlx.mlx_window_id);
	if (data->mlx.north_texture.img)
		mlx_destroy_image(data->mlx.mlx_id, data->mlx.north_texture.img);
	if (data->mlx.south_texture.img)
		mlx_destroy_image(data->mlx.mlx_id, data->mlx.south_texture.img);
	if (data->mlx.east_texture.img)
		mlx_destroy_image(data->mlx.mlx_id, data->mlx.east_texture.img);
	if (data->mlx.west_texture.img)
		mlx_destroy_image(data->mlx.mlx_id, data->mlx.west_texture.img);
	if (data->mlx.sprite_texture.img)
		mlx_destroy_image(data->mlx.mlx_id, data->mlx.sprite_texture.img);
	free(data->ps.e);
	free(data->ps.north);
	free(data->ps.s);
	free(data->ps.sprite);
	free(data->ps.west);
	free(data->mlx.mlx_id);
	if (data->map)
		ft_clear_splitted(data->map);
	exit(0);
}
