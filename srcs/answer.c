/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   answer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabshire <gabshire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 16:03:27 by gabshire          #+#    #+#             */
/*   Updated: 2019/03/21 16:03:27 by gabshire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"

int	ft_ocenka(const int *arr, int k)
{
	int i;

	i = 0;
	if (k == 0 || k == 1)
		return (0);
	while (i < k - 1)
	{
		if (arr[i] < arr[i + 1])
			i++;
		else
			return (1);
	}
	return (0);
}

int	*ft_copyarr(const int *arr, int k)
{
	int i;
	int *copy;

	i = 0;
	copy = (int *)malloc(sizeof(int) * k + 1);
	while (i < k)
	{
		copy[i] = arr[i];
		i++;
	}
	return (copy);
}

int	*ft_sort(const int *arr, int k)
{
	int i;
	int t;
	int *m;

	i = 0;
	m = ft_copyarr(arr, k);
	while (i < k - 1)
	{
		if (m[i] > m[i + 1])
		{
			t = m[i + 1];
			m[i + 1] = m[i];
			m[i] = t;
			if (i > 2)
				i = i - 2;
			else
				i = 0;
		}
		else
			i++;
	}
	return (m);
}

int	ft_max(const int *arr, int i)
{
	int l;
	int s;

	l = 0;
	s = arr[l];
	while (l < i)
	{
		if (s < arr[l])
			s = arr[l];
		l++;
	}
	return (s);
}
