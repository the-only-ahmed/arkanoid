/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kadh <ael-kadh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/12 14:19:01 by ael-kadh          #+#    #+#             */
/*   Updated: 2015/01/12 14:19:01 by ael-kadh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	c1;
	int		i;
	int		t;

	i = 0;
	t = 0;
	c1 = (char)c;
	while (s[i] != '\0')
	{
		if (s[i] == c1)
			t = i;
		i++;
	}
	if (c == 0)
		return (char*)(&s[i]);
	if ((t == 0 && s[t] == c1) || t > 0)
		return (char*)(&s[t]);
	else
		return (NULL);
}
