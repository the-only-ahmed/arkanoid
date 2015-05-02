/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kadh <ael-kadh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/12 14:19:00 by ael-kadh          #+#    #+#             */
/*   Updated: 2015/01/12 14:19:00 by ael-kadh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	char		*dest_2;
	const char	*src_2;
	size_t		n;
	size_t		len;

	dest_2 = dst;
	src_2 = src;
	n = size;
	while (n-- && *dest_2 != '\0')
		dest_2++;
	len = dest_2 - dst;
	n = size - len;
	if (n == 0)
		return (len + ft_strlen(src));
	while (n-- > 1 && *src_2 != '\0')
		*dest_2++ = *src_2++;
	*dest_2 = '\0';
	return (len + ft_strlen(src));
}
