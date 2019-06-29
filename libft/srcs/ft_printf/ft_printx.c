/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabshire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 09:28:57 by gabshire          #+#    #+#             */
/*   Updated: 2019/02/21 09:29:00 by gabshire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_oktrop(char *str, t_format *mod, t_num *r)
{
	char	*z;

	if (r->f == 1 && mod->o == 1)
	{
		z = ft_strnew(3);
		z[0] = '0';
		z[1] = 'X';
		return (ft_strjoin_mod(z, str));
	}
	if (r->f == 0 && mod->o == 1)
	{
		z = ft_strnew(3);
		z[0] = '0';
		z[1] = 'x';
		return (ft_strjoin_mod(z, str));
	}
	return (str);
}

static char	*ft_strok(t_num *p, t_format *mod)
{
	char	*v;

	v = NULL;
	if (mod->m == 1)
	{
		v = ft_strjoin_mod(p->z, p->s);
		v = ft_oktrop(v, mod, p);
		v = ft_strjoin_mod(v, p->sp);
		return (v);
	}
	v = ft_strjoin_mod(p->z, p->s);
	v = ft_oktrop(v, mod, p);
	v = ft_strjoin_mod(p->sp, v);
	return (v);
}

static char	*ft_genspaseo(t_num *p, t_format *mod)
{
	if (mod->o == 0 && p->z == NULL && mod->hp > p->d)
		return (ft_genspase(mod->hp - p->d));
	if (mod->o == 1 && p->z == NULL && mod->hp > p->d + 2)
		return (ft_genspase(mod->hp - p->d - 2));
	if (mod->o == 0 && mod->hp > p->d && mod->hp > mod->t)
	{
		if (p->d > mod->t)
			return (ft_genspase(mod->hp - p->d));
		else
			return (ft_genspase(mod->hp - mod->t));
	}
	if (mod->o == 1 && mod->hp > p->d + 2 && mod->hp > mod->t + 2)
	{
		if (p->d > mod->t)
			return (ft_genspase(mod->hp - p->d - 2));
		else
			return (ft_genspase(mod->hp - mod->t - 2));
	}
	return (NULL);
}

static void	ft_format(t_num *p, char *str, t_format *mod, size_t f1)
{
	if (p->d > 4 && f1 == 1)
		p->s = ft_strsub(str, p->d - 4, p->d);
	if (p->d > 2 && f1 == 2)
		p->s = ft_strsub(str, p->d - 2, p->d);
	if (p->s == NULL)
		p->s = str;
	if (f1 == 3)
		mod->o = 1;
	if (mod->z == 1)
	{
		if (mod->m == 1 && mod->hp > p->d && mod->z == 1)
			mod->m = 1;
		else
			mod->m = 0;
		if (mod->hp > p->d && mod->st == 0 && mod->o == 0)
			mod->t = mod->hp;
		if (mod->hp > p->d && mod->st == 0 && mod->o == 1 && mod->m == 0)
			mod->t = mod->hp - 2;
	}
	if (str[0] == '0' && mod->st == 1 && mod->t == 0)
	{
		free(p->s);
		p->d = 0;
		p->s = NULL;
	}
}

int			ft_px(char *str, t_format *mod, size_t f, size_t f1)
{
	t_num	*p;
	int		o;

	o = 0;
	p = (t_num *)malloc(sizeof(t_num));
	p->sp = NULL;
	p->z = NULL;
	p->s = NULL;
	p->f = f;
	if (str[0] == '0')
		mod->o = 0;
	p->d = ft_strlen(str);
	ft_format(p, str, mod, f1);
	if (mod->t > p->d)
		p->z = ft_genzero(mod->t - p->d);
	p->sp = ft_genspaseo(p, mod);
	p->s = ft_strok(p, mod);
	ft_putstr(p->s);
	if (p->s != NULL)
	{
		o = ft_strlen(p->s);
		free(p->s);
	}
	free(p);
	return (o);
}
