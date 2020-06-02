/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgertrud <msnazarow@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/29 12:21:57 by sgertrud          #+#    #+#             */
/*   Updated: 2020/06/02 17:12:07 by sgertrud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static int	check(int fd, char **line)
{
	char test;

	if (!line || fd < 0 || read(fd, &test, 0) < 0 || BUFFER_SIZE <= 0)
		return (-1);
	return (0);
}

static int	get_line(int fd, char **reminder, char **line)
{
	char		*buf;

	*line = reminder[fd + 1];
	if (!(reminder[fd + 1] = ft_memchr(*line, '\n', ft_strlen(*line))))
		if (!(buf = (char*)malloc(BUFFER_SIZE + 1)))
			return (-1);
	if (!reminder[fd + 1])
	{
		while (!reminder[fd + 1] && !(buf[read(fd, buf, BUFFER_SIZE)] = 0))
		{
			*line = ft_strjoin(*line, buf);
			if (!ft_strlen(buf))
			{
				free(buf);
				free(reminder[fd + 1]);
				reminder[fd + 1] = 0;
				return (0);
			}
			reminder[fd + 1] = ft_memchr(*line, '\n', ft_strlen(*line));
		}
		free(buf);
	}
	*(reminder[fd + 1]) = 0;
	return ((reminder[fd + 1] = ft_strjoin(NULL, reminder[fd + 1] + 1)) != 0);
}

int			remfree(char ***reminder)
{
	int i;
	int flag;

	flag = 1;
	i = 0;
	if (*reminder)
	{
		while (++i <= (long)**reminder)
		{
			if ((*reminder)[i])
			{
				flag = 0;
				break ;
			}
		}
	}
	if (flag)
	{
		free(*reminder);
		*reminder = 0;
	}
	return (1);
}

int			get_next_line(int fd, char **line)
{
	static char	**reminder;
	int			out;

	if (check(fd, line) == -1)
	{
		if (reminder && fd < (long)reminder[0])
		{
			free(reminder[fd + 1]);
			reminder[fd + 1] = 0;
			remfree(&reminder);
		}
		return (-1);
	}
	if (!reminder || fd >= (long)reminder[0])
	{
		if (!(reminder = ft_realloc(reminder, reminder ? (long)reminder[0] + 1 :
		FD + 1, fd + 10)))
			return (-1);
		reminder[0] = (char*)((long)fd + 9);
		reminder[fd + 1] = 0;
	}
	out = get_line(fd, reminder, line);
	remfree(&reminder);
	return (out);
}
