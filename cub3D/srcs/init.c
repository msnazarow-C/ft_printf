/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgertrud <msnazarow@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 00:11:33 by sgertrud          #+#    #+#             */
/*   Updated: 2020/10/24 00:30:27 by sgertrud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <fcntl.h>
#include "libft.h"
#include "mlx.h"
#include "cub3d.h"
#include "init.h"

static void	check_args(int argc, char **argv)
{
	if (argc < 2 || argc > 3 || (argc == 3 && ft_strncmp(argv[2], "--save",
		ft_strlen(argv[2]))) || (ft_strlen(argv[1]) <= 4 ||
		ft_strncmp(&argv[1][ft_strlen(argv[1]) - 4], ".cub", 4)))
	{
		ft_putstr_fd("Error\nWrong arguments or map format\n", 1);
		exit(0);
	}
}

static void	init_data(t_data *data)
{
	int	i;

	data->map = NULL;
	data->map_w = 0;
	data->map_h = 0;
	i = -1;
	while (++i < 8)
		data->keylist[i] = 0;
	data->paths.north = NULL;
	data->paths.south = NULL;
	data->paths.east = NULL;
	data->paths.west = NULL;
	data->paths.sprite = NULL;
	data->mlx.north_texture.img = NULL;
	data->mlx.south_texture.img = NULL;
	data->mlx.east_texture.img = NULL;
	data->mlx.west_texture.img = NULL;
	data->mlx.sprite_texture.img = NULL;
	data->color_textures.sky = -1;
	data->color_textures.floor = -1;
	data->param[0] = 0;
	data->param[1] = 0;
	data->mlx.w = -1;
	data->mlx.h = -1;
	data->mlx.mlx_window_id = NULL;
}

int			init(int argc, char **argv, t_data **data)
{
	int	ret_code;
	int	fd;

	if (!(*data = malloc(sizeof(t_data))))
		return (-1);
	init_data(*data);
	check_args(argc, argv);
	if (!((*data)->mlx.mlx_id = mlx_init()))
		return (-1);
	if ((fd = open(argv[1], O_RDONLY)) == -1)
		return (-1);
	if ((ret_code = read_input_file(fd, *data)) != OK)
		return (ret_code);
	close(fd);
	if ((ret_code = load_data(*data)) != OK)
		return (ret_code);
	if ((ret_code = is_map_closed(*data)) != OK)
		return (ret_code);
	return (OK);
}
