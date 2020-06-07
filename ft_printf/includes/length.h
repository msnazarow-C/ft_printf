/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   length.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgertrud <msnazarow@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/07 07:02:10 by sgertrud          #+#    #+#             */
/*   Updated: 2020/06/07 16:55:42 by sgertrud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LENGTH_H
# define LENGTH_H

# include <stdarg.h>

typedef struct	s_format
{
	char	flag[5];
	int		width;
	int		prec;
	char	mod[2];
	char	cv;
	int		count;
	int		len;
	char	nil;
}				t_format;

int				ft_strlen_f(char *s, t_format *f);
int				u_lbase(unsigned long long a, t_format *f, int base);
int				nbr_ull(unsigned long long nb, int fd, t_format *f);
int				lenhex(char c, t_format *f);
int				lenprint(t_format *f, va_list arg);

#endif
