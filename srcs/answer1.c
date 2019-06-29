/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   answer1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabshire <gabshire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 16:03:46 by gabshire          #+#    #+#             */
/*   Updated: 2019/03/21 16:03:46 by gabshire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"

int		counter(const int *arr, int i, int med)
{
	int		l;
	int		s;

	l = 0;
	s = 0;
	while (l < i)
	{
		if (arr[l] >= med)
			s++;
		l++;
	}
	return (s);
}

int		ft_len(const int *arr, int len, int max)
{
	int		i;
	int		f;

	i = 0;
	f = 0;
	while (arr[i] != max && len > 0)
	{
		i++;
		len--;
		f = 1;
	}
	if (f == 1)
		return (i + 1);
	return (i);
}

int		ft_sizeblok(t_m *l, int len)
{
	int		*temp;
	int		*sort;
	int		i;

	i = l->k2;
	if (len == 0)
		return (0);
	temp = ft_sort(l->arr2, len);
	sort = ft_sort(l->arr2, l->k2);
	while (len > 0 && len < l->k2 && l->k2 > 0)
	{
		if (temp[len - 1] != sort[i - 1])
		{
			free(temp);
			free(sort);
			return (1);
		}
		len--;
		i--;
	}
	free(temp);
	free(sort);
	return (0);
}

int		ft_mediana(int *arr, int len)
{
	int		*temp;
	int		s;

	s = 0;
	temp = ft_sort(arr, len);
	if (len == 0)
		s = temp[0];
	else
		s = temp[len / 2];
	free(temp);
	temp = NULL;
	return (s);
}
