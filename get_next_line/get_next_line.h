/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgertrud <msnazarow@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/29 12:27:18 by sgertrud          #+#    #+#             */
/*   Updated: 2020/06/01 09:14:52 by sgertrud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 128
# endif
# define FD 4

int		get_next_line(int fd, char **line);
char	*ft_strjoin(char const *s1, char const *s2);
void	*ft_memchr(const void *s, int c, size_t n);
size_t	ft_strlen(const char *s);
void	ft_bzero(void *s, size_t n);
char	**ft_realloc(char **data, size_t len, size_t newlen);
#endif
