/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabshire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 09:30:13 by gabshire          #+#    #+#             */
/*   Updated: 2019/02/21 09:30:16 by gabshire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_definitionflag(t_format *mod, va_list arg)
{
	if (mod->tp == 'c')
		return (ft_printchar(arg, mod));
	if (mod->tp == 's')
		return (ft_printstr(arg, mod));
	if (mod->tp == 'd' || mod->tp == 'i' || mod->tp == 'D')
		return (ft_flag_d_i(mod, arg));
	if (mod->tp == 'u' || mod->tp == 'U')
		return (ft_flag_u(mod, arg));
	if (mod->tp == 'x')
		return (ft_flag_x(mod, arg));
	if (mod->tp == 'X')
		return (ft_flag_xx(mod, arg));
	if (mod->tp == 'o' || mod->tp == 'O')
		return (ft_flag_o_o(mod, arg));
	if (mod->tp == 'p')
		return (ft_flag_p(mod, arg));
	if (mod->tp == 'f' || mod->tp == 'F')
		return (ft_flag_f(mod, arg));
	return (-1);
}

static int		ft_nap(int i, const char *str, va_list arg, t_format *mod)
{
	ft_incp(mod);
	i = ft_flag(i, mod, str);
	i = ft_h(i, mod, str, arg);
	i = ft_h(i, mod, str, arg);
	i = ft_t(i, mod, str, arg);
	i = ft_t(i, mod, str, arg);
	i = ft_flag(i, mod, str);
	i = ft_specr(i, mod, str);
	i = ft_flag(i, mod, str);
	mod->tp = str[i];
	return (i);
}

static void		ft_ubb(int i, t_format *mod, int *d, const char *str)
{
	while (mod->hp > 1)
	{
		if (mod->m == 1)
			ft_putchar(' ');
		else
			ft_putchar('0');
		mod->hp--;
		d[0]++;
	}
	ft_putchar(str[i]);
	d[0] = d[0] + 1;
	free(mod);
	mod = NULL;
}

static int		ft_format(int i, const char *str, va_list arg, int *d)
{
	t_format	*mod;
	int			k;

	i++;
	k = 0;
	if (!(mod = (t_format *)(malloc(sizeof(t_format)))))
		return (0);
	i = ft_nap(i, str, arg, mod);
	if (mod->tp != 0)
		k = ft_definitionflag(mod, arg);
	if (k >= 0)
	{
		d[0] = d[0] + k;
		free(mod);
		return (i + 1);
	}
	ft_ubb(i, mod, d, str);
	return (i + 1);
}

int				ft_printf(char const *s, ...)
{
	int			i;
	va_list		arg;
	int			d;
	int			len;

	d = 0;
	i = 0;
	va_start(arg, s);
	len = ft_strlen(s);
	while (i < len)
	{
		i = ft_cheakp(s, i, &d);
		if (s[i] != '%' && i < len)
		{
			ft_putchar(s[i]);
			d++;
			i++;
		}
		i = ft_cheakp(s, i, &d);
		if (s[i] == '%' && i < len)
			i = ft_format(i, s, arg, &d);
	}
	va_end(arg);
	return (d);
}
