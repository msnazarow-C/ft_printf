/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_line_validity.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgertrud <msnazarow@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 00:25:39 by sgertrud          #+#    #+#             */
/*   Updated: 2020/10/24 00:40:11 by sgertrud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "init.h"
#include "fcntl.h"
#include "get_next_line.h"

static int	color(char **spt, t_data *d)
{
	if (!ft_strcmp(spt[0], "F"))
		if (d->color_textures.floor == -1)
			d->color_textures.floor =
			(ft_atoi(spt[1]) << 16) + (ft_atoi(spt[2]) << 8) + ft_atoi(spt[3]);
		else
			return (ERR_DUP_KEY);
	else if (d->color_textures.sky == -1)
		d->color_textures.sky =
			(ft_atoi(spt[1]) << 16) + (ft_atoi(spt[2]) << 8) + ft_atoi(spt[3]);
	else
		return (ERR_DUP_KEY);
	return (0);
}

static int	parse_color(char *line, char **spl, t_data *d)
{
	char**spt;
	int	i;
	int	j;

	if (ft_strcmp("C", spl[0]) && ft_strcmp("F", spl[0]))
		return (-1);
	if (!(spt = ft_split(line, " ,")))
		return (-1);
	if (!spt[1] || !spt[2] || !spt[3] || spt[4])
		return (ERR_SX_COLOR);
	i = 0;
	while (++i < 4 && !(j = -1))
	{
		while (spt[i][++j])
			if (!ft_strchr("0123456789", spt[i][j]))
				return (-1);
		if (ft_atoi(spl[i]) > 255)
			return (-1);
	}
	if (color(spt, d))
		return (ERR_DUP_KEY);
	ft_clear_splitted(spt);
	return (0);
}

static int	parse_texture(char **spl, t_data *d)
{
	int		fd;

	if (!ft_strcmp("S", spl[0]) || !ft_strcmp("NO", spl[0]) ||
		!ft_strcmp("SO", spl[0]) || !ft_strcmp("EA", spl[0]) ||
		!ft_strcmp("WE", spl[0]))
	{
		if ((fd = open(spl[1], O_RDONLY)) == -1)
			return (-1);
		close(fd);
		if (!ft_strcmp(spl[0], "NO"))
			if (d->paths.north || !(d->paths.north = ft_strdup(spl[1])))
				return (ERR_DUP_KEY);
		if (!ft_strcmp(spl[0], "SO"))
			if (d->paths.south || !(d->paths.south = ft_strdup(spl[1])))
				return (ERR_DUP_KEY);
		if (!ft_strcmp(spl[0], "EA"))
			if (d->paths.east || !(d->paths.east = ft_strdup(spl[1])))
				return (ERR_DUP_KEY);
		if (!ft_strcmp(spl[0], "WE"))
			if (d->paths.west || !(d->paths.west = ft_strdup(spl[1])))
				return (ERR_DUP_KEY);
		if (!ft_strcmp(spl[0], "S"))
			if (d->paths.sprite || !(d->paths.sprite = ft_strdup(spl[1])))
				return (ERR_DUP_KEY);
		return (0);
	}
	return (-1);
}

static int	parse_resolution(char **spl, t_data *d)
{
	if (!ft_strcmp("R", spl[0]))
	{
		int	i;
		int j;
		if ((!spl[0] || !spl[1] || !spl[2]) && spl[3])
			return (ERR_SX_RES);
		if (d->mlx.w != -1 || d->mlx.h != -1)
			return (ERR_DUP_KEY);
		j = 0;
		while (j < 2 && (i = 1))
		{
			while (spl[j][i])
			{
				if (!ft_strchr("0123456789", spl[j][i]))
					return (ERR_SX_RES);
				i++;
			}
		j++;
		}
		if (ft_atoi(spl[1]) == 0 || ft_atoi(spl[2]) == 0)
			return (ERR_RES_TOO_LOW);
		d->mlx.w = ft_atoi(spl[1]) > d->scr_w ? d->scr_w : ft_atoi(spl[1]);
		d->mlx.h = ft_atoi(spl[2]) > d->scr_h ? d->scr_h: ft_atoi(spl[2]);
		return (0);
	}
	return (-1);
}

int	parse_map(char **spl, char *line, t_data *d)
{
	int		i;

	if (spl[0][0] == '1' || spl[0][0] == '0')
	{
		i = 0;
		while (line[i])
		{
			if (!ft_strchr("012NSEW ", line[i]))
				return (ERR_SX_MAP);
			if (ft_strchr("NSEW", line[i]))
			{
				if (!d->param[0])
					d->param[0] = 1;
				else
					return (ERR_TOO_MUCH_PLAYER);
			}
			i++;
		}

		d->map = ft_realloc(d->map,d->map_h + 1, d->map_h + 2);
		d->map_w = d->map_w < ft_strlen(line) ? ft_strlen(line) : d->map_w;
		d->map[d->map_h] = ft_strdup(line);
		d->map_h++;
		d->param[1] = 1;
		return (0);
	}
	return (-1);
}

int			parse_line(char *line, t_data *d)
{
	char	**spl;
	int		ret_code;

	ret_code = -1;
	if (!(spl = ft_split(line, " ")))
		return (-1);
	if (!*spl)
		return ((size_t)ft_clear_splitted(spl));
	else if (!(spl[0][0] == '1' || spl[0][0] == '0') && d->param[1])
		return ((size_t)ft_clear_splitted(spl) + ERR_MAP_NOT_LAST);
	if ((ret_code = parse_color(line, spl, d)) > 1)
		return (ret_code);
	else if (ret_code == -1 && (ret_code = parse_texture(spl, d)) > 1)
		return (ret_code);
	else if (ret_code == -1 && (ret_code = parse_map(spl, line, d)) > 1)
		return (ret_code);
	else if (ret_code == -1 && (ret_code = parse_resolution(spl, d)) > 1)
		return (ret_code);
	else if (ret_code == -1)
		ret_code = 1;
	ft_clear_splitted(spl);
	return (ret_code > 0 ? ret_code : 0);
}
