/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgertrud <msnazarow@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/20 09:21:16 by sgertrud          #+#    #+#             */
/*   Updated: 2020/05/20 15:44:06 by sgertrud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int len;

	len = ft_strlen(s);
	while (c && (s[len - 1]) && len)
		if (s[--len] == (char)c)
			return ((char*)&s[len]);
	return (c == 0 ? (char*)&s[ft_strlen(s)] : 0);
}
