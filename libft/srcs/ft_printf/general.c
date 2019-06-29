/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabshire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 09:29:24 by gabshire          #+#    #+#             */
/*   Updated: 2019/02/21 09:29:27 by gabshire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char			*ft_strjoin_mod(char *str1, char *str2)
{
	char *v;

	v = NULL;
	if (str1 == NULL && str2 == NULL)
		return (NULL);
	if (str1 == NULL && str2 != NULL)
		return (str2);
	if (str1 != NULL && str2 == NULL)
		return (str1);
	v = ft_strjoin(str1, str2);
	free(str1);
	str1 = NULL;
	free(str2);
	str2 = NULL;
	return (v);
}

char			*ft_genspase(size_t i)
{
	char	*str;
	size_t	k;

	k = 0;
	if (!(str = (char *)malloc(sizeof(char) * i + 1)))
		return (NULL);
	while (k < i)
	{
		str[k] = ' ';
		k++;
	}
	str[k] = '\0';
	return (str);
}

char			*ft_genzero(size_t i)
{
	char	*str;
	size_t	k;

	k = 0;
	if (!(str = (char *)malloc(sizeof(char) * i + 1)))
		return (NULL);
	while (k < i)
	{
		str[k] = '0';
		k++;
	}
	str[k] = '\0';
	return (str);
}

static size_t	ft_kols(unsigned long long i)
{
	size_t k;

	k = 0;
	if (i == 0)
		return (1);
	while (i > 0)
	{
		i = i / 16;
		k++;
	}
	return (k);
}

char			*ft_itoam(unsigned long long int i, size_t f)
{
	size_t	k;
	char	*str;
	size_t	t;

	k = ft_kols(i);
	if (f == 0)
		f = 'a';
	else
		f = 'A';
	t = 0;
	str = ft_strnew(k--);
	if (i == 0)
		str[0] = '0';
	while (i > 0)
	{
		t = i % 16;
		if (t > 9)
			str[k] = t - 10 + f;
		else
			str[k] = t + '0';
		k--;
		i = i / 16;
	}
	return (str);
}
