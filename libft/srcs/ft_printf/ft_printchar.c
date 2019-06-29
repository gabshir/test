/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printchar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabshire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 09:26:24 by gabshire          #+#    #+#             */
/*   Updated: 2019/02/21 09:26:28 by gabshire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_printcharm(t_format *mod, char c)
{
	int d;

	d = 0;
	ft_putchar(c);
	if (mod->hp > 1)
		mod->hp--;
	while (mod->hp > 0)
	{
		d++;
		ft_putchar(' ');
		mod->hp--;
	}
	return (d + 1);
}

static int	ft_printcharmnull(t_format *mod, char c)
{
	int d;

	d = 0;
	if (mod->hp > 1)
		mod->hp--;
	if (mod->z == 1 && mod->m == 0)
	{
		while (mod->hp > 0)
		{
			d++;
			ft_putchar('0');
			mod->hp--;
		}
	}
	else
	{
		while (mod->hp > 0)
		{
			d++;
			ft_putchar(' ');
			mod->hp--;
		}
	}
	ft_putchar(c);
	return (d + 1);
}

int			ft_printchar(va_list arg, t_format *mod)
{
	int		d;
	char	c;

	c = 0;
	d = 0;
	c = va_arg(arg, int);
	if (mod->m == 1)
		d = ft_printcharm(mod, c);
	else
		d = ft_printcharmnull(mod, c);
	return (d);
}
