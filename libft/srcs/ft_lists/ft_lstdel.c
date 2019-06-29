/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabshire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 15:12:59 by gabshire          #+#    #+#             */
/*   Updated: 2018/12/10 20:55:56 by gabshire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *alstn;
	t_list *t;

	alstn = *alst;
	while (alstn != NULL)
	{
		t = alstn->next;
		del(alstn, alstn->content_size);
		alstn = t;
	}
	free(alstn);
	*alst = NULL;
}
