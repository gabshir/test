/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabshire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 19:55:09 by gabshire          #+#    #+#             */
/*   Updated: 2019/03/27 19:55:13 by gabshire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"

static void	freeallp(t_m *l)
{
	int i;

	i = 0;
	while (l->m[i])
	{
		free(l->m[i]);
		i++;
	}
	free(l->m);
	free(l->arr1);
	free(l->arr2);
	free(l);
}

int			main(int a, char *b[])
{
	t_m	*l;

	if (a == 1)
		return (0);
	if (!(l = (t_m *)malloc(sizeof(t_m))))
		return (1);
	l->m = NULL;
	l->k2 = 0;
	l->kol = 0;
	l->c = 0;
	ft_napolnenie(l, a, b);
	if (ft_ocenka(l->arr1, l->k1) == 0 && l->k2 == 0)
	{
		freeallp(l);
		exit(0);
	}
	ft_sortirovka(l);
	freeallp(l);
	return (0);
}
