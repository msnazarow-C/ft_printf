/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgertrud <msnazarow@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/19 10:03:08 by sgertrud          #+#    #+#             */
/*   Updated: 2020/05/19 10:11:02 by sgertrud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void *out;

	if (!(out = malloc(size * nmemb)))
		return (0);
	ft_bzero(out, size * nmemb);
	return (out);
}
