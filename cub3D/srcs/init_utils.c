/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgertrud <msnazarow@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 00:23:48 by sgertrud          #+#    #+#             */
/*   Updated: 2020/10/24 04:10:12 by sgertrud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"
#include "libft.h"
#include "errors.h"

static int	is_point_closed(t_data *data, int x, int y)
{
	if (y - 1 < 0 || data->map[y - 1][x] == ' ')
		return (ERR);
	if (x + 1 >= data->map_w || data->map[y][x + 1] == ' ')
		return (ERR);
	if (y + 1 >= data->map_h || data->map[y + 1][x] == ' ')
		return (ERR);
	if (x - 1 < 0 || data->map[y][x - 1] == ' ')
		return (ERR);
	return (OK);
}

int			is_map_closed(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < data->map_h)
	{
		x = 0;
		while (x < data->map_w)
		{
			if (data->map[y][x] == '0' || data->map[y][x] == '2')
				if (is_point_closed(data, x, y))
					return (ERR_MAP_NOT_CLOSE);
			x++;
		}
		y++;
	}
	return (0);
}

char		*get_value_after_key(char *line)
{
	while (*line && !(*line == '\f' || *line == '\t' || *line == ' ' ||
					*line == '\n' || *line == '\r' || *line == '\v'))
		line++;
	while (*line && (*line == '\f' || *line == '\t' || *line == ' ' ||
					*line == '\n' || *line == '\r' || *line == '\v'))
		line++;
	return (line);
}
