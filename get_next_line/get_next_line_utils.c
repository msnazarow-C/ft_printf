/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgertrud <msnazarow@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/28 16:36:54 by sgertrud          #+#    #+#             */
/*   Updated: 2020/05/28 16:37:26 by sgertrud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_list	*ft_lstnew(void *content)
{
	t_list *new;

	if (!((new = (t_list*)malloc(sizeof(t_list)))))
		return (0);
	new->content = content;
	new->next = NULL;
	return (new);
}

void	ft_lstadd_back(t_list **list, t_list *new)
{
	t_list *pointer;

	if (!list || !new)
		return ;
	if (*list)
	{
		pointer = (*list);
		while (pointer->next)
			pointer = pointer->next;
		pointer->next = new;
	}
	else
		*list = new;
}
