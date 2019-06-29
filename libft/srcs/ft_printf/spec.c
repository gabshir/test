/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabshire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 16:54:19 by gabshire          #+#    #+#             */
/*   Updated: 2019/02/21 16:54:23 by gabshire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_specrl(int i, t_format *mod, const char *str)
{
	if (str[i] && str[i] == 'l')
	{
		i++;
		mod->sr[0] = 'l';
		if (str[i] && str[i] == 'l')
		{
			i++;
			mod->sr[1] = 'l';
			return (i);
		}
		else
			return (i);
	}
	return (i);
}

static int	ft_specrh(int i, t_format *mod, const char *str)
{
	if (str[i] && str[i] == 'h')
	{
		i++;
		mod->sr[0] = 'h';
		if (str[i] && str[i] == 'h')
		{
			i++;
			mod->sr[1] = 'h';
			return (i);
		}
		else
			return (i);
	}
	return (i);
}

static int	ft_specrjzl(int i, t_format *mod, const char *str)
{
	if (str[i] && str[i] == 'j')
	{
		mod->sr[0] = 'j';
		return (i + 1);
	}
	if (str[i] && str[i] == 'z')
	{
		mod->sr[0] = 'j';
		return (i + 1);
	}
	if (str[i] && str[i] == 't')
	{
		mod->sr[0] = 't';
		return (i + 1);
	}
	if (str[i] && str[i] == 'L')
	{
		mod->sr[0] = 'L';
		return (i + 1);
	}
	return (i);
}

int			ft_specr(int i, t_format *mod, const char *str)
{
	int k;

	k = 0;
	k = ft_specrl(i, mod, str);
	if (k > i)
		return (k);
	k = ft_specrh(i, mod, str);
	if (k > i)
		return (k);
	k = ft_specrjzl(i, mod, str);
	if (k > i)
		return (k);
	return (i);
}

char		*ft_dobsp(char *str, t_format *mod)
{
	char *sp;
	char *v;

	sp = NULL;
	v = NULL;
	if ((str == NULL || str[0] != ' ') && mod->pr == 1
		&& mod->pl == 0 && mod->tp != 'u')
	{
		sp = ft_strnew(2);
		sp[0] = ' ';
		v = ft_strjoin_mod(sp, str);
		return (v);
	}
	return (str);
}
