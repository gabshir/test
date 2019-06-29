/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabshire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 08:43:28 by gabshire          #+#    #+#             */
/*   Updated: 2018/12/06 14:41:54 by gabshire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <unistd.h>

static	void	ft_put(char c)
{
	write(1, &c, 1);
}

void			ft_putnbr(int n)
{
	long int s;

	s = n;
	if (s < 0)
	{
		ft_put('-');
		s = -s;
	}
	if (s >= 10)
	{
		ft_putnbr(s / 10);
		ft_putnbr(s % 10);
	}
	else
		ft_put(s + '0');
}
