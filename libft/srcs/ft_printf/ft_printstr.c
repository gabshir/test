/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabshire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 09:28:40 by gabshire          #+#    #+#             */
/*   Updated: 2019/02/21 09:28:43 by gabshire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_str(char *str, int k)
{
	int		i;
	char	*s;

	i = 0;
	if (!(s = (char *)malloc(sizeof(char) * k + 1)))
		return (NULL);
	while (i < k)
	{
		s[i] = str[i];
		i++;
	}
	s[i] = '\0';
	free(str);
	return (s);
}

static char	*ft_printstrm(char *str, t_format *mod, int k)
{
	char *temp;
	char *v;

	if (k > mod->t && mod->st == 1)
	{
		str = ft_str(str, mod->t);
		k = ft_strlen(str);
	}
	if (mod->hps == 0 || mod->hp <= k)
		return (str);
	else
	{
		temp = ft_genspase(mod->hp - k);
		v = ft_strjoin(str, temp);
	}
	free(str);
	free(temp);
	return (v);
}

static char	*ft_printstrn(char *str, t_format *mod, int k)
{
	char *temp;
	char *v;

	if (k > mod->t && mod->st == 1)
	{
		str = ft_str(str, mod->t);
		k = ft_strlen(str);
	}
	if (mod->hps == 0 || mod->hp <= k)
		return (str);
	else
	{
		if (mod->z == 1)
			temp = ft_genzero(mod->hp - k);
		else
			temp = ft_genspase(mod->hp - k);
		v = ft_strjoin(temp, str);
	}
	free(str);
	free(temp);
	return (v);
}

int			ft_printstr(va_list arg, t_format *mod)
{
	int		d;
	char	*str;
	int		k;
	char	*v;

	v = NULL;
	str = va_arg(arg, char*);
	if (str == NULL)
		v = ft_strdup("(null)");
	k = 0;
	d = 0;
	if (v == NULL)
		v = ft_strdup(str);
	k = ft_strlen(v);
	if (mod->m == 1)
		v = ft_printstrm(v, mod, k);
	else
		v = ft_printstrn(v, mod, k);
	d = ft_strlen(v);
	ft_putstr(v);
	free(v);
	return (d);
}
