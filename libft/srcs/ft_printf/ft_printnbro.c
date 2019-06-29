/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnbro.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabshire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 09:28:24 by gabshire          #+#    #+#             */
/*   Updated: 2019/02/21 09:28:28 by gabshire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_genspaseo(t_num *p, t_format *mod)
{
	if (mod->o == 0 && p->z == NULL && mod->hp > p->d)
		return (ft_genspase(mod->hp - p->d));
	if (mod->o == 1 && p->z == NULL && mod->hp > p->d + 1)
		return (ft_genspase(mod->hp - p->d - 1));
	if ((mod->o == 0 || (mod->o == 1 && p->z != NULL))
		&& mod->hp > p->d && mod->hp > mod->t)
	{
		if (p->d > mod->t)
			return (ft_genspase(mod->hp - p->d));
		else
			return (ft_genspase(mod->hp - mod->t));
	}
	if (mod->o == 1 && mod->hp > p->d + 1 && mod->hp > mod->t + 1)
	{
		if (p->d > mod->t)
			return (ft_genspase(mod->hp - p->d - 1));
		else
			return (ft_genspase(mod->hp - mod->t - 1));
	}
	return (NULL);
}

static char	*ft_stroka(t_num *p, t_format *mod)
{
	char	*v;
	char	*o;

	p->sp = NULL;
	p->z = NULL;
	v = NULL;
	o = NULL;
	if (mod->t > p->d)
		p->z = ft_genzero(mod->t - p->d);
	p->sp = ft_genspaseo(p, mod);
	if (mod->o == 1 && p->z == NULL)
	{
		o = ft_strnew(2);
		o[0] = '0';
	}
	if (mod->m == 1)
	{
		v = ft_strjoin_mod(p->z, p->s);
		v = ft_strjoin_mod(o, v);
		return (ft_strjoin_mod(v, p->sp));
	}
	v = ft_strjoin_mod(p->z, p->s);
	v = ft_strjoin_mod(o, v);
	return (ft_strjoin_mod(p->sp, v));
}

static void	ft_inc(t_num *p, char *str, t_format *mod)
{
	p->sp = NULL;
	p->z = NULL;
	p->s = NULL;
	if (str[0] == '0' && mod->st == 0 && mod->hps == 0)
		mod->o = 0;
	p->d = ft_strlen(str);
	p->s = str;
	if (mod->z == 1)
	{
		if (mod->m == 1 && mod->hp > p->d && mod->z == 1)
			mod->m = 1;
		else
			mod->m = 0;
		if (mod->hp > p->d && mod->st == 0 && mod->o == 0 && mod->m == 0)
			mod->t = mod->hp;
		if (mod->hp > p->d && mod->st == 0 && mod->o == 1 && mod->m == 0)
			mod->t = mod->hp - 1;
	}
	if (str[0] == '0' && mod->st == 1 && mod->t == 0)
	{
		free(p->s);
		p->d = 0;
		p->s = NULL;
	}
}

int			ft_po(char *str, t_format *mod)
{
	t_num	*p;
	int		o;

	o = 0;
	p = (t_num *)malloc(sizeof(t_num));
	ft_inc(p, str, mod);
	p->s = ft_stroka(p, mod);
	ft_putstr(p->s);
	if (p->s != NULL)
	{
		o = ft_strlen(p->s);
		free(p->s);
		p->s = NULL;
	}
	free(p);
	p = NULL;
	return (o);
}
