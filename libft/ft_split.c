/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgertrud <msnazarow@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/20 15:26:49 by sgertrud          #+#    #+#             */
/*   Updated: 2020/05/21 06:11:27 by sgertrud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	void	*free_mem(char **result)
{
	while (*result)
		free(*result++);
	free(result);
	return (NULL);
}

static int	numwords(char *str, char c)
{
	int i;
	int out;

	out = 0;
	i = 0;
	while (str[i])
	{
		while ((str[i] == c) && str[i])
			i++;
		out++;
		while (!(str[i] == c) && str[i])
			i++;
	}
	return (out);
}

static void	oneword(char *str, int *i, int *lengthofword, char c)
{
	while ((str[*i] == c) && str[*i])
		(*i)++;
	*lengthofword = 0;
	while (!(str[*i] == c) && str[*i])
	{
		(*lengthofword)++;
		(*i)++;
	}
}

char		**ft_split(char *str, char c)
{
	int i;
	int j;
	char**out;
	int lengthofword;

	j = 0;
	i = 0;
	if (!str || !(out = (char**)malloc((numwords(str, c) + 1) * sizeof(char*))))
		return (0);
	while (str[i])
	{
		oneword(str, &i, &lengthofword, c);
		if (lengthofword)
		{
			if (!(out[j] = (char*)malloc((lengthofword + 1) * sizeof(char))))
				return (free_mem(out));
			ft_strlcpy(out[j++], &str[i - lengthofword], lengthofword + 1);
		}
	}
	out[j] = 0;
	return (out);
}
