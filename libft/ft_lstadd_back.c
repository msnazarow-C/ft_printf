/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgertrud <msnazarow@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 00:37:58 by sgertrud          #+#    #+#             */
/*   Updated: 2020/05/22 10:58:10 by sgertrud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
