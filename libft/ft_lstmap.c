/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgertrud <msnazarow@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/20 18:00:08 by sgertrud          #+#    #+#             */
/*   Updated: 2020/05/21 07:48:45 by sgertrud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list *out;
	t_list *out_temp;

	if (!lst || !f || !del ||
	!(out = ft_lstnew(f(lst->content))))
	{
		ft_lstclear(&out, del);
		return (0);
	}
	out_temp = out;
	while ((lst = lst->next))
	{
		if (!(out->next = ft_lstnew(f(lst->content))))
		{
			ft_lstclear(&out_temp, del);
			return (0);
		}
		out = out->next;
	}
	return (out_temp);
}
