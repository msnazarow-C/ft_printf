/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_events.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgertrud <msnazarow@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 00:15:01 by sgertrud          #+#    #+#             */
/*   Updated: 2020/10/26 23:31:02 by sgertrud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "keys.h"
#include "cub3d.h"
#include "move_player.h"
#include <math.h>
#include <time.h>
#include <stdio.h>

clock_t t;

static int	is_key_pressed(t_data *data)
{
	return (data->keylist[RIGHT] || data->keylist[LEFT] || data->keylist[W] ||
			data->keylist[UP] || data->keylist[S] || data->keylist[DOWN] ||
			data->keylist[D] || data->keylist[A]);
}

int			handle_moves(t_data *data)
{
	if (is_key_pressed(data))
	{
		if (data->keylist[RIGHT])
			data->player.orientation += 0.04;
		if (data->keylist[LEFT])
			data->player.orientation -= 0.04;
		if (data->keylist[W] || data->keylist[UP])
			move_player(data->player.orientation, data);
		if (data->keylist[S] || data->keylist[DOWN])
			move_player(data->player.orientation - M_PI, data);
		if (data->keylist[D])
			move_player(data->player.orientation + M_PI_2, data);
		if (data->keylist[A])
			move_player(data->player.orientation - M_PI_2, data);
		if (data->player.orientation > 2 * M_PI)
			data->player.orientation -= 2 * M_PI;
		if (data->player.orientation < 0)
			data->player.orientation += 2 * M_PI;
	}
	t = clock();
	draw_image_mlx(data);
	t = t - clock();
	printf("%ld\n", CLOCKS_PER_SEC / t);
	return (0);
}

void		convert_keycode(int *keycode)
{
	if (*keycode == 65362)
		*keycode = UP;
	else if (*keycode == 65364)
		*keycode = DOWN;
	else if (*keycode == 65363)
		*keycode = RIGHT;
	else if (*keycode == 65361)
		*keycode = LEFT;
	else if (*keycode == 119)
		*keycode = W;
	else if (*keycode == 97)
		*keycode = A;
	else if (*keycode == 115)
		*keycode = S;
	else if (*keycode == 100)
		*keycode = D;
}

int			handle_keypress(int keycode, t_data *data)
{
	if (keycode == 65307)
		exit_program(data);
	convert_keycode(&keycode);
	if (keycode < 8)
		data->keylist[keycode] = 1;
	return (0);
}

int			handle_keyrelease(int keycode, t_data *data)
{
	convert_keycode(&keycode);
	if (keycode < 280)
		data->keylist[keycode] = 0;
	return (0);
}
