/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itua_e.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabshire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 09:26:11 by gabshire          #+#    #+#             */
/*   Updated: 2019/02/21 09:26:16 by gabshire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	ft_kols(unsigned long long i)
{
	size_t k;

	k = 0;
	if (i == 0)
		return (1);
	while (i > 0)
	{
		i = i / 8;
		k++;
	}
	return (k);
}

char			*ft_ie(unsigned long long int i)
{
	size_t	k;
	char	*str;

	k = ft_kols(i);
	if (!(str = (char *)malloc(sizeof(char) * k + 1)))
		return (NULL);
	str[k--] = '\0';
	if (i == 0)
		str[0] = '0';
	while (i > 0)
	{
		str[k] = i % 8 + '0';
		k--;
		i = i / 8;
	}
	return (str);
}

char			*ft_odf(double k)
{
	if (k != k)
		return (ft_strdup("nan"));
	if (k == k + k / 0. && k < 0)
		return (ft_strdup("-inf"));
	if (k == k + k / 0. && k > 0)
		return (ft_strdup("inf"));
	return (NULL);
}
