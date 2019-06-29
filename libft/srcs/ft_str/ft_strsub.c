/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabshire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 07:17:21 by gabshire          #+#    #+#             */
/*   Updated: 2018/12/07 15:55:38 by gabshire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*s1;
	unsigned int	j;

	i = 0;
	j = len + start;
	if (!s)
		return (NULL);
	if (start > j)
		return (NULL);
	if (!(s1 = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	while (start < j)
		s1[i++] = s[start++];
	s1[i] = '\0';
	return (s1);
}
