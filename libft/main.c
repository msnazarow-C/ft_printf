/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgertrud <msnazarow@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 15:16:21 by jtoty             #+#    #+#             */
/*   Updated: 2020/05/21 07:57:27 by sgertrud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include <unistd.h>
#include <string.h>
#include "stdio.h"

int main()
{
char *data = "hello, i'm a data";
        t_list *l = ft_lstnew(data);

        if (!ft_strncmp(data, l->content,30))
                printf("TEST_SUCCESS");
		else
        printf("TEST_FAILED");
}
