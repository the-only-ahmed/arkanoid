/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kadh <ael-kadh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/12 14:18:59 by ael-kadh          #+#    #+#             */
/*   Updated: 2015/01/12 14:18:59 by ael-kadh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	c1;

	c1 = (char)c;
	while (*s)
	{
		if (*s == c1)
			return (char*)(s);
		s++;
	}
	if (*s == '\0' && c1 == '\0')
		return (char*)(s);
	else
		return (NULL);
}
