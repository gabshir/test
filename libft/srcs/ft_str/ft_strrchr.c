/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabshire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 14:22:21 by gabshire          #+#    #+#             */
/*   Updated: 2018/12/05 20:36:22 by gabshire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

char	*ft_strrchr(const char *str, int ch)
{
	int		i;
	char	*s;

	i = 0;
	s = (char*)str;
	while (s[i])
	{
		i++;
	}
	if (ch == 0)
		return (s + i);
	while (i >= 0)
	{
		if ((char)ch == s[i])
			return (s + i);
		i--;
	}
	return (NULL);
}
