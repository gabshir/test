/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   answer2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabshire <gabshire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 16:03:46 by gabshire          #+#    #+#             */
/*   Updated: 2019/03/26 17:35:55 by gabshire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"

static void	ft_incnap(t_nap *k, t_m *l)
{
	k->i = 0;
	k->f = 0;
	k->j = 1;
	l->f = 1;
}

char		**copyarr(const int *a, char **b)
{
	char	**copy;
	int		i;

	i = 0;
	copy = NULL;
	if (!(copy = (char **)malloc(sizeof(char *) * (a[0] + 1))))
		return (NULL);
	while (b[i])
	{
		copy[i] = NULL;
		copy[i] = ft_strdup(b[i]);
		i++;
	}
	copy[i] = NULL;
	return (copy);
}

void		transformb(t_m *l, t_nap *k, int *a, char **b)
{
	if ((a[0] == 3 && l->f == 0) || (a[0] == 2 && l->f != 0))
	{
		if (a[0] == 3 && l->f == 0)
			l->m = ft_strsplit(b[2], ' ');
		else if ((a[0] == 2) && l->f != 0)
			l->m = ft_strsplit(b[1], ' ');
		a[0] = 0;
		while (l->m[a[0]])
			a[0]++;
		k->j = 0;
	}
	else
		l->m = copyarr(a, b);
	l->k1 = a[0] - k->j;
}

void		ft_napolnenie(t_m *l, int a, char **b)
{
	t_nap		k;

	ft_incnap(&k, l);
	if (a == 1)
		return ;
	if (a > 1)
	{
		l->f = ft_strcmp(b[1], "-v");
		if (l->f == 0)
			k.j = 2;
	}
	transformb(l, &k, &a, b);
	if (!(l->arr1 = (int *)malloc(sizeof(int) * (a + 1))))
		exit(1);
	if (!(l->arr2 = (int *)malloc(sizeof(int) * (a + 1))))
		exit(1);
	while (k.i < l->k1)
	{
		ft_proverka(l->m[k.j], l);
		l->arr1[k.i++] = ft_miniatoi(l->m[k.j++], &k.f);
	}
	ft_dubly(l, k.f);
}
