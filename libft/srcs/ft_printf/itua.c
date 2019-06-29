/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itua.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabshire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 09:29:42 by gabshire          #+#    #+#             */
/*   Updated: 2019/02/21 09:29:45 by gabshire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t		ft_razrco(long long int *i, size_t *f)
{
	size_t			l;
	long long int	k;

	l = 0;
	if (i[0] < 0)
	{
		f[0] = 1;
		if (i[0] == LLONG_MIN)
		{
			i[0] = -9223372036854775807;
			f[0] = 2;
		}
		i[0] = -i[0];
		l++;
	}
	k = i[0];
	if (k == 0)
		return (1);
	while (k > 0)
	{
		k = k / 10;
		l++;
	}
	return (l);
}

char				*ft_itoao(long long int i)
{
	t_itua r;

	r.f = 0;
	r.k = ft_razrco(&i, &r.f);
	if (!(r.str = (char *)malloc(sizeof(char) * r.k + 1)))
		return (NULL);
	r.str[r.k--] = '\0';
	if (r.f > 0)
		r.str[0] = '-';
	if (i == 0)
		r.str[0] = '0';
	while (i > 0)
	{
		r.str[r.k] = i % 10 + '0';
		if (r.f == 2)
		{
			r.str[r.k] = i % 10 + '0' + 1;
			r.f = 0;
		}
		r.k--;
		i = i / 10;
	}
	return (r.str);
}

static size_t		ft_razrcu(unsigned long long int i)
{
	size_t l;

	l = 0;
	if (i == 0)
		return (1);
	while (i > 0)
	{
		i = i / 10;
		l++;
	}
	return (l);
}

char				*ft_itoau(unsigned long long int i)
{
	t_itua r;

	r.k = ft_razrcu(i);
	if (!(r.str = (char *)malloc(sizeof(char) * r.k + 1)))
		return (NULL);
	r.str[r.k--] = '\0';
	if (i == 0)
		r.str[0] = '0';
	while (i > 0)
	{
		r.str[r.k] = i % 10 + '0';
		r.k--;
		i = i / 10;
	}
	return (r.str);
}
