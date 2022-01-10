/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 14:09:06 by cmariot           #+#    #+#             */
/*   Updated: 2021/12/29 13:11:04 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* The memmove() function copies len bytes from string src to string dst.
 * The two strings may overlap;
 * the copy is always done in a non-destructive manner. */

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*dest;
	const char	*source;
	size_t		i;

	if (!dst && !src)
		return (NULL);
	dest = (char *)dst;
	source = (const char *)src;
	if (len == 0)
		return (dst);
	if (dst > src)
	{
		while (len-- > 0)
			dest[len] = source[len];
	}
	else
	{
		i = 0;
		while (i < len)
		{
			dest[i] = source[i];
			i++;
		}
	}
	return (dest);
}
