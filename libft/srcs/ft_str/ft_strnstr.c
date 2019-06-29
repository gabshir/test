/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabshire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 13:12:54 by gabshire          #+#    #+#             */
/*   Updated: 2018/11/30 02:26:43 by gabshire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

int		ft_len1(const char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strnstr(const char *strb, const char *stra, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	r;

	i = 0;
	j = 0;
	r = 0;
	if (ft_len1(stra) == 0)
		return ((char*)strb);
	r = ft_len1(stra);
	while (strb[i])
	{
		j = 0;
		while (stra[j])
		{
			if (strb[i + j] == stra[j] && (i + j) < len)
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
