/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabshire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 16:18:29 by gabshire          #+#    #+#             */
/*   Updated: 2018/12/07 14:44:49 by gabshire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

static	void	ft_put_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void			ft_putnbr_fd(int n, int fd)
{
	long int s;

	s = n;
	if (s < 0)
	{
		ft_put_fd('-', fd);
		s = -s;
	}
	if (s >= 10)
	{
		ft_putnbr_fd(s / 10, fd);
		ft_putnbr_fd(s % 10, fd);
	}
	else
		ft_put_fd(s + '0', fd);
}
