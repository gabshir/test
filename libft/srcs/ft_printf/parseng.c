/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parseng.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabshire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 16:54:30 by gabshire          #+#    #+#             */
/*   Updated: 2019/02/21 16:54:32 by gabshire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_bonusts(t_format *mod, va_list arg, int f, int i)
{
	int s;

	i++;
	s = 0;
	s = va_arg(arg, int);
	if (f == 0)
	{
		if (s < 0)
			return (i);
		mod->t = s;
		mod->st = 1;
		return (i);
	}
	if (s < 0)
	{
		s = -s;
		mod->m = 1;
	}
	mod->hp = s;
	mod->hps = 1;
	return (i);
}

int			ft_h(int i, t_format *mod, const char *str, va_list arg)
{
	int s;
	int k;

	s = 0;
	k = i;
	if (str[i] && str[i] == '*')
		return (ft_bonusts(mod, arg, 1, i));
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		s = s * 10 + str[i] - '0';
		i++;
	}
	if (i > k)
	{
		mod->hps = 1;
		mod->hp = s;
	}
	return (i);
}

int			ft_t(int i, t_format *mod, const char *str, va_list arg)
{
	int s;
	int k;

	s = 0;
	k = i;
	if (str[i] && str[i] == '.')
		i++;
	if (str[i] && str[i] == '*')
		return (ft_bonusts(mod, arg, 0, i));
	if (str[i] && str[i] == '-')
	{
		i++;
		mod->m = 1;
	}
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		s = s * 10 + str[i] - '0';
		i++;
	}
	if (i > k)
	{
		mod->st = 1;
		mod->t = s;
	}
	return (i);
}

int			ft_flag(int i, t_format *mod, const char *str)
{
	while (str[i] && (str[i] == '-' || str[i] == '+'
	|| str[i] == ' ' || str[i] == '#' || str[i] == '0'))
	{
		if (str[i] == '-')
			mod->m = 1;
		if (str[i] == '+')
			mod->pl = 1;
		if (str[i] == ' ')
			mod->pr = 1;
		if (str[i] == '#')
			mod->o = 1;
		if (str[i] == '0')
			mod->z = 1;
		i++;
	}
	return (i);
}

int			ft_cheakp(const char *str, int i, int *d)
{
	int s;
	int f;

	s = 0;
	f = 0;
	while (str[i] && str[i] == '%')
	{
		s++;
		i++;
		f = 2;
	}
	while (s >= 2)
	{
		ft_putchar('%');
		d[0]++;
		s = s - 2;
		f = 1;
	}
	if (f == 1 || f == 0)
		return (i);
	return (i - 1);
}
