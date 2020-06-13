/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgertrud <msnazarow@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/03 02:21:10 by sgertrud          #+#    #+#             */
/*   Updated: 2020/06/12 22:52:44 by sgertrud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIBFTPRINTF_H
# define FT_LIBFTPRINTF_H
# include "libft.h"
# include "libftprintf_utils.h"
# include "length.h"
# include "f_print.h"
# include <stdbool.h>

char			*parsing(char *s, t_format *format, va_list arg);
int				ft_printf(const char *s, ...);
int				cv(char **s);
int				printing(t_format *format, va_list arg);
void			clear(t_format *format);
int				print_width(t_format *format, va_list arg);
int				nbr(long long nb, int fd, t_format *format);
int				nbr_f(long double nb, int fd);
int				nbr_ull(unsigned long long nb, int fd, t_format *f);
int				lbase(long long a, t_format *f, int base);
int				ft_putstr_fd_f(char *s, int fd, t_format *format);
int				nbrbase(unsigned long long nb, int fd, int base, t_format *f);
int				print_one(t_format *f, va_list arg);
int				printhex(char c, t_format *f);
int				print_zeros(t_format *f);
int				putstr(t_format *f, va_list arg);
int				ft_putstr_w(wchar_t *s, int fd, t_format *f);
int				is_float(char c);
int				f_print(t_format *f,long double d);
int				e_print(t_format *f,long double d);

#endif
