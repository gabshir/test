/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pushswap.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabshire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 12:48:02 by gabshire          #+#    #+#             */
/*   Updated: 2019/03/26 17:35:55 by gabshire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSHSWAP_H
# define FT_PUSHSWAP_H

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdarg.h>
# include <wchar.h>
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft.h"

typedef struct			s_mass
{
	int		*arr1;
	int		*arr2;
	int		k1;
	int		k2;
	int		kol;
	int		f;
	char	**m;
	int		c;
}						t_m;

typedef struct			s_transform
{
	int		rotate;
	int		med;
	int		len;
	int		max;
	int		t;
	int		f;
}						t_o;

typedef struct			s_sbora
{
	int		max;
	int		med;
	int		r;
	int		o;
	int		s;
}						t_sb;

typedef struct			s_napolnenye
{
	int		i;
	int		f;
	int		j;
}						t_nap;

typedef struct			s_comand
{
	int i;
	int k;
	int k1;
}						t_com;

void					ft_rra(t_m *l);
void					ft_rrb(t_m *l);
void					ft_rrr(t_m *l);
void					ft_sa(t_m *l);
void					ft_sb(t_m *l);
void					ft_ss(t_m *l);
void					ft_pa(t_m *l);
void					ft_pb(t_m *l);
void					ft_ra(t_m *l);
void					ft_rb(t_m *l);
void					ft_rr(t_m *l);
void					ft_sortirovka(t_m *l);
int						ft_ocenka(const int *arr, int k);
int						*ft_copyarr(const int *arr, int k);
int						*ft_sort(const int *arr, int k);
int						ft_max(const int *arr, int i);
int						counter(const int *arr, int i, int med);
int						ft_len(const int *arr, int len, int max);
int						ft_sizeblok(t_m *l, int len);
int						ft_mediana(int *arr, int len);
void					minias(t_m *l, int len, int max);
void					minia(t_m *l, int len);
void					minib(t_m *l, int len);
void					ft_starta(t_m *l, int *len, t_sb *k);
void					ft_optima(t_m *l, t_sb *k, int f, int len);
void					lasta(t_m *l, t_sb *k, int len);
void					ft_sbora(t_m *l, int len);
void					ft_start(t_m *l, t_o *tr);
void					ft_rotate(t_m *l, t_o *tr);
void					ft_perenos(t_m *l, t_o *tr);
void					ft_inclogik(t_m *l, t_o *tr);
void					ft_optim(t_m *l, t_o *tr);
void					ft_cycleb(t_m *l, t_o *tr);
void					ft_transform(t_m *l);
void					print_stack(t_m *l);
char					**ft_strsplit(char const *s, char c);
char					*ft_strdup(const char *s1);
void					ft_error(t_m *l);
void					ft_proverka(const char *str, t_m *l);
int						ft_miniatoi(const char *str, int *z);
void					ft_dubly(t_m *l, int f);
char					**copyarr(const int *a, char **b);
void					transformb(t_m *l, t_nap *k, int *a, char **b);
void					ft_napolnenie(t_m *l, int a, char **b);

#endif
