/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabshire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/23 03:47:46 by gabshire          #+#    #+#             */
/*   Updated: 2019/02/23 03:47:48 by gabshire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libft.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdarg.h>
# include <wchar.h>
# include <limits.h>
# include <stdlib.h>

typedef struct				s_format
{
	int		hp;
	int		t;
	size_t	hps;
	size_t	st;
	char	sr[3];
	char	tp;
	size_t	m;
	size_t	pl;
	size_t	pr;
	size_t	o;
	size_t	z;
}							t_format;

typedef struct				s_printnbrd
{
	int		k;
	char	*s;
	char	*z;
	char	*sp;
	int		d;
	int		f;
}							t_num;

typedef struct				s_itua
{
	size_t	f;
	int		k;
	char	*str;
}							t_itua;

typedef struct				s_float
{
	char	*sp;
	int		f;
	char	*z;
}							t_f;

typedef struct				s_fl
{
	unsigned long long int	c;
	char					*d;
	int						f;
	int						i;
}							t_ff;

void						ft_incp(t_format *mod);
char						*ft_dobsp(char *str, t_format *mod);
int							ft_flag_d_i(t_format *mod, va_list arg);
int							ft_flag_u(t_format *mod, va_list arg);
int							ft_flag_x(t_format *mod, va_list arg);
int							ft_flag_xx(t_format *mod, va_list arg);
int							ft_flag_o_o(t_format *mod, va_list arg);
int							ft_flag_f(t_format *mod, va_list arg);
int							ft_flag_p(t_format *mod, va_list arg);
int							ft_h(int i, t_format *m, const char *s, va_list a);
int							ft_t(int i, t_format *m, const char *s, va_list a);
int							ft_flag(int i, t_format *mod, const char *str);
int							ft_cheakp(const char *str, int i, int *d);
int							ft_specr(int i, t_format *mod, const char *str);
char						*ft_sbor(char *str, t_format *mod, t_f *a);
char						*ft_o(char *o, unsigned long long int c, int f);
void						ft_incfd(char **str, t_f *a, t_format *mod);
char						*ft_genspase(size_t i);
char						*ft_genzero(size_t i);
char						*ft_itoao(long long int i);
char						*ft_itoau(unsigned long long int i);
char						*ft_strjoin_mod(char *str1, char *str2);
char						*ft_itoam(unsigned long long int i, size_t f);
char						*ft_ie(unsigned long long int i);
char						*ft_strf (double k, t_format *mod);
char						*ft_dobsym(char c, char *str);
char						*ft_subd(char *s, unsigned int st, size_t l);
char						*ft_strfl(long double k, t_format *mod);
int							ft_printf(char const *s, ...);
int							ft_printchar(va_list arg, t_format *mod);
int							ft_printstr(va_list arg, t_format *mod);
int							ft_pd(char *str, t_format *mod);
int							ft_px(char *sr, t_format *mo, size_t f, size_t f1);
int							ft_po(char *str, t_format *mod);
int							ft_printff(char *str, t_format *mod);
int							ft_printffl(char *str, t_format *mod);
char						*ft_odf(double k);

#endif
