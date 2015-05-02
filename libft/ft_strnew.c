/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kadh <ael-kadh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/12 14:19:01 by ael-kadh          #+#    #+#             */
/*   Updated: 2015/01/12 14:19:01 by ael-kadh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*newstr;
	size_t	i;

	i = 0;
	newstr = (char *)malloc(sizeof(newstr) * size + 1);
	if (newstr == NULL)
		return (NULL);
	while (i <= size)
	{
		newstr[i] = '\0';
		i++;
	}
	newstr[size] = '\0';
	return (newstr);
}
