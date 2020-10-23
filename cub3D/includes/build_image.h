/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_image.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgertrud <msnazarow@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 23:38:26 by sgertrud          #+#    #+#             */
/*   Updated: 2020/10/23 23:40:42 by sgertrud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILD_IMAGE_H
# define BUILD_IMAGE_H

# include "libft.h"
# include "cub3d.h"

typedef struct	s_column
{
	char		wall;
	int			column;
	int			height;
	int			start;
	int			end;
	double		impact_x;
	double		impact_y;
	t_list		*sprites;
}				t_column;

int				get_sky_color(t_data *data);
int				get_floor_color(t_data *data);
int				get_wall_color(t_data *data, t_column *column, int line);
int				get_sprite_color(t_data *data, t_column *column, int line,
					int *px);
int				build_image(t_data *data, t_img **img);

#endif
