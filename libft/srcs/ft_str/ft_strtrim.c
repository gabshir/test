/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabshire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 16:54:59 by gabshire          #+#    #+#             */
/*   Updated: 2018/12/07 18:28:06 by gabshire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strtrim(char const *s)
{
	int		i;
	int		j;
	int		kol;
	char	*str;

	i = 0;
	kol = 0;
	if (!s)
		return (NULL);
	while ((s[i] == ' ' || s[i] == '\n' || s[i] == '\t') && s[i])
		i++;
	if (!s[i] && (str = ft_strnew(sizeof(char))))
		return (str);
	j = ft_strlen(s) - 1;
	while ((s[j] == ' ' || s[j] == '\n' || s[j] == '\t') && j > 0)
		j--;
	str = (char *)malloc(sizeof(char) * (j - i + 1));
	if (str == 0)
		return (NULL);
	while (i < j + 1)
		str[kol++] = s[i++];
	str[kol] = '\0';
	return (str);
}
