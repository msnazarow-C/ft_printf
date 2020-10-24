/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgertrud <msnazarow@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 00:25:39 by sgertrud          #+#    #+#             */
/*   Updated: 2020/10/24 05:22:09 by sgertrud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "init.h"
#include "fcntl.h"
#include "get_next_line.h"
#include "errors.h"

static int	parse_color(char *line, char **spl, t_data *d)
{
	char**spt;
	int	i;
	int	j;

	if (ft_strcmp("C", spl[0]) && ft_strcmp("F", spl[0]))
		return (-2);
	if (!(spt = ft_split(line, " ,")))
		return ((size_t)ft_clear_splitted(spt) + ERR_MALLOC);
	if (!spt[1] || !spt[2] || !spt[3] || spt[4])
		return ((size_t)ft_clear_splitted(spt) + ERR_SX_COLOR);
	if (count_comma(line))
		return ((size_t)ft_clear_splitted(spt) + ERR_SX_COLOR);
	i = 0;
	while (++i < 4 && (j = -1))
	{
		while (spt[i][++j])
			if (!ft_strchr("0123456789", spt[i][j]))
				return ((size_t)ft_clear_splitted(spt) + ERR_COLOR_VAL);
		if (ft_atoi(spt[i]) > 255 || ft_atoi(spt[i]) < 0)
			return ((size_t)ft_clear_splitted(spt) + ERR_COLOR_VAL);
	}
	if (color(spt, d))
		return ((size_t)ft_clear_splitted(spt) + ERR_DUP_KEY);
	ft_clear_splitted(spt);
	return (0);
}

static int	parse_texture(char **spl, t_data *d)
{
	int		fd;

	if (ft_strcmp("S", spl[0]) && ft_strcmp("NO", spl[0]) &&
		ft_strcmp("SO", spl[0]) && ft_strcmp("EA", spl[0]) &&
		ft_strcmp("WE", spl[0]))
		return (-2);
	if ((fd = open(spl[1], O_RDONLY)) == -1)
		return (ERR_OPEN_TX);
	close(fd);
	if (spl[2])
		return (ERR_OPEN_TX);
	if (!ft_strcmp(spl[0], "NO"))
		if (d->ps.north || !(d->ps.north = ft_strdup(spl[1])))
			return (ERR_DUP_KEY);
	if (!ft_strcmp(spl[0], "SO") && (d->ps.s || !(d->ps.s = ft_strdup(spl[1]))))
		return (ERR_DUP_KEY);
	if (!ft_strcmp(spl[0], "EA") && (d->ps.e || !(d->ps.e = ft_strdup(spl[1]))))
		return (ERR_DUP_KEY);
	if (!ft_strcmp(spl[0], "WE"))
		if (d->ps.west || !(d->ps.west = ft_strdup(spl[1])))
			return (ERR_DUP_KEY);
	if (!ft_strcmp(spl[0], "S"))
		if (d->ps.sprite || !(d->ps.sprite = ft_strdup(spl[1])))
			return (ERR_DUP_KEY);
	return (0);
}

static int	parse_resolution(char **spl, t_data *d)
{
	int	i;
	int j;

	if (ft_strcmp("R", spl[0]))
		return (-2);
	if (!spl[0] || !spl[1] || !spl[2] || spl[3])
		return (ERR_SX_RES);
	if (d->mlx.w != -1 || d->mlx.h != -1)
		return (ERR_DUP_KEY);
	j = 0;
	while (++j < 3 && !(i = 0))
		while (spl[j][i])
		{
			if (!ft_strchr("0123456789", spl[j][i]))
				return (ERR_SX_RES);
			i++;
		}
	if (ft_atoi(spl[1]) == 0 || ft_atoi(spl[2]) == 0)
		return (ERR_RES_TOO_LOW);
	d->mlx.w = ft_atoi(spl[1]) > d->scr_w || ft_atoi(spl[1]) < 0 ?
	d->scr_w : ft_atoi(spl[1]);
	d->mlx.h = ft_atoi(spl[2]) > d->scr_h || ft_atoi(spl[2]) < 0 ? d->scr_h :
	ft_atoi(spl[2]);
	return (0);
}

static int	parse_map(char **spl, char *line, t_data *d)
{
	int		i;

	if (spl[0][0] != '1' && spl[0][0] != '0')
		return (-2);
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
	d->map = ft_realloc(d->map, d->map_h + 1, d->map_h + 2);
	d->map_w = d->map_w < ft_strlen(line) ? ft_strlen(line) : d->map_w;
	d->map[d->map_h] = ft_strdup(line);
	d->map_h++;
	d->param[1] = 1;
	return (0);
}

int			parse_line(char *line, t_data *d)
{
	char	**spl;
	int		ret_code;

	ret_code = -2;
	if (!(spl = ft_split(line, " ")))
		return ((size_t)ft_clear_splitted(spl) + ERR_MALLOC);
	if (!*spl && d->param[1])
		d->param[1] = 2;
	if (!*spl)
		return ((size_t)ft_clear_splitted(spl));
	else if (!(spl[0][0] == '1' || spl[0][0] == '0') && d->param[1])
		return ((size_t)ft_clear_splitted(spl) + ERR_MAP_NOT_LAST);
	if (*spl && d->param[1] == 2)
		return ((size_t)ft_clear_splitted(spl) + ERR_EMPTY_LINE_MAP);
	if ((ret_code = parse_color(line, spl, d)) > 1)
		return ((size_t)ft_clear_splitted(spl) + ret_code);
	else if (ret_code == -2 && (ret_code = parse_texture(spl, d)) > 1)
		return ((size_t)ft_clear_splitted(spl) + ret_code);
	else if (ret_code == -2 && (ret_code = parse_map(spl, line, d)) > 1)
		return ((size_t)ft_clear_splitted(spl) + ret_code);
	else if (ret_code == -2 && (ret_code = parse_resolution(spl, d)) > 1)
		return ((size_t)ft_clear_splitted(spl) + ret_code);
	else if (ret_code == -2)
		ret_code = 23;
	return ((size_t)ft_clear_splitted(spl) + ret_code);
}
