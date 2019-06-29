/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maindop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabshire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 12:31:12 by gabshire          #+#    #+#             */
/*   Updated: 2019/03/26 13:25:45 by gabshire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"

void	ft_error(t_m *l)
{
	int i;

	i = 0;
	write(2, "Error\n", 6);
	free(l->arr1);
	free(l->arr2);
	while (l->m[i])
	{
		free(l->m[i]);
		i++;
	}
	free(l->m);
	free(l);
	exit(1);
}

void	ft_proverka(const char *str, t_m *l)
{
	int i;
	int f;

	i = 0;
	f = 0;
	while (str[i])
	{
		if ((str[i] < '0' || str[i] > '9') && str[i] != '-' && str[i] != '+')
		{
			f = 1;
			break ;
		}
		i++;
	}
	if ((i == 1 && (str[0] == '-' || str[0] == '+')) || i == 0
		|| i > 11 || f == 1 || l->f == 1)
		ft_error(l);
}

int		ft_miniatoi(const char *str, int *z)
{
	int			i;
	long int	s;
	int			f;

	i = 0;
	s = 0;
	f = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		i++;
		if (str[i - 1] == '-')
			f = 1;
	}
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		s = s * 10 + str[i] - '0';
		i++;
	}
	if (f == 1)
		s = -s;
	if (s > 2147483647 || s < -2147483648)
		z[0] = 1;
	return (int)(s);
}

void	ft_dubly(t_m *l, int f)
{
	int i;
	int j;

	i = 0;
	if (f == 1)
		ft_error(l);
	while (i < l->k1 - 1)
	{
		j = i + 1;
		while (j < l->k1)
		{
			if (l->arr1[i] == l->arr1[j])
				ft_error(l);
			j++;
		}
		i++;
	}
}
