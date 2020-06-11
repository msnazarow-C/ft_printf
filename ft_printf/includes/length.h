/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   length.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgertrud <msnazarow@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/07 07:02:10 by sgertrud          #+#    #+#             */
/*   Updated: 2020/06/11 22:57:04 by sgertrud         ###   ########.fr       */
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
	char	inf;
	char	g;
}				t_format;

int				ft_strlen_f(char *s, t_format *f);
int				u_lbase(unsigned long long a, t_format *f, int base);
int				nbr_ull(unsigned long long nb, int fd, t_format *f);
int				lenhex(char c, t_format *f);
int				lenprint(t_format *f, va_list arg);
int				ft_strlen_cw(t_format *f, va_list arg);
size_t			ft_strlen_w(const wchar_t *s, t_format *f);
int				f_len(t_format *f, double num);
int				e_len(t_format *f, double num);
int				g_len(t_format *f, double num);
int				u_len(t_format *f, va_list arg);
int				s_len(t_format *f, va_list arg);
#endif
