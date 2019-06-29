/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabshire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 09:27:56 by gabshire          #+#    #+#             */
/*   Updated: 2019/02/21 09:28:00 by gabshire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_znak(char *str, t_format *mod, t_num *r)
{
	char *z;

	z = NULL;
	if (r->f == 1)
	{
		z = ft_strnew(2);
		z[0] = '-';
		return (ft_strjoin_mod(z, str));
	}
	if (mod->pl == 1 && mod->tp != 'u')
	{
		z = ft_strnew(2);
		z[0] = '+';
		return (ft_strjoin_mod(z, str));
	}
	return (str);
}

static char	*ft_genspaseo(t_num *p, t_format *mod)
{
	if (p->f == 0 && mod->pl == 0 && p->z == NULL && mod->hp > p->d)
		return (ft_genspase(mod->hp - p->d));
	if ((p->f == 1 || mod->pl == 1) && p->z == NULL && mod->hp > p->d + 1)
		return (ft_genspase(mod->hp - p->d - 1));
	if (p->f == 0 && mod->pl == 0 && mod->hp > p->d && mod->hp > mod->t)
	{
		if (p->d > mod->t)
			return (ft_genspase(mod->hp - p->d));
		else
			return (ft_genspase(mod->hp - mod->t));
	}
	if ((p->f == 1 || mod->pl == 1) && mod->hp > p->d + 1
	&& mod->hp > mod->t + 1)
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
	char *v;

	v = NULL;
	p->sp = NULL;
	p->z = NULL;
	if (mod->t > p->d)
		p->z = ft_genzero(mod->t - p->d);
	p->sp = ft_genspaseo(p, mod);
	if (mod->m == 1)
	{
		v = ft_strjoin_mod(p->z, p->s);
		v = ft_znak(v, mod, p);
		v = ft_strjoin_mod(v, p->sp);
		return (ft_dobsp(v, mod));
	}
	v = ft_strjoin_mod(p->z, p->s);
	v = ft_znak(v, mod, p);
	v = ft_strjoin_mod(p->sp, v);
	return (ft_dobsp(v, mod));
}

static void	ft_inc(t_num *p, char *str, t_format *mod)
{
	p->d = ft_strlen(p->s);
	if (mod->m == 1 && mod->pr == 1 && mod->hp > 0)
		mod->hp--;
	if (mod->z == 1)
	{
		if (mod->m == 1 && mod->hp > p->d)
			mod->m = 1;
		else
			mod->m = 0;
		if (mod->hp > p->d && mod->st == 0 && p->f == 0 && mod->pl == 0
			&& mod->pr == 0 && mod->m == 0)
			mod->t = mod->hp;
		if (mod->hp > p->d && mod->st == 0 && p->f == 0 && mod->pl == 0
			&& mod->pr == 1 && mod->hp > 0)
			mod->t = mod->hp - 1;
		if (mod->hp > p->d && mod->st == 0
			&& (p->f == 1 || mod->pl == 1) && mod->m == 0)
			mod->t = mod->hp - 1;
	}
	if (str[0] == '0' && mod->st == 1 && mod->t == 0)
	{
		free(p->s);
		p->d = 0;
		p->s = NULL;
	}
}

int			ft_pd(char *str, t_format *mod)
{
	t_num	*p;
	int		o;

	o = 0;
	p = (t_num *)malloc(sizeof(t_num));
	p->s = NULL;
	p->f = 0;
	if (str[0] == '-')
	{
		p->f = 1;
		mod->pr = 0;
		p->s = ft_strsub(str, 1, ft_strlen(str));
	}
	else
		p->s = str;
	ft_inc(p, str, mod);
	p->s = ft_stroka(p, mod);
	if (p->s != NULL)
	{
		ft_putstr(p->s);
		o = ft_strlen(p->s);
		free(p->s);
	}
	free(p);
	return (o);
}
