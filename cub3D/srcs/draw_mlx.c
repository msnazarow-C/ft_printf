/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgertrud <msnazarow@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 00:19:30 by sgertrud          #+#    #+#             */
/*   Updated: 2020/10/24 04:08:22 by sgertrud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "mlx.h"
#include "build_image.h"

int	draw_image_mlx(t_data *data)
{
	int		ret_code;

	if ((ret_code = build_image(data, &data->img)))
		return (ret_code);
	mlx_do_sync(data->mlx.mlx_id);
	mlx_put_image_to_window(
	data->mlx.mlx_id, data->mlx.mlx_window_id, data->img->img, 0, 0);
	return (0);
}
