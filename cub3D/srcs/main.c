/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgertrud <msnazarow@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 00:10:39 by sgertrud          #+#    #+#             */
/*   Updated: 2020/10/24 00:17:19 by sgertrud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "mlx.h"
#include "cub3d.h"
#include "init.h"
#include "stdio.h"
#include "errno.h"
#include "bmp.h"

int		main(int argc, char **argv)
{
	int		ret_code;
	t_data	*data;

	if ((ret_code = init(argc, argv, &data)))
	{
		if (ret_code == -1)
			perror("Error\n");
		else
			handle_errors(ret_code, data);
		exit(ret_code);
	}
	if (!(data->img = malloc(sizeof(t_img))))
		return (ERR_MALLOC);
	data->img->img = mlx_new_image(data->mlx.mlx_id, data->mlx.w,
			data->mlx.h);
	data->img->data = (int*)mlx_get_data_addr(
		data->img->img, &data->img->bpp, &data->img->size, &data->img->endian);
	if (argc == 3)
	{
		if ((ret_code = save_bmp(data)))
			handle_errors(ret_code, data);
		exit_program(data);
	}
	else
	{
		if (!(data->mlx.mlx_window_id = mlx_new_window(data->mlx.mlx_id,
						data->mlx.w, data->mlx.h, "cub3D")))
			handle_errors(ret_code, data);
		mlx_mouse_hide(data->mlx.mlx_id, data->mlx.mlx_window_id);
		mlx_hook(data->mlx.mlx_window_id, 2, 1L << 0, handle_keypress, data);
		mlx_hook(data->mlx.mlx_window_id, 3, 1L << 1, handle_keyrelease, data);
		mlx_hook(data->mlx.mlx_window_id, 17, 1L << 17, exit_program, data);
		draw_image_mlx(data);
		mlx_loop_hook(data->mlx.mlx_id, handle_moves, data);
		mlx_loop(data->mlx.mlx_id);
	}
}
