/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kadh <ael-kadh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/12 14:18:57 by ael-kadh          #+#    #+#             */
/*   Updated: 2015/01/12 14:18:57 by ael-kadh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static void		free_lst(void *content, size_t t)
{
	(void)t;
	if (content != NULL)
		free(content);
	t = 0;
}

t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list		*tmp;
	t_list		*new;
	t_list		*start;
	t_list		*tmp2;

	start = NULL;
	while (lst)
	{
		tmp = f(lst);
		if ((new = ft_lstnew(tmp->content, tmp->content_size)) == NULL)
		{
			ft_lstdel(&start, free_lst);
			return (NULL);
		}
		if (start == NULL)
			start = new;
		else
			tmp2->next = new;
		tmp2 = new;
		lst = lst->next;
	}
	return (start);
}
