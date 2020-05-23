/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgertrud <msnazarow@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/23 06:03:14 by sgertrud          #+#    #+#             */
/*   Updated: 2020/05/23 06:21:55 by sgertrud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include "fcntl.h"
# include "unistd.h"

typedef struct		s_list
{
	struct s_list	*next;
	char			*data;
	int				len;
}					t_list;

#endif
