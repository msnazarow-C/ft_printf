/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_line_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgertrud <msnazarow@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 05:15:21 by sgertrud          #+#    #+#             */
/*   Updated: 2020/10/24 05:16:23 by sgertrud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "errors.h"

int	color(char **spt, t_data *d)
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

int	count_comma(char *line)
{
	char	count;
	char	first_comma;

	first_comma = 0;
	count = 0;
	while (*line == ' ')
		line++;
	line++;
	while (*line == ' ')
		line++;
	while (*line)
	{
		if (!first_comma && *line == ',')
			return (-1);
		else
			first_comma = 1;
		if (*line == ',')
			count++;
		if (count > 2)
			return (-1);
		line++;
	}
	if (count < 2)
		return (-1);
	return (0);
}
