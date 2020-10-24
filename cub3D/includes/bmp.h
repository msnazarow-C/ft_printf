/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgertrud <msnazarow@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 04:34:43 by sgertrud          #+#    #+#             */
/*   Updated: 2020/10/24 05:32:05 by sgertrud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BMP_H
# define BMP_H

typedef struct
{
	unsigned int	bf_size;
	unsigned short	bf_reserved1;
	unsigned short	bf_reserved2;
	unsigned int	bf_off_bits;
	unsigned int	bi_size;
	int				bi_width;
	int				bi_height;
	unsigned short	bi_planes;
	unsigned short	bi_bit_count;
	unsigned int	bi_compression;
	unsigned int	bi_size_image;
	int				bi_x_pels_per_meter;
	int				bi_y_pels_per_meter;
	unsigned int	bi_clr_used;
	unsigned int	bi_clr_important;
}					t_bmp_header;

int					save_bmp(t_data *data);

#endif
