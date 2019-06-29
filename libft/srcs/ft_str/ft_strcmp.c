/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabshire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 13:06:20 by gabshire          #+#    #+#             */
/*   Updated: 2018/11/30 01:52:02 by gabshire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(const char *s1, const char *s2)
{
	int				i;
	unsigned char	*p1;
	unsigned char	*p2;

	i = 0;
	p1 = (unsigned char*)s1;
	p2 = (unsigned char*)s2;
	while (s1[i] - s2[i] == 0 && s1[i] && s2[i])
		i++;
	if (p1[i] > 127 || p2[i] > 127)
		return (p1[i] - p2[i]);
	return (s1[i] - s2[i]);
}
