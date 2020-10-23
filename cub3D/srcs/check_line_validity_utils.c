/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_line_validity_utils.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgertrud <msnazarow@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 00:41:23 by sgertrud          #+#    #+#             */
/*   Updated: 2020/10/24 00:41:26 by sgertrud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <fcntl.h>
#include "init.h"

int	check_color_value(char **splitted)
{
	int	i;
	int	j;

	i = 1;
	while (i < 4)
	{
		j = 0;
		while (splitted[i][j])
		{
			if (!ft_strchr("0123456789", splitted[i][j]))
				return (ERR_SX_COLOR);
			j++;
		}
		if (ft_atoi(splitted[i]) > 255)
			return (ERR_COLOR_VAL);
		i++;
	}
	return (OK);
}
