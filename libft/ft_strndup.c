/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kadh <ael-kadh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/12 14:19:01 by ael-kadh          #+#    #+#             */
/*   Updated: 2015/01/12 14:19:01 by ael-kadh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strndup(const char *s, size_t n)
{
	char		*s2;
	size_t		i;

	i = -1;
	if (s == NULL)
		return (NULL);
	if ((s2 = (char *)(malloc(sizeof(*s2) * (n + 1)))) == NULL)
		return (NULL);
	while (++i < n)
		s2[i] = s[i];
	s2[i] = '\0';
	return (s2);
}
