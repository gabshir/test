/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logik2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabshire <gabshire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 16:05:32 by gabshire          #+#    #+#             */
/*   Updated: 2019/03/21 16:05:32 by gabshire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"

void	minias(t_m *l, int len, int max)
{
	if (len == 3 && l->arr1[0] == max)
	{
		ft_pb(l);
		ft_pb(l);
		ft_sb(l);
		ft_pa(l);
		ft_sa(l);
		ft_pa(l);
		if (l->arr1[0] > l->arr1[1] && l->arr2[0] < l->arr2[1])
			ft_ss(l);
		else if (l->arr1[0] > l->arr1[1])
			ft_sa(l);
	}
	else if (len == 3 && l->arr1[1] == max)
	{
		ft_pb(l);
		ft_sa(l);
		ft_pa(l);
		if (l->arr1[0] > l->arr1[1] && l->arr2[0] < l->arr2[1])
			ft_ss(l);
		else if (l->arr1[0] > l->arr1[1])
			ft_sa(l);
	}
}

void	minia(t_m *l, int len)
{
	int max;

	max = ft_max(l->arr1, len);
	if (ft_ocenka(l->arr1, l->k1) == 0)
		return ;
	if (len == 2)
	{
		if (l->arr1[0] > l->arr1[1] && l->arr2[0] < l->arr2[1])
			ft_ss(l);
		else if (l->arr1[0] > l->arr1[1])
			ft_sa(l);
	}
	else if (len == 3)
		minias(l, len, max);
}

void	minib(t_m *l, int len)
{
	int max;

	max = ft_max(l->arr2, len);
	if (len == 3 && l->arr2[2] == max)
	{
		if (l->arr2[0] < l->arr2[1])
			ft_sb(l);
		ft_pa(l);
		ft_sb(l);
		ft_pa(l);
		ft_sa(l);
		ft_pa(l);
	}
	else if (len == 3 && l->arr2[1] == max)
	{
		ft_sb(l);
		ft_pa(l);
		if (l->arr2[0] < l->arr2[1])
			ft_sb(l);
		ft_pa(l);
		ft_pa(l);
	}
}

void	ft_starta(t_m *l, int *len, t_sb *k)
{
	k->max = ft_max(l->arr1, l->k1);
	while (l->arr1[l->k1 - 1] != k->max)
		ft_rra(l);
	k->max = ft_max(l->arr1, len[0]);
	while (l->arr1[len[0] - 1] == k->max && len[0] > 1)
	{
		len[0]--;
		k->max = ft_max(l->arr1, len[0]);
	}
	if (len[0] < 4)
	{
		minia(l, len[0]);
		len[0] = 0;
	}
	if (ft_ocenka(l->arr1, l->k1) == 0)
		return ;
	k->med = ft_mediana(l->arr1, len[0]);
	k->r = counter(l->arr1, len[0], k->med);
	k->o = len[0] - k->r;
	k->s = 0;
	k->max = ft_max(l->arr1, len[0]);
}

void	ft_optima(t_m *l, t_sb *k, int f, int len)
{
	if (f == 0)
	{
		if (l->arr2[0] < l->arr2[1] && l->arr1[0] > l->arr1[1]
		&& k->r > 0 && k->r < 12)
			ft_ss(l);
		if (l->arr1[0] == k->max && k->o == 1 && l->arr1[0] > l->arr1[1])
		{
			ft_sa(l);
			k->max = ft_max(l->arr1, len);
		}
	}
	if (f == 1)
	{
		ft_pb(l);
		if (l->arr2[0] < l->arr2[1] && l->arr1[0] > l->arr1[1]
		&& k->r > 0 && k->r < 12)
			ft_ss(l);
		if (l->arr2[0] < l->arr2[1] && k->r > 0 && k->r < 12)
			ft_sb(l);
		k->o--;
	}
}
