/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kadh <ael-kadh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/12 14:19:00 by ael-kadh          #+#    #+#             */
/*   Updated: 2015/01/12 14:19:00 by ael-kadh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *s1, const char *s2, size_t n)
{
	unsigned int	i;

	i = 0;
	while (i < n)
	{
		if (s2[i] == '\0')
		{
			while (i < n)
				s1[i++] = '\0';
			return (s1);
		}
		s1[i] = s2[i];
		i++;
	}
	return (s1);
}
