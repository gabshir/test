/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabshire <gabshire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 16:07:00 by gabshire          #+#    #+#             */
/*   Updated: 2019/03/21 21:44:46 by gabshire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"

void	ft_sa(t_m *l)
{
	int t;

	if (l->k1 < 2)
		return ;
	t = l->arr1[1];
	l->arr1[1] = l->arr1[0];
	l->arr1[0] = t;
	l->kol++;
	if (l->c == 0)
		ft_printf("sa\n");
	print_stack(l);
}

void	ft_sb(t_m *l)
{
	int t;

	if (l->k2 < 2)
		return ;
	t = l->arr2[1];
	l->arr2[1] = l->arr2[0];
	l->arr2[0] = t;
	l->kol++;
	if (l->c == 0)
		ft_printf("sb\n");
	print_stack(l);
}

void	ft_ss(t_m *l)
{
	int t;

	if (l->k1 < 2 || l->k2 < 2)
		return ;
	t = l->arr1[1];
	l->arr1[1] = l->arr1[0];
	l->arr1[0] = t;
	t = l->arr2[1];
	l->arr2[1] = l->arr2[0];
	l->arr2[0] = t;
	l->kol++;
	if (l->c == 0)
		ft_printf("ss\n");
	print_stack(l);
}
