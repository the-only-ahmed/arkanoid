/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kadh <ael-kadh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/12 14:19:00 by ael-kadh          #+#    #+#             */
/*   Updated: 2015/04/01 15:47:15 by ael-kadh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (n == 0)
		return (0);
	while (n-- && *s1 && *s2)
	{
		if (*s1++ != *s2++)
			return ((unsigned char)*(s1 - 1) - (unsigned char)*(s2 - 1));
		if (n == 0)
			return (0);
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}
