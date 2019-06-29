/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flagidiux.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabshire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 16:54:52 by gabshire          #+#    #+#             */
/*   Updated: 2019/02/21 16:54:54 by gabshire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_flag_d_i(t_format *mod, va_list arg)
{
	if (mod->tp == 'D')
		return (ft_pd(ft_itoao(va_arg(arg, long long int)), mod));
	if (mod->sr[0] == 0)
		return (ft_pd(ft_itoao(va_arg(arg, int)), mod));
	if ((mod->sr[0] == 'l' && mod->sr[1] == 'l') || mod->sr[0] == 'j')
		return (ft_pd(ft_itoao(va_arg(arg, long long int)), mod));
	if (mod->sr[0] == 'l' && mod->sr[1] == 0)
		return (ft_pd(ft_itoao(va_arg(arg, long int)), mod));
	if (mod->sr[0] == 'h' && mod->sr[1] == 'h')
		return (ft_pd(ft_itoao((char)va_arg(arg, unsigned int)), mod));
	if (mod->sr[0] == 'h' && mod->sr[1] == 0)
		return (ft_pd(ft_itoao((short)va_arg(arg, int)), mod));
	return (0);
}

int	ft_flag_u(t_format *mod, va_list arg)
{
	if (mod->tp == 'U')
		return (ft_pd(ft_itoau(va_arg(arg, unsigned long int)), mod));
	if (mod->sr[0] == 0)
		return (ft_pd(ft_itoau(va_arg(arg, unsigned int)), mod));
	if ((mod->sr[0] == 'l' && mod->sr[1] == 'l') || mod->sr[0] == 'j')
		return (ft_pd(ft_itoau(va_arg(arg, unsigned long long int)), mod));
	if (mod->sr[0] == 'l' && mod->sr[1] == 0)
		return (ft_pd(ft_itoau(va_arg(arg, unsigned long int)), mod));
	if (mod->sr[0] == 'h' && mod->sr[1] == 'h')
		return (ft_pd(ft_itoao((unsigned char)va_arg(arg, int)), mod));
	if (mod->sr[0] == 'h' && mod->sr[1] == 0)
		return (ft_pd(ft_itoao((unsigned short)va_arg(arg, int)), mod));
	return (0);
}

int	ft_flag_x(t_format *mod, va_list arg)
{
	if (mod->sr[0] == 0)
		return (ft_px(ft_itoam(va_arg(arg, unsigned int), 0), mod, 0, 0));
	if ((mod->sr[0] == 'l' && mod->sr[1] == 'l') || mod->sr[0] == 'j')
		return (ft_px(ft_itoam(va_arg(arg, long long int), 0), mod, 0, 0));
	if (mod->sr[0] == 'l' && mod->sr[1] == 0)
		return (ft_px(ft_itoam(va_arg(arg, long int), 0), mod, 0, 0));
	if (mod->sr[0] == 'h' && mod->sr[1] == 0)
		return (ft_px(ft_itoam(va_arg(arg, unsigned int), 0), mod, 0, 1));
	if (mod->sr[0] == 'h' && mod->sr[1] == 'h')
		return (ft_px(ft_itoam(va_arg(arg, unsigned int), 0), mod, 0, 2));
	return (0);
}

int	ft_flag_xx(t_format *mod, va_list arg)
{
	if (mod->sr[0] == 0)
		return (ft_px(ft_itoam(va_arg(arg, unsigned int), 1), mod, 1, 0));
	if ((mod->sr[0] == 'l' && mod->sr[1] == 'l') || mod->sr[0] == 'j')
		return (ft_px(ft_itoam(va_arg(arg, long long int), 1), mod, 1, 0));
	if (mod->sr[0] == 'l' && mod->sr[1] == 0)
		return (ft_px(ft_itoam(va_arg(arg, long int), 1), mod, 1, 0));
	if (mod->sr[0] == 'h' && mod->sr[1] == 0)
		return (ft_px(ft_itoam(va_arg(arg, unsigned int), 1), mod, 1, 1));
	if (mod->sr[0] == 'h' && mod->sr[1] == 'h')
		return (ft_px(ft_itoam(va_arg(arg, unsigned int), 1), mod, 1, 2));
	return (0);
}
