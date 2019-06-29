/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabshire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 19:56:51 by gabshire          #+#    #+#             */
/*   Updated: 2019/03/27 19:56:55 by gabshire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"

void		ft_comands(t_m *l, char *line)
{
	if (ft_strcmp(line, "rra") == 0)
		ft_rra(l);
	else if (ft_strcmp(line, "rrb") == 0)
		ft_rrb(l);
	else if (ft_strcmp(line, "rrr") == 0)
		ft_rrr(l);
	else if (ft_strcmp(line, "ra") == 0)
		ft_ra(l);
	else if (ft_strcmp(line, "rb") == 0)
		ft_rb(l);
	else if (ft_strcmp(line, "rr") == 0)
		ft_rr(l);
	else if (ft_strcmp(line, "sa") == 0)
		ft_sa(l);
	else if (ft_strcmp(line, "sb") == 0)
		ft_sb(l);
	else if (ft_strcmp(line, "ss") == 0)
		ft_ss(l);
	else if (ft_strcmp(line, "pa") == 0)
		ft_pa(l);
	else if (ft_strcmp(line, "pb") == 0)
		ft_pb(l);
	else
		ft_error(l);
}

static void	ft_inc(t_m *l)
{
	l->c = 1;
	l->k2 = 0;
	l->kol = 0;
}

static void	freeall(t_m *l)
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
	t_m		*l;
	char	*line;

	if (a == 1)
		return (0);
	if (!(l = (t_m *)malloc(sizeof(t_m))))
		return (1);
	ft_inc(l);
	ft_napolnenie(l, a, b);
	while ((get_next_line(0, &line)) > 0)
	{
		ft_comands(l, line);
		free(line);
		line = NULL;
	}
	if (line != NULL)
		free(line);
	if (ft_ocenka(l->arr1, l->k1) == 0 && l->k2 == 0)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	freeall(l);
	return (0);
}
