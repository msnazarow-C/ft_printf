/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgertrud <msnazarow@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/19 09:30:29 by sgertrud          #+#    #+#             */
/*   Updated: 2020/05/20 08:55:59 by sgertrud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char *out;

	if (!(out = (char*)malloc(sizeof(char) * (ft_strlen(s) + 1))))
		return (0);
	ft_strlcpy(out, s, ft_strlen(s) + 1);
	return (out);
}
