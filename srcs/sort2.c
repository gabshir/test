/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabshire <gabshire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 16:07:11 by gabshire          #+#    #+#             */
/*   Updated: 2019/03/21 20:32:34 by gabshire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"

void	ft_rra(t_m *l)
{
	int k;
	int m;

	if (l->k1 < 2)
		return ;
	m = l->k1 - 1;
	k = l->arr1[m];
	while (m > 0)
	{
		l->arr1[m] = l->arr1[m - 1];
		m--;
	}
	l->arr1[0] = k;
	l->kol++;
	if (l->c == 0)
		ft_printf("rra\n");
	print_stack(l);
}

void	ft_rrb(t_m *l)
{
	int k;
	int m;

	if (l->k2 < 2)
		return ;
	m = l->k2 - 1;
	k = l->arr2[m];
	while (m > 0)
	{
		l->arr2[m] = l->arr2[m - 1];
		m--;
	}
	l->arr2[0] = k;
	l->kol++;
	if (l->c == 0)
		ft_printf("rrb\n");
	print_stack(l);
}

void	ft_rrr(t_m *l)
{
	int k;
	int m;

	if (l->k1 < 2 || l->k2 < 2)
		return ;
	m = l->k1 - 1;
	k = l->arr1[m];
	while (m > 0)
	{
		l->arr1[m] = l->arr1[m - 1];
		m--;
	}
	l->arr1[0] = k;
	m = l->k2 - 1;
	k = l->arr2[m];
	while (m > 0)
	{
		l->arr2[m] = l->arr2[m - 1];
		m--;
	}
	l->arr2[0] = k;
	l->kol++;
	if (l->c == 0)
		ft_printf("rrr\n");
	print_stack(l);
}
