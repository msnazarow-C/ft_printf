/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_input_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgertrud <msnazarow@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 23:30:34 by sgertrud          #+#    #+#             */
/*   Updated: 2020/10/24 05:08:49 by sgertrud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "mlx.h"
#include "get_next_line.h"
#include "init.h"
#include "errors.h"

int		missing_data(t_data *data)
{
	if (!data->map)
		return (ERR_MISSING_MAP);
	if (!data->ps.north)
		return (ERR_MISSING_NO);
	if (!data->ps.s)
		return (ERR_MISSING_SO);
	if (!data->ps.e)
		return (ERR_MISSING_EA);
	if (!data->ps.west)
		return (ERR_MISSING_WE);
	if (data->color_textures.sky == -1)
		return (ERR_MISSING_C);
	if (data->color_textures.floor == -1)
		return (ERR_MISSING_F);
	if (!data->ps.sprite)
		return (ERR_MISSING_S);
	if (data->mlx.w == -1)
		return (ERR_MISSING_R);
	if (!data->param[0])
		return (ERR_NO_PLAYER);
	return (OK);
}

int		read_input_file(int fd, t_data *data)
{
	int				status;
	int				ret_code;

	mlx_get_screen_size(data->mlx.mlx_id, &data->scr_w, &data->scr_h);
	while ((status = get_next_line(fd, &data->line)) >= 0)
	{
		if ((ret_code = parse_line(data->line, data)))
			return (ret_code);
		free(data->line);
		if (status == 0)
			break ;
	}
	if (status == -1)
		return (ERR);
	if ((ret_code = missing_data(data)) != OK)
		return (ret_code);
	return (OK);
}
