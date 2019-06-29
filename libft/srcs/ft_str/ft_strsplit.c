/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabshire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 19:31:12 by gabshire          #+#    #+#             */
/*   Updated: 2019/03/26 13:35:51 by gabshire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		kolslov(char const *s, char c)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (s[i] == c)
		i++;
	while (s[i])
	{
		while (s[i] && s[i] != c)
			i++;
		j++;
		while (s[i] && s[i] == c)
			i++;
	}
	return (j);
}

static	int		dlina(char const *s, char c, int a)
{
	int i;

	i = 0;
	while (s[a] && s[a] != c)
	{
		a++;
		i++;
	}
	return (i);
}

static char		**ochistka(char **str, int l)
{
	while (l >= 0)
	{
		free(str[l]);
		free(str);
		l--;
	}
	return (NULL);
}

static	char	**oksborka(char **str, char const *s, char c)
{
	int l;
	int i;
	int j;

	l = 0;
	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (!(str[l] = (char *)malloc(sizeof(char) * dlina(s, c, i) + 1)))
			ochistka(str, l);
		while (s[i] && s[i] != c)
			str[l][j++] = s[i++];
		str[l++][j] = '\0';
		j = 0;
		while (s[i] && s[i] == c)
			i++;
	}
	str[l] = NULL;
	return (str);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**str;
	int		l;

	l = 0;
	if ((!s) || (!(str = (char **)malloc(sizeof(char*) * (kolslov(s, c) + 1)))))
		return (NULL);
	if (kolslov(s, c) == 0)
	{
		str[l] = NULL;
		return (str);
	}
	str = oksborka(str, s, c);
	return (str);
}
