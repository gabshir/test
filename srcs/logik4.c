/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logik4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabshire <gabshire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 16:06:47 by gabshire          #+#    #+#             */
/*   Updated: 2019/03/21 16:06:47 by gabshire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"

void	ft_inclogik(t_m *l, t_o *tr)
{
	tr->med = ft_mediana(l->arr2, tr->len);
	tr->len = counter(l->arr2, tr->len, tr->med);
	tr->t = tr->len;
	tr->rotate = 0;
	tr->f = 0;
	while (l->arr2[l->k2 - 1] > tr->med && l->k2 > 1)
		ft_rrb(l);
}

void	ft_optim(t_m *l, t_o *tr)
{
	if (l->arr1[0] > l->arr1[1] && l->arr2[0] < l->arr2[1])
		ft_ss(l);
	tr->max = ft_max(l->arr2, l->k2);
	if (l->arr2[0] == tr->max && tr->f == 1 && l->arr2[0] > l->arr1[0])
	{
		ft_pa(l);
		ft_sa(l);
		tr->len--;
		tr->f = 0;
	}
}

void	ft_cycleb(t_m *l, t_o *tr)
{
	ft_inclogik(l, tr);
	while (tr->len > 0)
	{
		ft_optim(l, tr);
		if (l->arr2[0] >= tr->med)
		{
			if (l->arr2[0] != tr->max)
				tr->f++;
			ft_pa(l);
			tr->len--;
		}
		else
		{
			ft_rb(l);
			tr->rotate++;
		}
	}
	if (tr->t > 1)
		ft_sbora(l, tr->t);
}

void	ft_transform(t_m *l)
{
	t_o tr;

	tr.rotate = 0;
	while (l->k2 > 0)
	{
		ft_start(l, &tr);
		ft_rotate(l, &tr);
		if (l->k2 == 0)
			return ;
		tr.len = ft_len(l->arr2, l->k2, tr.max);
		while (ft_sizeblok(l, tr.len) == 1 && tr.len < l->k2)
			tr.len++;
		if ((l->arr2[l->k2 - 1] == tr.max && l->k2 > 1)
			|| (tr.len >= 0 && tr.len < 4))
			ft_perenos(l, &tr);
		else
			ft_cycleb(l, &tr);
	}
}
