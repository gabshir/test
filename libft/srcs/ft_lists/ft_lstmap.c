/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabshire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 17:19:26 by gabshire          #+#    #+#             */
/*   Updated: 2018/12/11 18:34:09 by gabshire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ochistca(t_list *lst)
{
	t_list *new;

	while (lst)
	{
		new = lst->next;
		free(lst);
		lst = new;
	}
}

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*list;

	if (lst)
	{
		list = f(lst);
		new = list;
		while (lst->next)
		{
			lst = lst->next;
			if (!(list->next = f(lst)))
			{
				ochistca(lst);
				return (NULL);
			}
			list = list->next;
		}
		return (new);
	}
	return (NULL);
}
