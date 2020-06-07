/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgertrud <msnazarow@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/20 18:00:08 by sgertrud          #+#    #+#             */
/*   Updated: 2020/05/23 06:24:18 by sgertrud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*out;
	t_list	*out_temp;
	void	*f_temp;

	f_temp = f(lst->content);
	if (!lst || !f || !del)
		return (0);
	else if (!(out = ft_lstnew(f_temp)))
	{
		del(f_temp);
		return (0);
	}
	out_temp = out;
	f_temp = f(lst->content);
	while ((lst = lst->next))
	{
		if (!(out->next = ft_lstnew(f_temp)))
		{
			del(f_temp);
			ft_lstclear(&out_temp, del);
			return (0);
		}
		out = out->next;
	}
	return (out_temp);
}
