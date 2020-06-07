/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf_utils.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgertrud <msnazarow@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/07 06:56:40 by sgertrud          #+#    #+#             */
/*   Updated: 2020/06/07 22:14:54 by sgertrud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIBFTPRINTF_UTILS_H
# define FT_LIBFTPRINTF_UTILS_H

int				ft_abs(int a);
int				u_digital(char c);
int				digital(int c);
char			bigdigit(int a);
char			smalldigit(int a);
int				base(char c);
int				max(int a, int b);
int				min(int a, int b);
int				is_flag(char c);

#endif
