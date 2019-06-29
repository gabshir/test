/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logik3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabshire <gabshire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 16:06:10 by gabshire          #+#    #+#             */
/*   Updated: 2019/03/26 13:14:09 by gabshire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"

void	lasta(t_m *l, t_sb *k, int len)
{
	k->max = ft_max(l->arr1, l->k1);
	while (l->arr1[l->k1 - 1] != k->max)
		ft_rra(l);
	minia(l, len);
	if (l->arr1[0] > l->arr1[1])
		ft_sa(l);
}

void	ft_sbora(t_m *l, int len)
{
	t_sb k;

	while (len > 3)
	{
		ft_starta(l, &len, &k);
		if (ft_ocenka(l->arr1, l->k1) == 0)
			return ;
		while (k.o > 0)
		{
			ft_optima(l, &k, 0, len);
			if (l->arr1[0] >= k.med)
			{
				ft_ra(l);
				k.s++;
			}
			else
				ft_optima(l, &k, 1, len);
		}
		len = k.r;
	}
	lasta(l, &k, len);
}

void	ft_start(t_m *l, t_o *tr)
{
	tr->max = 0;
	tr->len = 0;
	tr->max = ft_max(l->arr2, l->k2);
	tr->len = ft_len(l->arr2, l->k2, tr->max);
	while (ft_sizeblok(l, tr->len) == 1)
		tr->len++;
	while (tr->len == 2 && l->k2 > 0)
	{
		ft_sb(l);
		ft_pa(l);
		tr->max = ft_max(l->arr2, l->k2);
		tr->len = ft_len(l->arr2, l->k2, tr->max);
	}
}

void	ft_rotate(t_m *l, t_o *tr)
{
	while (tr->len > l->k2 / 2 && tr->rotate > 0 && l->k2 > 0
		&& l->k2 > 10 && tr->rotate < l->k2 / 2)
	{
		ft_rrb(l);
		tr->rotate--;
		while (l->arr2[0] == tr->max && l->k2 > 0)
		{
			ft_pa(l);
			if (tr->rotate > 0 || l->arr2[l->k2 - 1] == tr->max)
				ft_rrb(l);
			tr->rotate--;
			if (l->k2 > 0)
				tr->max = ft_max(l->arr2, l->k2);
		}
	}
}

void	ft_perenos(t_m *l, t_o *tr)
{
	if (l->arr2[l->k2 - 1] == tr->max && l->k2 > 1)
	{
		ft_rrb(l);
		ft_pa(l);
		if (tr->rotate > 0)
			tr->rotate--;
	}
	else if (tr->len == 0 && l->k2 > 0)
		ft_pa(l);
	else if (tr->len == 2)
	{
		ft_pa(l);
		ft_pa(l);
		if (l->arr2[0] < l->arr2[1])
			ft_ss(l);
		else
			ft_sa(l);
	}
	else if (tr->len == 3)
		minib(l, tr->len);
}
