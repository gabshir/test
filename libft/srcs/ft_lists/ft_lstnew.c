/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabshire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 14:58:35 by gabshire          #+#    #+#             */
/*   Updated: 2018/12/11 15:58:43 by gabshire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*str;

	if ((str = (t_list *)malloc(sizeof(t_list))) == NULL)
		return (NULL);
	if (content == NULL)
	{
		str->content = NULL;
		str->content_size = 0;
		str->next = NULL;
		return (str);
	}
	if ((str->content = malloc(content_size)) == NULL)
	{
		free(str);
		return (NULL);
	}
	str->content = ft_strdup(content);
	str->content_size = content_size;
	str->next = NULL;
	return (str);
}
