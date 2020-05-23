/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgertrud <msnazarow@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/22 18:50:34 by sgertrud          #+#    #+#             */
/*   Updated: 2020/05/23 06:16:48 by sgertrud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	check_end_line(char *line)
{
	while (*line)
		if (!*line++)
			return (0);
}

int	get_next_line(int fd, char **line)
{
	t_list	t_temp;
	char *	s_temp;


	#ifdef BUFFER
		s_temp = (char*)malloc(BUFFER + 1);
		temp = ft_create_elem(s_temp,read(fd,s_temp,BUFFER);)

		read(fd,)
		while (check_end_line(*line))
		{

		}
	#endif
}

int	main()
{
	int file;
	char *line;

	line = "";
	file = open("test.txt",O_RDWR);
	while (line)
	{
		get_next_line(file,&line);
	}
	return 0;
}