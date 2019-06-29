/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabshire <gabshire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 16:07:00 by gabshire          #+#    #+#             */
/*   Updated: 2019/03/21 21:44:46 by gabshire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"

void	ft_pa(t_m *l)
{
	t_com z;

	if (l->k2 == 0)
		return ;
	z.k = l->k1;
	z.k1 = l->k2;
	l->k1++;
	l->k2--;
	while (z.k >= 0)
	{
		l->arr1[z.k + 1] = l->arr1[z.k];
		z.k--;
	}
	l->arr1[0] = l->arr2[0];
	z.i = 0;
	while (z.i < z.k1)
	{
		l->arr2[z.i] = l->arr2[z.i + 1];
		z.i++;
	}
	l->kol++;
	if (l->c == 0)
		ft_printf("pa\n");
	print_stack(l);
}

void	ft_pb(t_m *l)
{
	t_com z;

	if (l->k1 == 0)
		return ;
	z.k = l->k2;
	z.k1 = l->k1;
	l->k2++;
	l->k1--;
	while (z.k >= 0)
	{
		l->arr2[z.k + 1] = l->arr2[z.k];
		z.k--;
	}
	l->arr2[0] = l->arr1[0];
	z.i = 0;
	while (z.i < z.k1)
	{
		l->arr1[z.i] = l->arr1[z.i + 1];
		z.i++;
	}
	l->kol++;
	if (l->c == 0)
		ft_printf("pb\n");
	print_stack(l);
}

void	ft_ra(t_m *l)
{
	int i;
	int t;

	if (l->k1 == 0)
		return ;
	t = l->arr1[0];
	i = 0;
	while (i + 1 < l->k1)
	{
		l->arr1[i] = l->arr1[i + 1];
		i++;
	}
	l->arr1[i] = t;
	l->kol++;
	if (l->c == 0)
		ft_printf("ra\n");
	print_stack(l);
}

void	ft_rb(t_m *l)
{
	int i;
	int t;

	if (l->k2 == 0)
		return ;
	t = l->arr2[0];
	i = 0;
	while (i + 1 < l->k2)
	{
		l->arr2[i] = l->arr2[i + 1];
		i++;
	}
	l->arr2[i] = t;
	l->kol++;
	if (l->c == 0)
		ft_printf("rb\n");
	print_stack(l);
}

void	ft_rr(t_m *l)
{
	int i;
	int t;

	if (l->k1 < 0 || l->k2 < 0)
		return ;
	t = l->arr1[0];
	i = 0;
	while (i + 1 < l->k1)
	{
		l->arr1[i] = l->arr1[i + 1];
		i++;
	}
	l->arr1[i] = t;
	t = l->arr2[0];
	i = 0;
	while (i + 1 < l->k2)
	{
		l->arr2[i] = l->arr2[i + 1];
		i++;
	}
	l->arr2[i] = t;
	l->kol++;
	if (l->c == 0)
		ft_printf("rr\n");
	print_stack(l);
}
