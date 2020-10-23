/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstconcat.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgertrud <msnazarow@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 23:10:59 by sgertrud          #+#    #+#             */
/*   Updated: 2020/10/23 23:19:35 by sgertrud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstconcat(t_list **lst1, t_list **lst2)
{
	t_list	*last;

	if (!*lst1)
	{
		*lst1 = *lst2;
		return ;
	}
	last = ft_lstlast(*lst1);
	last->next = *lst2;
}
