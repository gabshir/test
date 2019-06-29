/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabshire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 19:14:32 by gabshire          #+#    #+#             */
/*   Updated: 2018/12/06 14:15:50 by gabshire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

static	int		kolsim(long int i)
{
	int s;

	s = 0;
	if (i < 0)
	{
		s++;
		i = -i;
	}
	while (i /= 10)
		s++;
	return (s);
}

static	char	*ft_str(long int s, int i, int flag)
{
	char	*str;

	if (!(str = (char *)malloc(sizeof(char) * (i + 2))))
		return (NULL);
	str[i + 1] = '\0';
	while (i >= 0)
	{
		if (s >= 9)
		{
			str[i] = s % 10 + '0';
			s = s / 10;
		}
		else
		{
			str[i] = s + '0';
			if (flag == 1)
				str[0] = '-';
			break ;
		}
		i--;
	}
	return (str);
}

char			*ft_itoa(int n)
{
	int			flag;
	int			i;
	long int	l;
	char		*str;

	flag = 0;
	l = n;
	i = kolsim(l);
	if (l < 0)
	{
		flag = 1;
		l = -l;
	}
	str = ft_str(l, i, flag);
	return (str);
}
