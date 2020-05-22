/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgertrud <msnazarow@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/20 09:13:42 by sgertrud          #+#    #+#             */
/*   Updated: 2020/05/20 15:43:58 by sgertrud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(char *str, char *to_find, size_t len)
{
	size_t start;
	size_t i;

	start = 0;
	if (*to_find == 0)
		return (str);
	while (str[start] != '\0' && start < len)
	{
		i = 0;
		while (str[start + i] == to_find[i] && start + i < len)
		{
			i++;
			if (to_find[i] == '\0')
				return (&str[start]);
		}
		start++;
	}
	return (0);
}
