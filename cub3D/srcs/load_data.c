/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgertrud <msnazarow@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 00:23:37 by sgertrud          #+#    #+#             */
/*   Updated: 2020/10/24 05:08:49 by sgertrud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "init.h"
#include "libft.h"
#include "mlx.h"
#include <math.h>
#include "errors.h"

static int	load_texture(t_data *data, t_texture *texture,
		char *texture_path)
{
	if (!(texture->img = mlx_xpm_file_to_image(data->mlx.mlx_id, texture_path,
			&texture->width, &texture->height)))
		return (ERR_MLX);
	if (!(texture->data = (int *)mlx_get_data_addr(texture->img, &texture->bpp,
			&texture->size,
			&texture->endian)))
		return (ERR_MLX);
	return (OK);
}

static void	handle_player(t_data *data, char *player, int pos_x, int pos_y)
{
	if (*player == 'N')
		data->player.orientation = 0;
	if (*player == 'S')
		data->player.orientation = M_PI;
	if (*player == 'E')
		data->player.orientation = M_PI_2;
	if (*player == 'W')
		data->player.orientation = M_PI_2 * 3;
	data->player.pos_x = pos_x + 0.5;
	data->player.pos_y = pos_y + 0.5;
	*player = '0';
}

static int	fix_line(t_data *data, int line_index, int line_len)
{
	char	*tmp;
	int		i;

	if (line_len < data->map_w)
	{
		if (!(tmp = malloc(sizeof(char) * (data->map_w + 1))))
			return (ERR_MALLOC);
		i = 0;
		while (data->map[line_index][i])
		{
			tmp[i] = data->map[line_index][i];
			i++;
		}
		while (i < data->map_w)
		{
			tmp[i] = ' ';
			i++;
		}
		tmp[i] = '\0';
		free(data->map[line_index]);
		data->map[line_index] = tmp;
	}
	return (OK);
}

static int	fix_map(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->map_h)
	{
		if (fix_line(data, i, ft_strlen(data->map[i])) != OK)
			return (ERR_MALLOC);
		j = 0;
		while (j < data->map_w)
		{
			if (ft_strchr("NSEW", data->map[i][j]))
				handle_player(data, &data->map[i][j], j, i);
			j++;
		}
		i++;
	}
	return (OK);
}

int			load_data(t_data *data)
{
	int		ret_code;

	if ((ret_code = load_texture(data, &data->mlx.north_texture,
								data->ps.north)) != OK)
		return (ret_code);
	if ((ret_code = load_texture(data, &data->mlx.south_texture,
								data->ps.s)) != OK)
		return (ret_code);
	if ((ret_code = load_texture(data, &data->mlx.east_texture,
								data->ps.e)) != OK)
		return (ret_code);
	if ((ret_code = load_texture(data, &data->mlx.west_texture,
								data->ps.west)) != OK)
		return (ret_code);
	if ((ret_code = load_texture(data, &data->mlx.sprite_texture,
								data->ps.sprite)) != OK)
		return (ret_code);
	if ((ret_code = fix_map(data)) != OK)
		return (ret_code);
	return (OK);
}
