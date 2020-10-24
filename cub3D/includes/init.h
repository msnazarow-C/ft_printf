/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgertrud <msnazarow@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 23:32:57 by sgertrud          #+#    #+#             */
/*   Updated: 2020/10/24 05:17:42 by sgertrud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_H
# define INIT_H

# include "cub3d.h"
# include "libft.h"

int				init(int argc, char **argv, t_data **data);
int				read_input_file(int fd, t_data *data);
int				parse_line(char *line, t_data *data);
int				load_data(t_data *data);
int				is_map_closed(t_data *data);
char			*get_value_after_key(char *line);
int				random_fn(char **splitted, int code, int *var_to_set);
int				color(char **spt, t_data *d);
int				count_comma(char *line);
#endif
