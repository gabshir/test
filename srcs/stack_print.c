/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabshire <gabshire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 16:07:11 by gabshire          #+#    #+#             */
/*   Updated: 2019/03/21 22:06:06 by gabshire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"

static void	printa(t_m *l, int k)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (k > 0)
	{
		ft_printf("%-d\n", l->arr1[i]);
		k--;
		i++;
	}
	while (i < l->k1 && j < l->k2)
	{
		ft_printf("%-11d\t%-d\n", l->arr1[i], l->arr2[j]);
		i++;
		j++;
	}
}

static void	printb(t_m *l, int k)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (k < 0)
	{
		ft_printf("           \t%-d\n", l->arr2[j]);
		k++;
		j++;
	}
	while (i < l->k1 && j < l->k2)
	{
		ft_printf("%-11d\t%-d\n", l->arr1[i], l->arr2[j]);
		i++;
		j++;
	}
}

void		print_stack(t_m *l)
{
	int	k;

	k = l->k1 - l->k2;
	if (l->f == 0)
	{
		ft_printf("Stack A    \tStack B\n");
		if (k >= 0)
			printa(l, k);
		else
			printb(l, k);
		ft_printf("-----------\t-----------\n");
	}
}
