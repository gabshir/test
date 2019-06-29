/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flagifo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabshire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 16:54:41 by gabshire          #+#    #+#             */
/*   Updated: 2019/02/21 16:54:43 by gabshire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_flag_o_o(t_format *mod, va_list arg)
{
	if (mod->tp == 'O')
		return (ft_po(ft_ie(va_arg(arg, unsigned long int)), mod));
	if (mod->sr[0] == 0)
		return (ft_po(ft_ie(va_arg(arg, unsigned int)), mod));
	if ((mod->sr[0] == 'l' && mod->sr[1] == 'l') || mod->sr[0] == 'j')
		return (ft_po(ft_ie(va_arg(arg, long long int)), mod));
	if ((mod->sr[0] == 'l' && mod->sr[1] == 0) || mod->tp == 'O')
		return (ft_po(ft_ie(va_arg(arg, long int)), mod));
	if (mod->sr[0] == 'h' && mod->sr[1] == 'h')
		return (ft_po(ft_ie((unsigned char)va_arg(arg, unsigned int)), mod));
	if (mod->sr[0] == 'h' && mod->sr[1] == 0)
		return (ft_po(ft_ie((unsigned short)va_arg(arg, unsigned int)), mod));
	return (0);
}

int		ft_flag_f(t_format *mod, va_list arg)
{
	if (mod->sr[0] == 'L')
		return (ft_printffl(ft_strfl(va_arg(arg, long double), mod), mod));
	if (mod->sr[0] == 0)
		return (ft_printff(ft_strf(va_arg(arg, double), mod), mod));
	return (0);
}

int		ft_flag_p(t_format *mod, va_list arg)
{
	return (ft_px(ft_itoam(va_arg(arg, unsigned long int), 0), mod, 0, 3));
	return (0);
}

void	ft_incp(t_format *mod)
{
	mod->hp = 0;
	mod->t = 0;
	mod->tp = 0;
	mod->hps = 0;
	mod->st = 0;
	mod->m = 0;
	mod->pl = 0;
	mod->pr = 0;
	mod->o = 0;
	mod->z = 0;
	mod->sr[0] = 0;
	mod->sr[1] = 0;
	mod->sr[2] = 0;
}
