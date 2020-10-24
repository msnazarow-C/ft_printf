/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgertrud <msnazarow@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 04:34:56 by sgertrud          #+#    #+#             */
/*   Updated: 2020/10/24 05:43:31 by sgertrud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "libft.h"
# include "math.h"
# define FOV 1.04719755119659774615

typedef struct	s_texture_img
{
	int					width;
	int					height;
	int					bpp;
	int					size;
	int					endian;
	void				*img;
	int					*data;
}				t_texture;

typedef struct	s_player
{
	double				pos_x;
	double				pos_y;
	double				orientation;
}				t_player;

typedef struct	s_mlx
{
	void			*mlx_id;
	void			*mlx_window_id;
	int				w;
	int				h;
	t_texture		north_texture;
	t_texture		south_texture;
	t_texture		east_texture;
	t_texture		west_texture;
	t_texture		sprite_texture;
}				t_mlx;

typedef struct	s_textures_paths
{
	char				*north;
	char				*s;
	char				*e;
	char				*west;
	char				*sprite;
}				t_textures_paths;

typedef struct	s_color_textures
{
	int					floor;
	int					sky;
}				t_color_textures;

typedef struct	s_img
{
	void		*img;
	int			*data;
	int			bpp;
	int			size;
	int			endian;
}				t_img;
typedef struct	s_data
{
	t_player			player;
	t_mlx				mlx;
	t_img				*img;
	t_textures_paths	ps;
	t_color_textures	color_textures;
	char				**map;
	int					map_w;
	int					map_h;
	int					scr_w;
	int					scr_h;
	int					keylist[8];
	char				*line;
	char				param[2];
}				t_data;
int				exit_program(t_data *data);
int				draw_image_mlx(t_data *data);
int				handle_errors(int error_code, t_data *data);
int				handle_moves(t_data *data);
int				handle_keypress(int keycode, t_data *data);
int				handle_keyrelease(int keycode, t_data *data);
#endif
