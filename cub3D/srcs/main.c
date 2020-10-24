/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgertrud <msnazarow@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 00:10:39 by sgertrud          #+#    #+#             */
/*   Updated: 2020/10/24 05:44:36 by sgertrud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "mlx.h"
#include "cub3d.h"
#include "init.h"
#include "stdio.h"
#include "errno.h"
#include "bmp.h"
#include "errors.h"

int		main(int argc, char **argv)
{
	int		ret_code;
	t_data	*d;

	if ((ret_code = init(argc, argv, &d)))
		handle_errors(ret_code, d);
	if (!(d->img = malloc(sizeof(t_img))))
		return (ERR_MALLOC);
	d->img->img = mlx_new_image(d->mlx.mlx_id, d->mlx.w, d->mlx.h);
	d->img->data = (int*)mlx_get_data_addr(
		d->img->img, &d->img->bpp, &d->img->size, &d->img->endian);
	if (argc == 3)
		if (!(ret_code = save_bmp(d)) || handle_errors(ret_code, d))
			exit_program(d);
	if (!(d->mlx.mlx_window_id = mlx_new_window(d->mlx.mlx_id,
						d->mlx.w, d->mlx.h, "cub3D")))
		handle_errors(ret_code, d);
	mlx_mouse_hide(d->mlx.mlx_id, d->mlx.mlx_window_id);
	mlx_hook(d->mlx.mlx_window_id, 2, 1L << 0, handle_keypress, d);
	mlx_hook(d->mlx.mlx_window_id, 3, 1L << 1, handle_keyrelease, d);
	mlx_hook(d->mlx.mlx_window_id, 17, 1L << 17, exit_program, d);
	draw_image_mlx(d);
	mlx_loop_hook(d->mlx.mlx_id, handle_moves, d);
	mlx_loop(d->mlx.mlx_id);
}
