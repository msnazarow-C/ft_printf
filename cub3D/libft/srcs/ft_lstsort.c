/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgertrud <msnazarow@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 23:11:52 by sgertrud          #+#    #+#             */
/*   Updated: 2020/10/23 23:12:16 by sgertrud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	move_smallest_before_tmp(t_list *to_move_prev,
		t_list *dest, t_list *dest_prev, t_list **lst)
{
	t_list	*to_move;

	to_move = to_move_prev->next;
	if (dest_prev)
		dest_prev->next = to_move;
	else
		*lst = to_move;
	to_move_prev->next = to_move->next;
	to_move->next = dest;
}

static void	get_smallest(t_list **smallest, t_list **smallest_prev,
		int (*f)(void *content1, void *content2))
{
	t_list	*current;
	t_list	*current_prev;

	current = *smallest;
	current_prev = *smallest_prev;
	while (current)
	{
		if (f((*smallest)->content, current->content))
		{
			*smallest = current;
			*smallest_prev = current_prev;
		}
		current_prev = current;
		current = current->next;
	}
}

void		ft_lstsort(t_list **lst, int (*f)(void *content1, void *content2))
{
	t_list	*smallest;
	t_list	*smallest_prev;
	t_list	*tmp;
	t_list	*tmp_prev;

	tmp = *lst;
	smallest = *lst;
	smallest_prev = NULL;
	tmp_prev = NULL;
	while (tmp)
	{
		smallest = tmp;
		smallest_prev = tmp_prev;
		get_smallest(&smallest, &smallest_prev, f);
		if (tmp == smallest)
		{
			tmp_prev = tmp;
			tmp = tmp->next;
		}
		else
		{
			move_smallest_before_tmp(smallest_prev, tmp, tmp_prev, lst);
			tmp_prev = smallest;
		}
	}
}
