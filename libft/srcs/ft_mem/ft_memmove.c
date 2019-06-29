/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabshire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 15:47:53 by gabshire          #+#    #+#             */
/*   Updated: 2018/12/05 18:58:05 by gabshire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

void	*ft_memmove(void *s1, const void *s2, size_t n)
{
	unsigned char	*p1;
	unsigned char	*p2;
	size_t			i;

	i = 0;
	p1 = (unsigned char *)s2;
	p2 = (unsigned char *)s1;
	if (s2 > s1)
	{
		while (i < n)
		{
			*(p2 + i) = *(p1 + i);
			i++;
		}
	}
	else
	{
		while (n > 0)
		{
			n--;
			*(p2 + n) = *(p1 + n);
		}
	}
	return (p2);
}
