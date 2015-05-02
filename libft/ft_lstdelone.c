/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kadh <ael-kadh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/12 14:18:57 by ael-kadh          #+#    #+#             */
/*   Updated: 2015/01/12 14:18:57 by ael-kadh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	ft_lstdelone(t_list **alst, void (*del)(void *, size_t))
{
	t_list		*tmp;

	if (alst == NULL || *alst == NULL)
		return ;
	tmp = *alst;
	del(tmp->content, tmp->content_size);
	free(tmp);
	*alst = NULL;
}
