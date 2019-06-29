/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   over.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabshire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 16:55:01 by gabshire          #+#    #+#             */
/*   Updated: 2019/02/21 16:55:03 by gabshire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_dobsym(char c, char *str)
{
	int		k;
	char	*ns;

	k = ft_strlen(str);
	ns = NULL;
	ns = ft_strnew(k + 2);
	ns[0] = c;
	ns[k] = '\0';
	k = 1;
	while (str[k - 1])
	{
		ns[k] = str[k - 1];
		k++;
	}
	if (str != NULL)
		free(str);
	return (ns);
}

char	*ft_subd(char *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*s1;
	unsigned int	j;

	i = 0;
	s1 = NULL;
	j = len + start;
	if (!s)
		return (NULL);
	if (start > j)
		return (NULL);
	if (!(s1 = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	while (start < j)
		s1[i++] = s[start++];
	s1[i] = '\0';
	free(s);
	return (s1);
}

char	*ft_sbor(char *str, t_format *mod, t_f *a)
{
	char *v;

	v = NULL;
	if (a->f == 1 || mod->pl == 1 || mod->pr == 1)
	{
		v = ft_strnew(2);
		if (a->f == 1)
			v[0] = '-';
		if (mod->pl == 1)
			v[0] = '+';
		if (mod->pr == 1 && a->sp == NULL)
			v[0] = ' ';
	}
	v = ft_strjoin_mod(v, a->z);
	v = ft_strjoin_mod(v, str);
	if (mod->m == 1)
		return (ft_strjoin_mod(v, a->sp));
	if (mod->m == 0)
		return (ft_strjoin_mod(a->sp, v));
	return (NULL);
}

char	*ft_o(char *okr, unsigned long long int c, int f)
{
	char *v;

	v = NULL;
	okr[0] = '0';
	c = c + 1;
	v = ft_itoau(c);
	if (f == 1)
		v = ft_dobsym('-', v);
	okr = ft_dobsym('.', okr);
	v = ft_strjoin_mod(v, okr);
	v = ft_subd(v, 0, ft_strlen(v) - 1);
	return (v);
}

void	ft_incfd(char **str, t_f *a, t_format *mod)
{
	int v;

	v = 0;
	a->sp = NULL;
	a->z = NULL;
	a->f = 0;
	if (str[0][0] == '-')
	{
		str[0] = ft_subd(str[0], 1, ft_strlen(str[0]));
		a->f = 1;
		mod->pl = 0;
	}
	if (a->f == 1 || mod->pl == 1)
		mod->pr = 0;
	v = ft_strlen(str[0]);
	if (a->f == 1 || mod->pl == 1 || (mod->pr == 1 && a->f == 0
	&& mod->pl == 0 && mod->z == 1 && mod->hp > v))
		v++;
	if (mod->m == 1)
		mod->z = 0;
	if (mod->z == 0 && mod->hp > v)
		a->sp = ft_genspase(mod->hp - v);
	if (mod->z == 1 && mod->hp > v)
		a->z = ft_genzero(mod->hp - v);
}
