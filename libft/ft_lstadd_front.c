/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgertrud <msnazarow@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 03:31:03 by sgertrud          #+#    #+#             */
/*   Updated: 2020/05/22 10:58:32 by sgertrud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **list, t_list *new)
{
	t_list *pointer;

	if (!list || !new)
		return ;
	if (*list)
	{
		pointer = new;
		pointer->next = *list;
		*list = pointer;
	}
	else
		*list = new;
}
