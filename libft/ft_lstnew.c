/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kadh <ael-kadh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/12 14:18:57 by ael-kadh          #+#    #+#             */
/*   Updated: 2015/01/12 14:18:57 by ael-kadh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list		*ret;

	if ((ret = (t_list *)malloc(sizeof(*ret))) == NULL)
		return (NULL);
	if (content == NULL)
	{
		ret->content = NULL;
		ret->content_size = 0;
	}
	else if ((ret->content = ft_memdup(content, content_size)) == NULL)
	{
		free(ret);
		return (NULL);
	}
	else
		ret->content_size = content_size;
	ret->next = NULL;
	return (ret);
}
