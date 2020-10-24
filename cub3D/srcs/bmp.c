/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgertrud <msnazarow@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 23:34:37 by sgertrud          #+#    #+#             */
/*   Updated: 2020/10/24 04:04:50 by sgertrud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "bmp.h"
#include "build_image.h"
#include <fcntl.h>

void		set_body(int file, t_img *img, t_data *d)
{
	int				x;
	int				y;
	unsigned int	color;

	y = d->mlx.h;
	while (--y >= 0 && (x = -1))
		while (++x < d->mlx.w)
		{
			color = img->data[d->mlx.w * y + x];
			write(file, &color, 4);
		}
}

void		write_file(int file, t_img *img, t_data *d)
{
	write(file, &(short){0x4d42}, 2);
	write(file, &((t_bmp_header){54 + d->mlx.w * d->mlx.h * 4, 0, 0, 54,
	40, d->mlx.w, d->mlx.h, 1, 32, 0, 0, 5000, 5000, 0, 0}), 52);
	set_body(file, img, d);
}

int			save_bmp(t_data *d)
{
	int						file;
	int						ret_code;

	if ((ret_code = build_image(d, &d->img)))
		return (ret_code);
	if (!(file = open("save.bmp", O_CREAT | O_RDWR | O_TRUNC, 0666)))
	{
		ft_putstr_fd("Could not write file\n", 2);
		return (1);
	}
	write_file(file, d->img, d);
	close(file);
	return (0);
}
