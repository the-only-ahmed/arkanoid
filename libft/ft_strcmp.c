/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kadh <ael-kadh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/12 14:18:59 by ael-kadh          #+#    #+#             */
/*   Updated: 2015/04/01 15:45:33 by ael-kadh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	int		i;

	i = 0;
	if (s1[0] != '\0' || s2[0] != '\0')
	{
		while (s1[i] == s2[i])
		{
			if (s1[i] == '\0' && s2[i] == '\0')
				return (0);
			i++;
		}
		if (s1[i] != s2[i])
			return (int)((unsigned char)s1[i] - (unsigned char)s2[i]);
	}
	return (0);
}
