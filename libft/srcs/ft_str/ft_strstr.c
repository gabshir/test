/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabshire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 13:52:28 by gabshire          #+#    #+#             */
/*   Updated: 2018/12/06 14:12:55 by gabshire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

static	int	ft_len(const char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char		*ft_strstr(const char *strb, const char *stra)
{
	size_t	i;
	size_t	j;
	size_t	r;

	i = 0;
	j = 0;
	r = 0;
	if (ft_len(stra) == 0)
		return ((char*)strb);
	r = ft_len(stra);
	while (strb[i])
	{
		j = 0;
		while (stra[j])
		{
			if (strb[i + j] == stra[j])
				j++;
			else
				break ;
			if (r == j)
				return ((char*)strb + i + j - r);
		}
		i++;
	}
	return (NULL);
}
