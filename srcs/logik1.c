/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logik1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabshire <gabshire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 14:57:40 by gabshire          #+#    #+#             */
/*   Updated: 2019/03/26 09:26:09 by gabshire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"

static void	ft_dosa(t_m *l)
{
	if (l->k1 == 3 && ft_ocenka(l->arr1, l->k1) == 1)
	{
		if (l->arr1[0] > l->arr1[2] && l->arr1[2] > l->arr1[1])
			ft_ra(l);
		else if (l->arr1[1] > l->arr1[0] && l->arr1[0] > l->arr1[2])
			ft_rra(l);
		else if (l->arr1[0] > l->arr1[1] && l->arr1[0] < l->arr1[2])
			ft_sa(l);
		else if (l->arr1[0] > l->arr1[1] && l->arr1[1] > l->arr1[2])
		{
			ft_ra(l);
			ft_sa(l);
		}
		else if (l->arr1[1] > l->arr1[0] && l->arr1[2] > l->arr1[0])
		{
			ft_rra(l);
			ft_sa(l);
		}
	}
	else if (l->k1 == 2 && l->arr1[0] > l->arr1[1])
		ft_sa(l);
}

static void	division(t_m *l)
{
	int med;
	int s;
	int *temp;

	if (l->k1 < 4)
		return ;
	temp = ft_sort(l->arr1, l->k1);
	med = temp[l->k1 / 2];
	s = counter(l->arr1, l->k1, med);
	s = l->k1 - s;
	free(temp);
	while (l->arr1[l->k1 - 1] <= med && l->k1 > 1)
		ft_rra(l);
	while (s > 0)
	{
		if (l->arr1[0] >= med && l->k1 > 0)
			ft_ra(l);
		else if (l->arr1[0] < med && l->k1 > 0 && s > 0)
		{
			ft_pb(l);
			s--;
		}
	}
	if (l->k1 > 3)
		division(l);
}

void		ft_sortirovka(t_m *l)
{
	division(l);
	ft_dosa(l);
	ft_transform(l);
}
