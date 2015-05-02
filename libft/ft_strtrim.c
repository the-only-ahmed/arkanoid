/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kadh <ael-kadh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/12 14:19:01 by ael-kadh          #+#    #+#             */
/*   Updated: 2015/01/12 14:19:01 by ael-kadh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strtrim(char const *s)
{
	int		len;
	int		endchar;
	int		startchar;

	if (!s)
		return (NULL);
	endchar = 0;
	startchar = 0;
	len = ft_strlen(s);
	while (ft_iswhitespace(s[len - 1 - endchar]))
		endchar++;
	while (ft_iswhitespace(s[startchar]))
		startchar++;
	if ((len - startchar - endchar) <= 0)
		return (ft_strnew(0));
	return (ft_strsub(s, startchar, (size_t) (len - startchar - endchar)));
}
