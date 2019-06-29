/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpush.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwillem- <jwillem-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 16:21:12 by wballaba          #+#    #+#             */
/*   Updated: 2019/03/29 21:04:41 by jwillem-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstpush(t_list **alst, t_list *new)
{
	t_list *list;

	if (new != NULL)
	{
		if (alst && *alst)
		{
			list = *alst;
			while (list != NULL)
			{
				if (list->next)
					list = list->next;
				else
				{
					list->next = new;
					break ;
				}
			}
		}
		else
			*alst = new;
	}
}
