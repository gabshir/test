/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabshire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 09:26:50 by gabshire          #+#    #+#             */
/*   Updated: 2019/02/21 09:26:53 by gabshire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*ft_nt(const char *s, unsigned long long int c, int f, double k)
{
	char *v;

	v = NULL;
	if ((c + 1) % 2 == 0)
	{
		if (k + s[0] - '0' >= 5)
			c++;
	}
	else
	{
		if (k + s[0] - '0' > 5)
			c++;
	}
	v = ft_itoau(c);
	if (f == 1)
		v = ft_dobsym('-', v);
	return (v);
}

static char		*ft_okrlogik(char *str, int t, int i, double k)
{
	while (str[t] && str[t - 1] && i == 1)
	{
		i = 0;
		if ((str[t - 1] + 1) % 2 == 0)
		{
			if (k + str[t] - '5' >= 0)
			{
				str[t] = '0';
				str[t - 1] = str[t - 1] + 1;
			}
		}
		else
		{
			if (k + str[t] - '5' > 0)
			{
				str[t] = '0';
				str[t - 1] = str[t - 1] + 1;
			}
		}
		if (str[t - 1] > 9 + '0')
			i = 1;
		t--;
	}
	return (ft_subd(str, 0, ft_strlen(str)));
}

static char		*ft_okr(char *str, unsigned long long int c, int f, double k)
{
	int		t;
	char	*v;
	char	*okr;

	t = ft_strlen(str) - 1;
	v = NULL;
	okr = NULL;
	if (t == 0)
		return (ft_nt(str, c, f, k));
	okr = ft_okrlogik(str, t, 1, k);
	if (okr[0] > 9 + '0')
		return (ft_o(okr, c, f));
	v = ft_itoau(c);
	if (f == 1)
		v = ft_dobsym('-', v);
	okr = ft_dobsym('.', okr);
	v = ft_strjoin_mod(v, okr);
	return (ft_subd(v, 0, ft_strlen(v) - 1));
}

char			*ft_strf(double k, t_format *mod)
{
	t_ff a;

	a.f = 0;
	a.i = 0;
	a.d = ft_odf(k);
	if (a.d != NULL)
		return (a.d);
	if (k < 0)
	{
		a.f = 1;
		k = -k;
	}
	a.c = (unsigned long long int)k;
	k = k - a.c;
	if (mod->st == 0)
		mod->t = 6;
	a.d = ft_strnew(mod->t + 2);
	while (a.i < mod->t + 1)
	{
		k = k * 10;
		a.d[a.i] = (char)k + '0';
		k = k - (char)k;
		a.i++;
	}
	return (ft_okr(a.d, a.c, a.f, k));
}

int				ft_printff(char *str, t_format *mod)
{
	t_f		a;
	char	*o;
	int		v;

	a.sp = NULL;
	a.f = 0;
	a.z = NULL;
	v = 0;
	o = NULL;
	if (str[0] == 'n' || (str[0] == '-' && str[1] == 'i'))
	{
		ft_putstr(str);
		free(str);
		return (3);
	}
	ft_incfd(&str, &a, mod);
	o = ft_sbor(str, mod, &a);
	ft_putstr(o);
	v = ft_strlen(o);
	free(o);
	return (v);
}
