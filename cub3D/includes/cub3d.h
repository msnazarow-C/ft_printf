/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgertrud <msnazarow@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 18:31:02 by frdescam          #+#    #+#             */
/*   Updated: 2020/10/24 00:30:27 by sgertrud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "libft.h"
# include "math.h"
# define FOV M_PI /3

# define OK 0
# define ERR 1
# define ERR_TOO_FEW_ARGS 10
# define ERR_TOO_MUCH_ARGS 11
# define ERR_UK_ARG  12
# define ERR_NOT_CUB_MAP 13

# define ERR_OPEN_MAP 20
# define ERR_EOF_UNTIMELY 21
# define ERR_EMPTY_LINE_MAP 22
# define ERR_SX_UK_KEY 23
# define ERR_SX_TOO_FEW_VAL 24
# define ERR_SX_TOO_MUCH_VAL 25
# define ERR_OPEN_TX 26
# define ERR_DUP_KEY 27

# define ERR_SX_COLOR 28

# define ERR_COLOR_VAL 29
# define ERR_SX_RES 30
# define ERR_SX_MAP 31
# define ERR_TOO_MUCH_PLAYER 32

# define ERR_MISSING_MAP 33
# define ERR_MISSING_NO 34
# define ERR_MISSING_SO 35
# define ERR_MISSING_EA 36
# define ERR_MISSING_WE 37
# define ERR_MISSING_C 38
# define ERR_MISSING_F 39
# define ERR_MISSING_S 40
# define ERR_MISSING_R 41
# define ERR_KEY_ON_MAP 42
# define ERR_MAP_NOT_CLOSE 43
# define ERR_NO_PLAYER 44
# define ERR_RES_TOO_LOW 45
# define ERR_WRITING_BMP 46
# define ERR_MAP_NOT_LAST 47

# define ERR_MLX 50
# define ERR_MALLOC 51

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
	void				*mlx_id;
	void				*mlx_window_id;
	int					w;
	int					h;
	t_texture		north_texture;
	t_texture		south_texture;
	t_texture		east_texture;
	t_texture		west_texture;
	t_texture		sprite_texture;
}				t_mlx;

typedef struct	s_textures_paths
{
	char				*north;
	char				*south;
	char				*east;
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
	t_textures_paths	paths;
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
void			handle_errors(int error_code, t_data *data);
int				handle_moves(t_data *data);
int				handle_keypress(int keycode, t_data *data);
int				handle_keyrelease(int keycode, t_data *data);
#endif
