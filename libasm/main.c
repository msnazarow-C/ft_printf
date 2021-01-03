/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgertrud <msnazarow@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 22:29:43 by sgertrud          #+#    #+#             */
/*   Updated: 2020/11/04 13:01:19 by sgertrud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "string.h"
#include "stdio.h"
#include "fcntl.h"
#include "errno.h"
#include "test.h"
#include "assert.h"

void	test_write(void)
{
	int			fd;
	int			ret;
	const char	*str1 = "nasmNASMnasmNASMnasmNASMnasm (ft_write) ";
	const char	*str2 = "nasmNASMnasmNASMnasmNASMnasm (   write) ";

	printf("\033[1;32m\n=== ft_write ===\033[0m\n");
	printf("\n\tft_write's => %d\n", (ret = ft_write(1, (void*)str1, 40)));
	printf("\n\twrite's => %d \n\n", (ret = write(1, (void*)str2, 40)));
	fd = open("write.txt", O_CREAT | O_WRONLY | O_TRUNC,
	S_IRWXG | S_IRWXU | S_IRWXO);
	ret = ft_write(fd, (void*)str1, 40);
	printf("\033[33mft_write - good (!check write.txt) =>\033[0m %d\n", ret);
	ret = write(fd, (void*)str2, 40);
	printf("\033[35m   write - good(!check write.txt) =>\033[0m %d\n", ret);
	close(fd);
	ret = write(-1, 0, 40);
	printf("\033[35m   write - bad=> %d && errno:\033[0m %d\n", ret, errno);
	ret = write(1, 0, 40);
	printf("\033[35m   write - bad => %d && errno:\033[0m %d\n", ret, errno);
	errno = 0;
	ret = ft_write(-1, 0, 40);
	printf("\033[33mft_write - bad=> %d && errno:\033[0m %d\n", ret, errno);
	ret = ft_write(1, 0, 40);
	printf("\033[33mft_write - bad=> %d && errno:\033[0m %d\n", ret, errno);
}

void	test_read(void)
{
	int	fd;
	int	ret;
	char*buf;

	errno = 0;
	printf("\033[1;32m\n=== ft_read ===\n\033[0m");
	fd = open("write.txt", O_RDONLY);
	buf = malloc(sizeof(char) * 100);
	buf[40] = 0;
	ret = read(fd, buf, 40);
	printf("\033[35mread:\033[0m\nfd => %d\nret => %d\nbuf => %s\nerrno => %d\
	\n\n", fd, ret, buf, errno);
	ret = read(-1, buf, 40);
	printf("\033[35mread:\033[0m\nfd => %d\nret => %d\nbuf => %s\nerrno => %d\
	\n\n", -1, ret, buf, errno);
	errno = 0;
	close(fd);
	fd = open("write.txt", O_RDONLY);
	printf("\033[33mft_read:\033[0m\nfd => %d\nret => %d\nbuf => %s\nerrno =>\
	%d\n\n", fd, ret = ft_read(fd, buf, 40), buf, errno);
	ret = ft_read(-1, buf, 40);
	printf("\033[33mft_read:\033[0m\nfd => %d\nret => %d\nbuf => %s\nerrno =>\
	%d\n\n", -1, ret, buf, errno);
	free(buf);
	close(fd);
}

int		cmp(int *a, int *b)
{
	return (*a - *b);
}

void	test_list(void)
{
	t_list *list;
	t_list *p;

	list = 0;
	ft_list_push_front(&list, &(int){23});
	ft_list_push_front(&list, &(int){12});
	ft_list_push_front(&list, &(int){12});
	ft_list_push_front(&list, &(int){1});
	ft_list_push_front(&list, &(int){-100});
	ft_list_push_front(&list, &(int){23});
	ft_list_push_front(&list, &(int){213});
	ft_list_push_front(&list, &(int){23});
	p = list;
	printf("before sort\n");
	while ((p = p->next))
		printf("list-elem = %d\n", *(int*)p->content);
	ft_list_sort(&list, cmp);
	printf("after sort and remove if 23\n");
	ft_list_remove_if(&list, &(int){23}, cmp);
	while ((p = list))
	{
		printf("list-elem = %d\n", *(int*)list->content);
		list = list->next;
		free(p);
	}
}

int		main(void)
{
	test_strcmp();
	test_strlen();
	test_strcpy();
	test_write();
	test_read();
	test_strdup();
	printf("\n");
	test_list();
	printf("\n");
	printf("atoi: %d\n", (ft_atoi_base("asdfghjklq", "asdfghjklq")));
	printf("atoi_bonus : %d\n", (ft_atoi_base("12345", "01234567")));
	return (0);
}
