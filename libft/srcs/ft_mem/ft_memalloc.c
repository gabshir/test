/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabshire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 13:23:48 by gabshire          #+#    #+#             */
/*   Updated: 2018/11/30 06:17:03 by gabshire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_memalloc(size_t size)
{
	size_t			i;
	void			*memalloc;
	unsigned char	*z;

	i = 0;
	memalloc = malloc(size);
	if (memalloc == NULL)
		return (NULL);
	z = (unsigned char*)memalloc;
	while (i < size)
	{
		z[i] = 0;
		i++;
	}
	return (z);
}
